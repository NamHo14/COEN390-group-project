# Smart Gym Tracker

Smart Gym Tracker is a modular engineering project foundation for tracking workouts with an ESP32, an IMU sensor, and a BLE-connected mobile app.

## Project goals
- Build a clean, maintainable starter architecture for embedded firmware, mobile app integration, and hardware design.
- Keep the firmware modular so IMU drivers can be swapped (MPU6050, MPU9250, ICM-20948, BMI160, or similar).
- Support manual exercise selection from the app and exercise-specific rep detection logic.

## Explicit non-goals (current phase)
- **No machine learning**.
- **No automatic exercise recognition/classification**.
- No production-ready thresholds yet; thresholds and filtering parameters remain TODOs for experimental calibration.

## System architecture
```text
Mobile App
    |
   BLE
    v
ESP32
    +---- IMU
    +---- Exercise Manager
    +---- Rep Detection
    +---- Workout Statistics
    |
    v
Mobile App
```

## Initial features (foundation)
- BLE command/telemetry protocol documentation and starter interfaces.
- Manual exercise selection pipeline from mobile app to firmware.
- Modular firmware abstractions for IMU, BLE, exercise routing, and rep detectors.
- Bicep curl state-machine scaffold (`BOTTOM -> MOVING_UP -> TOP -> MOVING_DOWN -> BOTTOM`).
- Repository scaffolding for hardware files, tools, and sample data.

## Future features
- Experimentally calibrated thresholds and filters per exercise.
- Robust set detection, rest timer behavior, and workout history persistence.
- Battery monitoring and haptic feedback support.
- Custom PCB and enclosure iterations.

## Hardware (planned)
- ESP32 development board
- IMU sensor (candidate: MPU6050 / MPU9250 / ICM-20948 / BMI160)
- BLE-capable mobile device
- Rechargeable battery and charging circuitry
- Voltage regulation
- Optional vibration motor

## Software and tooling
- Embedded C++ (ESP32 firmware)
- BLE command protocol (text-based, versionable)
- Mobile app scaffold (framework-agnostic starter)
- Python utilities for debugging/visualization only (no ML)

## Repository structure
```text
README.md
LICENSE
.gitignore

firmware/
    README.md
    src/
    include/
    lib/
    tests/

mobile-app/
    README.md
    src/

hardware/
    README.md
    pcb/
    schematics/
    enclosure/
    bom/

docs/
    architecture.md
    ble-protocol.md
    imu-data.md
    rep-detection.md

tools/
    README.md
    sensor_visualizer/
    data_logger/

data/
    README.md
    sample-data/
```

## End-to-end flow
1. User opens mobile app and connects to ESP32 over BLE.
2. User manually selects an exercise in app.
3. App sends `SELECT_EXERCISE:<EXERCISE_NAME>`.
4. User starts workout (`START_WORKOUT`).
5. ESP32 reads IMU accelerometer/gyroscope samples.
6. Exercise-specific detector updates rep count.
7. ESP32 streams telemetry (reps/sets/tempo/rest/battery) to app.
8. App displays workout progress and stores history.

## Current development status
This repository currently provides a starter foundation and placeholders. It is not a finished product and does not claim production-ready motion thresholds.

## Roadmap
1. Set up ESP32 project.
2. Connect and read IMU sensor.
3. Calibrate and filter IMU data.
4. Stream IMU data for visualization.
5. Implement BLE communication.
6. Create basic mobile app.
7. Add manual exercise selection workflow.
8. Implement bicep curl rep detection.
9. Add additional exercise detectors.
10. Add sets, rest timer, and tempo logic.
11. Persist workout history in app.
12. Design custom PCB.
13. Design compact enclosure.

## Setup (placeholders)
- Firmware setup: see `firmware/README.md` for ESP32 toolchain placeholders.
- Mobile app setup: see `mobile-app/README.md` for framework selection placeholder.
- Hardware docs: see `hardware/README.md`.
- BLE protocol details: see `docs/ble-protocol.md`.

## Contributing / development guidance
- Keep modules small, explicit, and testable.
- Preserve manual exercise selection as a core rule.
- Do not add ML or automatic exercise inference.
- Use TODOs for experimentally determined thresholds and calibration constants.
