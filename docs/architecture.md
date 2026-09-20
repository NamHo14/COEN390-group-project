# Architecture

## Overview
Smart Gym Tracker uses a mobile app + BLE + ESP32 + IMU pipeline. The user manually selects the exercise in the app before workout start.

No machine learning and no automatic exercise recognition are used.

## High-level diagram
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

## Data flow
1. App connects to ESP32 over BLE.
2. App sends exercise selection command.
3. ESP32 stores selected exercise in `ExerciseManager`.
4. `IMUManager` reads accelerometer/gyroscope samples.
5. Selected detector processes samples and emits rep events.
6. Firmware computes workout stats (rep count/set/tempo/rest/battery).
7. `BLEManager` sends telemetry back to app.

## Modularity boundary
- IMU-specific details stay behind `IMUManager`.
- Detectors consume neutral `IMUSample` data.
- Swapping IMU devices should require minimal changes outside the IMU layer.
