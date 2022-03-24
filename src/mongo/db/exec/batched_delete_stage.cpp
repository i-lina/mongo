/**
 *    Copyright (C) 2022-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#define MONGO_LOGV2_DEFAULT_COMPONENT ::mongo::logv2::LogComponent::kWrite

#include "mongo/platform/basic.h"

#include "mongo/db/exec/batched_delete_stage.h"

#include "mongo/db/catalog/collection.h"
#include "mongo/db/commands/server_status.h"
#include "mongo/db/concurrency/write_conflict_exception.h"
#include "mongo/db/curop.h"
#include "mongo/db/exec/scoped_timer.h"
#include "mongo/db/exec/working_set_common.h"
#include "mongo/db/exec/write_stage_common.h"
#include "mongo/db/op_observer.h"
#include "mongo/db/query/canonical_query.h"
#include "mongo/db/repl/replication_coordinator.h"
#include "mongo/db/s/collection_sharding_state.h"
#include "mongo/db/service_context.h"
#include "mongo/logv2/log.h"
#include "mongo/s/pm2423_feature_flags_gen.h"
#include "mongo/util/scopeguard.h"

namespace mongo {

MONGO_FAIL_POINT_DEFINE(throwWriteConflictExceptionInBatchedDeleteStage);

namespace {
void incrementSSSMetricNoOverflow(AtomicWord<long long>& metric, long long value) {
    const int64_t MAX = 1ULL << 60;

    if (metric.loadRelaxed() > MAX) {
        metric.store(value);
    } else {
        metric.fetchAndAdd(value);
    }
}

// Returns true to if the Record exists and its data still matches the query. Returns false
// otherwise.
bool ensureStillMatches(OperationContext* opCtx,
                        const CollectionPtr& collection,
                        RecordId rid,
                        SnapshotId snapshotId,
                        const CanonicalQuery* cq) {

    if (opCtx->recoveryUnit()->getSnapshotId() != snapshotId) {
        Snapshotted<BSONObj> docData;
        bool docExists = collection->findDoc(opCtx, rid, &docData);
        if (!docExists) {
            return false;
        }

        // Make sure the re-fetched doc still matches the predicate.
        if (cq && !cq->root()->matchesBSON(docData.value(), nullptr)) {
            // No longer matches.
            return false;
        }
    }
    return true;
}

}  // namespace

/**
 * Reports globally-aggregated batch stats.
 */
struct BatchedDeletesSSS : ServerStatusSection {
    BatchedDeletesSSS()
        : ServerStatusSection("batchedDeletes"), batches(0), docs(0), sizeBytes(0), timeMillis(0) {}

    bool includeByDefault() const override {
        return true;
    }

    BSONObj generateSection(OperationContext* opCtx, const BSONElement& configElem) const override {
        BSONObjBuilder bob;
        bob.appendNumber("batches", batches.loadRelaxed());
        bob.appendNumber("docs", docs.loadRelaxed());
        bob.appendNumber("sizeBytes", sizeBytes.loadRelaxed());
        bob.append("timeMillis", timeMillis.loadRelaxed());

        return bob.obj();
    }

    AtomicWord<long long> batches;
    AtomicWord<long long> docs;
    AtomicWord<long long> sizeBytes;
    AtomicWord<long long> timeMillis;
} batchedDeletesSSS;


BatchedDeleteStage::BatchedDeleteStage(ExpressionContext* expCtx,
                                       std::unique_ptr<DeleteStageParams> params,
                                       std::unique_ptr<BatchedDeleteStageBatchParams> batchParams,
                                       WorkingSet* ws,
                                       const CollectionPtr& collection,
                                       PlanStage* child)
    : DeleteStage::DeleteStage(
          kStageType.rawData(), expCtx, std::move(params), ws, collection, child),
      _batchParams(std::move(batchParams)) {
    tassert(6303800,
            "batched deletions only support multi-document deletions (multi: true)",
            _params->isMulti);
    tassert(6303801,
            "batched deletions do not support the 'fromMigrate' parameter",
            !_params->fromMigrate);
    tassert(6303802,
            "batched deletions do not support the 'returnDelete' parameter",
            !_params->returnDeleted);
    tassert(
        6303803, "batched deletions do not support the 'sort' parameter", _params->sort.isEmpty());
    tassert(6303804,
            "batched deletions do not support the 'removeSaver' parameter",
            _params->sort.isEmpty());
    tassert(6303805,
            "batched deletions do not support the 'numStatsForDoc' parameter",
            !_params->numStatsForDoc);
    tassert(6303806,
            "batch size cannot be unbounded; you must specify at least one of the following batch "
            "parameters: "
            "'targetBatchBytes', 'targetBatchDocs', 'targetBatchTimeMS'",
            _batchParams->targetBatchBytes || _batchParams->targetBatchDocs ||
                _batchParams->targetBatchTimeMS != Milliseconds(0));
    tassert(6303807,
            "batch size parameters must be greater than or equal to zero",
            _batchParams->targetBatchBytes >= 0 && _batchParams->targetBatchDocs >= 0 &&
                _batchParams->targetBatchTimeMS >= Milliseconds(0));
}

