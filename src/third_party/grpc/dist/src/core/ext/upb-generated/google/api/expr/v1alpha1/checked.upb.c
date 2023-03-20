/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     google/api/expr/v1alpha1/checked.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "google/api/expr/v1alpha1/checked.upb.h"
#include "google/api/expr/v1alpha1/syntax.upb.h"
#include "google/protobuf/empty.upb.h"
#include "google/protobuf/struct.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub google_api_expr_v1alpha1_CheckedExpr_submsgs[4] = {
  {.submsg = &google_api_expr_v1alpha1_CheckedExpr_ReferenceMapEntry_msginit},
  {.submsg = &google_api_expr_v1alpha1_CheckedExpr_TypeMapEntry_msginit},
  {.submsg = &google_api_expr_v1alpha1_Expr_msginit},
  {.submsg = &google_api_expr_v1alpha1_SourceInfo_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_CheckedExpr__fields[4] = {
  {2, UPB_SIZE(4, 8), UPB_SIZE(0, 0), 0, 11, kUpb_FieldMode_Map | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {3, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 1, 11, kUpb_FieldMode_Map | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {4, UPB_SIZE(12, 24), UPB_SIZE(1, 1), 2, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {5, UPB_SIZE(16, 32), UPB_SIZE(2, 2), 3, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_CheckedExpr_msginit = {
  &google_api_expr_v1alpha1_CheckedExpr_submsgs[0],
  &google_api_expr_v1alpha1_CheckedExpr__fields[0],
  UPB_SIZE(20, 40), 4, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_CheckedExpr_ReferenceMapEntry_submsgs[1] = {
  {.submsg = &google_api_expr_v1alpha1_Reference_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_CheckedExpr_ReferenceMapEntry__fields[2] = {
  {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 3, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_CheckedExpr_ReferenceMapEntry_msginit = {
  &google_api_expr_v1alpha1_CheckedExpr_ReferenceMapEntry_submsgs[0],
  &google_api_expr_v1alpha1_CheckedExpr_ReferenceMapEntry__fields[0],
  UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_CheckedExpr_TypeMapEntry_submsgs[1] = {
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_CheckedExpr_TypeMapEntry__fields[2] = {
  {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 3, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_CheckedExpr_TypeMapEntry_msginit = {
  &google_api_expr_v1alpha1_CheckedExpr_TypeMapEntry_submsgs[0],
  &google_api_expr_v1alpha1_CheckedExpr_TypeMapEntry__fields[0],
  UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Type_submsgs[7] = {
  {.submsg = &google_protobuf_Empty_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_ListType_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_MapType_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_FunctionType_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
  {.submsg = &google_protobuf_Empty_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_AbstractType_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Type__fields[13] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 5, kUpb_FieldMode_Scalar | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
  {3, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 5, kUpb_FieldMode_Scalar | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
  {4, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 5, kUpb_FieldMode_Scalar | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
  {5, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 5, kUpb_FieldMode_Scalar | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
  {6, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 1, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {7, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 2, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {8, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 3, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {9, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {10, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {11, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 4, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {12, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 5, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {14, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 6, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Type_msginit = {
  &google_api_expr_v1alpha1_Type_submsgs[0],
  &google_api_expr_v1alpha1_Type__fields[0],
  UPB_SIZE(12, 24), 13, kUpb_ExtMode_NonExtendable, 12, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Type_ListType_submsgs[1] = {
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Type_ListType__fields[1] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Type_ListType_msginit = {
  &google_api_expr_v1alpha1_Type_ListType_submsgs[0],
  &google_api_expr_v1alpha1_Type_ListType__fields[0],
  UPB_SIZE(8, 24), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Type_MapType_submsgs[2] = {
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Type_MapType__fields[2] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), UPB_SIZE(2, 2), 1, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Type_MapType_msginit = {
  &google_api_expr_v1alpha1_Type_MapType_submsgs[0],
  &google_api_expr_v1alpha1_Type_MapType__fields[0],
  UPB_SIZE(12, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Type_FunctionType_submsgs[2] = {
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Type_FunctionType__fields[2] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 1, 11, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Type_FunctionType_msginit = {
  &google_api_expr_v1alpha1_Type_FunctionType_submsgs[0],
  &google_api_expr_v1alpha1_Type_FunctionType__fields[0],
  UPB_SIZE(12, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Type_AbstractType_submsgs[1] = {
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Type_AbstractType__fields[2] = {
  {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 0, 11, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Type_AbstractType_msginit = {
  &google_api_expr_v1alpha1_Type_AbstractType_submsgs[0],
  &google_api_expr_v1alpha1_Type_AbstractType__fields[0],
  UPB_SIZE(12, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Decl_submsgs[2] = {
  {.submsg = &google_api_expr_v1alpha1_Decl_IdentDecl_msginit},
  {.submsg = &google_api_expr_v1alpha1_Decl_FunctionDecl_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Decl__fields[3] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(12, 24), UPB_SIZE(-1, -1), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {3, UPB_SIZE(12, 24), UPB_SIZE(-1, -1), 1, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Decl_msginit = {
  &google_api_expr_v1alpha1_Decl_submsgs[0],
  &google_api_expr_v1alpha1_Decl__fields[0],
  UPB_SIZE(16, 40), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Decl_IdentDecl_submsgs[2] = {
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
  {.submsg = &google_api_expr_v1alpha1_Constant_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Decl_IdentDecl__fields[3] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), UPB_SIZE(2, 2), 1, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {3, UPB_SIZE(12, 24), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Decl_IdentDecl_msginit = {
  &google_api_expr_v1alpha1_Decl_IdentDecl_submsgs[0],
  &google_api_expr_v1alpha1_Decl_IdentDecl__fields[0],
  UPB_SIZE(20, 40), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Decl_FunctionDecl_submsgs[1] = {
  {.submsg = &google_api_expr_v1alpha1_Decl_FunctionDecl_Overload_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Decl_FunctionDecl__fields[1] = {
  {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Decl_FunctionDecl_msginit = {
  &google_api_expr_v1alpha1_Decl_FunctionDecl_submsgs[0],
  &google_api_expr_v1alpha1_Decl_FunctionDecl__fields[0],
  UPB_SIZE(4, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Decl_FunctionDecl_Overload_submsgs[2] = {
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
  {.submsg = &google_api_expr_v1alpha1_Type_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Decl_FunctionDecl_Overload__fields[6] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(12, 24), UPB_SIZE(0, 0), 0, 11, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {3, UPB_SIZE(16, 32), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {4, UPB_SIZE(20, 40), UPB_SIZE(1, 1), 1, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {5, UPB_SIZE(1, 1), UPB_SIZE(0, 0), kUpb_NoSub, 8, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
  {6, UPB_SIZE(24, 48), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Decl_FunctionDecl_Overload_msginit = {
  &google_api_expr_v1alpha1_Decl_FunctionDecl_Overload_submsgs[0],
  &google_api_expr_v1alpha1_Decl_FunctionDecl_Overload__fields[0],
  UPB_SIZE(32, 72), 6, kUpb_ExtMode_NonExtendable, 6, 255, 0,
};

static const upb_MiniTable_Sub google_api_expr_v1alpha1_Reference_submsgs[1] = {
  {.submsg = &google_api_expr_v1alpha1_Constant_msginit},
};

static const upb_MiniTable_Field google_api_expr_v1alpha1_Reference__fields[3] = {
  {1, UPB_SIZE(4, 8), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {3, UPB_SIZE(12, 24), UPB_SIZE(0, 0), kUpb_NoSub, 9, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
  {4, UPB_SIZE(16, 32), UPB_SIZE(1, 1), 0, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_api_expr_v1alpha1_Reference_msginit = {
  &google_api_expr_v1alpha1_Reference_submsgs[0],
  &google_api_expr_v1alpha1_Reference__fields[0],
  UPB_SIZE(20, 40), 3, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable *messages_layout[13] = {
  &google_api_expr_v1alpha1_CheckedExpr_msginit,
  &google_api_expr_v1alpha1_CheckedExpr_ReferenceMapEntry_msginit,
  &google_api_expr_v1alpha1_CheckedExpr_TypeMapEntry_msginit,
  &google_api_expr_v1alpha1_Type_msginit,
  &google_api_expr_v1alpha1_Type_ListType_msginit,
  &google_api_expr_v1alpha1_Type_MapType_msginit,
  &google_api_expr_v1alpha1_Type_FunctionType_msginit,
  &google_api_expr_v1alpha1_Type_AbstractType_msginit,
  &google_api_expr_v1alpha1_Decl_msginit,
  &google_api_expr_v1alpha1_Decl_IdentDecl_msginit,
  &google_api_expr_v1alpha1_Decl_FunctionDecl_msginit,
  &google_api_expr_v1alpha1_Decl_FunctionDecl_Overload_msginit,
  &google_api_expr_v1alpha1_Reference_msginit,
};

const upb_MiniTable_File google_api_expr_v1alpha1_checked_proto_upb_file_layout = {
  messages_layout,
  NULL,
  NULL,
  13,
  0,
  0,
};

#include "upb/port_undef.inc"
