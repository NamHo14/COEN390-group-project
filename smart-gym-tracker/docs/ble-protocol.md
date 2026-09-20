# BLE Protocol

This document defines the initial human-readable BLE message format.

## App -> ESP32

```text
SELECT_EXERCISE:BICEP_CURL
SELECT_EXERCISE:BENCH_PRESS
SELECT_EXERCISE:SQUAT
SELECT_EXERCISE:SHOULDER_PRESS
SELECT_EXERCISE:ROW
START_WORKOUT
STOP_WORKOUT
RESET_REPS
```

## ESP32 -> App

```text
REP:1
REP:2
SET:1
TEMPO:2.4
REST_TIME:45
BATTERY:82
```

## Notes

This protocol is intentionally simple for early development.

Later versions may use:

- Separate BLE characteristics
- Binary packets
- Checksums
- Versioning
- Timestamps