BatchedDeleteStage::~BatchedDeleteStage() {}

PlanStage::StageState BatchedDeleteStage::_deleteBatch(WorkingSetID* out) {
    try {
        child()->saveState();
    } catch (const WriteConflictException&) {
        std::terminate();
    }

    const auto startOfBatchTimestampMillis = Date_t::now().toMillisSinceEpoch();
    unsigned int docsDeleted = 0;
    std::vector<RecordId> recordsThatNoLongerMatch;
    try {
        // Start a WUOW with 'groupOplogEntries' which groups a delete batch into a single timestamp
        // and oplog entry
        WriteUnitOfWork wuow(opCtx(), true /* groupOplogEntries */);

        for (auto& [rid, snapshotId] : _ridMap) {
            if (MONGO_unlikely(throwWriteConflictExceptionInBatchedDeleteStage.shouldFail())) {
                throw WriteConflictException();
            }

            // The PlanExecutor YieldPolicy may change snapshots between calls to 'doWork()'.
            // Different documents may have different snapshots.
            bool docStillMatches =
                ensureStillMatches(opCtx(), collection(), rid, snapshotId, _params->canonicalQuery);
            if (docStillMatches) {
                collection()->deleteDocument(opCtx(),
                                             _params->stmtId,
                                             rid,
                                             _params->opDebug,
                                             _params->fromMigrate,
                                             false,
                                             _params->returnDeleted
                                                 ? Collection::StoreDeletedDoc::On
                                                 : Collection::StoreDeletedDoc::Off);

                docsDeleted++;
            } else {
                recordsThatNoLongerMatch.emplace_back(rid);
            }
        }
        wuow.commit();
    } catch (const WriteConflictException&) {
        for (auto rid : recordsThatNoLongerMatch) {
            // Lazily delete records that no longer match from the buffer. They should be skipped
            // when the deletes are retryed.
            _ridMap.erase(rid);
        }

        _drainRemainingBuffer = true;
        *out = WorkingSet::INVALID_ID;
        return NEED_YIELD;
    }

    const auto endOfBatchTimestampMillis = Date_t::now().toMillisSinceEpoch();
    incrementSSSMetricNoOverflow(batchedDeletesSSS.docs, docsDeleted);
    incrementSSSMetricNoOverflow(batchedDeletesSSS.batches, 1);
    incrementSSSMetricNoOverflow(batchedDeletesSSS.timeMillis,
                                 endOfBatchTimestampMillis - startOfBatchTimestampMillis);
    // TODO (SERVER-63039): report batch size
    _specificStats.docsDeleted += docsDeleted;
    _ridMap.clear();
    _drainRemainingBuffer = false;

    try {
        child()->restoreState(&collection());
    } catch (const WriteConflictException&) {
        // Note we don't need to retry anything in this case since the delete already was committed.
        *out = WorkingSet::INVALID_ID;
        return NEED_YIELD;
    }

    return NEED_TIME;
}

PlanStage::StageState BatchedDeleteStage::doWork(WorkingSetID* out) {
    if (!_drainRemainingBuffer) {
        WorkingSetID id;
        auto status = child()->work(&id);

        switch (status) {
            case PlanStage::ADVANCED:
                break;

            case PlanStage::NEED_TIME:
                return status;

            case PlanStage::NEED_YIELD:
                *out = id;
                return status;

            case PlanStage::IS_EOF:
                if (!_ridMap.empty()) {
                    // Drain the outstanding deletions.
                    auto ret = _deleteBatch(out);
                    if (ret != NEED_TIME) {
                        return ret;
                    }
                }
                return status;

            default:
                MONGO_UNREACHABLE;
        }

        WorkingSetMember* member = _ws->get(id);

        // Free the WSM at the end of this scope. Retries will re-fetch by the RecordId and will not
        // need to keep the WSM around
        ScopeGuard memberFreer([&] { _ws->free(id); });

        invariant(member->hasRecordId());
        RecordId recordId = member->recordId;

        // Deletes can't have projections. This means that covering analysis will always add
        // a fetch. We should always get fetched data, and never just key data.
        invariant(member->hasObj());

        if (!_params->isExplain) {
            _ridMap.insert(std::make_pair(recordId, member->doc.snapshotId()));
        }
    }

    if (!_params->isExplain &&
        (_drainRemainingBuffer ||
         (_batchParams->targetBatchDocs &&
          _ridMap.size() >= static_cast<unsigned long long>(_batchParams->targetBatchDocs)))) {
        return _deleteBatch(out);
    }

    return PlanStage::NEED_TIME;
}

}  // namespace mongo
