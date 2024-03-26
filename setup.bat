python -m venv venv --prompt mongo
venv/scripts/activate.bat
python -m pip install poetry==1.5.1
python -m poetry install --no-root --sync
set PYTHON_KEYRING_BACKEND=keyring.backends.null.Keyring
python -m poetry install --no-root --sync
