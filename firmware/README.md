# Firmware (ESP32 Starter)

This folder contains modular, compile-oriented C++ starter code for an ESP32-based workout tracker.

## Scope
- Foundation only (not production-ready).
- Manual exercise selection is required (no automatic exercise recognition).
- Thresholds, filtering constants, and calibration values are intentionally left as TODOs.

## Intended modules
- `IMUManager`: IMU init/read/calibrate abstraction.
- `BLEManager`: BLE command parsing and telemetry transport.
- `ExerciseManager`: selected exercise + detector routing.
- `RepDetector`: common detector interface.
- Exercise detectors: bicep curl, bench press, squat, shoulder press, row.

## Toolchain placeholder
Choose one flow:
- PlatformIO (`espressif32`) 
- ESP-IDF
- Arduino-ESP32

TODO:
1. Pick a toolchain and add project files.
2. Add a concrete IMU driver adapter for the selected sensor.
3. Wire BLE callbacks to command parsing and telemetry publishing.

## Driver swap strategy
The IMU hardware boundary is isolated in `IMUManager` and data models so a chosen driver (MPU6050/MPU9250/ICM-20948/BMI160/...) can be integrated with minimal detector changes.
