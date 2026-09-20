# BLE Protocol (v0)

## Goals
Simple, versionable text protocol between mobile app and ESP32.

## Framing and encoding
- UTF-8 text messages
- One command/telemetry message per line
- Message delimiter: `\n`
- Format: `KEY:VALUE` (or single keyword command)

## Direction
### App -> ESP32 commands
- `SELECT_EXERCISE:BICEP_CURL`
- `SELECT_EXERCISE:BENCH_PRESS`
- `SELECT_EXERCISE:SQUAT`
- `SELECT_EXERCISE:SHOULDER_PRESS`
- `SELECT_EXERCISE:ROW`
- `START_WORKOUT`
- `STOP_WORKOUT`
- `RESET_REPS`

### ESP32 -> App telemetry
- `REP:1`
- `REP:2`
- `SET:1`
- `TEMPO:2.4`
- `REST_TIME:45`
- `BATTERY:82`

## Error handling
- Unknown command: `ERR:UNKNOWN_COMMAND`
- Invalid value format: `ERR:INVALID_VALUE`
- Missing exercise selection before start: `ERR:EXERCISE_NOT_SELECTED`

## Compatibility notes
- Reserve optional version handshake for future (`PROTO:1`).
- Add new keys without breaking old clients (ignore unknown keys).
- Keep command semantics stable across minor protocol revisions.
