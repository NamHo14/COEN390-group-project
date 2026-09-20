# Rep Detection

Each exercise has its own detector.

The detector receives IMU samples and maintains a small state machine.

## Example: Bicep Curl

Possible states:

```text
BOTTOM
MOVING_UP
TOP
MOVING_DOWN
```

A valid repetition is:

```text
BOTTOM
   |
   v
MOVING_UP
   |
   v
TOP
   |
   v
MOVING_DOWN
   |
   v
BOTTOM
```

Only after completing the entire sequence should the rep counter increase.

## Why State Machines?

They are:

- Easy to understand
- Easy to debug
- Lightweight enough for an ESP32
- Suitable for exercise-specific rules
- Independent from machine learning

## Thresholds

Thresholds should be determined experimentally.

Examples may include:

- Angular velocity
- Acceleration magnitude
- Direction change
- Minimum movement duration
- Minimum range of motion
- Debounce time

Do not finalize these values until actual IMU recordings are available.
