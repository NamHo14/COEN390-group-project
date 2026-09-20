# Rep Detection Strategy

## Core rule
Exercise selection is manual. The app sends the selected exercise, and firmware runs only that exercise detector.

No machine learning and no automatic exercise classification are used.

## Detector interface
Each exercise detector implements a common `RepDetector` interface:
- `reset()`
- `update(IMUSample)` -> returns `true` when one full rep is completed

## Bicep curl state-machine example
```text
BOTTOM -> MOVING_UP -> TOP -> MOVING_DOWN -> BOTTOM
```
When the detector returns to `BOTTOM` after completing the cycle, one rep is counted.

## Other exercises
Bench press, squat, shoulder press, and row detectors use the same interface and currently contain placeholders for exercise-specific logic.

## Tempo/set derivation (future)
- Rep duration from timestamps between rep boundaries.
- Average tempo from rolling average of rep durations.
- Set counting from user workflow and rest windows.

## Calibration warning
Thresholds and transition conditions must be determined experimentally with real IMU data. Placeholder thresholds in starter code are intentionally non-production.
