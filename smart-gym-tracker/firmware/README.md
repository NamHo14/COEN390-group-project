# Firmware

Embedded C++ firmware for the ESP32.

## Responsibilities

- Initialize and read the IMU
- Calibrate and filter motion data
- Receive exercise selection over BLE
- Select the correct rep detector
- Count repetitions
- Track sets, tempo, and rest time
- Send workout data back to the mobile app

## Planned Modules

- `IMUManager`
- `BLEManager`
- `ExerciseManager`
- `RepDetector`
- `BicepCurlDetector`
- `BenchPressDetector`
- `SquatDetector`
- `ShoulderPressDetector`
- `RowDetector`

Thresholds are intentionally left as TODOs until real IMU data is recorded.
