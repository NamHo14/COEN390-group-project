# Smart Gym Tracker

Smart Gym Tracker is an embedded systems + mobile application project that uses an **ESP32** and an **IMU sensor** to automatically count repetitions and track workout statistics.

The user manually selects the exercise in the mobile app before beginning a set. The ESP32 then applies an exercise-specific motion detection algorithm using accelerometer and gyroscope data.

> Machine learning is intentionally not used in this project.

## Project Goals

- Connect a mobile app to an ESP32 using Bluetooth Low Energy (BLE)
- Let the user manually select an exercise
- Read accelerometer and gyroscope data from an IMU
- Count repetitions automatically
- Detect sets and rest periods
- Measure rep duration and exercise tempo
- Store workout history in the mobile app
- Eventually create a compact custom PCB and enclosure

## High-Level Architecture

```text
Mobile App
    |
    | BLE
    v
ESP32
    |
    +---- IMU
    |
    +---- Exercise Manager
    |
    +---- Rep Detection
    |
    +---- Workout Statistics
    |
    v
Mobile App
```

## Example Workout Flow

```text
User selects "Bicep Curl"
        |
        v
Mobile App
        |
        | BLE command
        v
ESP32
        |
        v
IMU Sensor
        |
        v
Bicep Curl Detector
        |
        v
Rep Count / Tempo / Set Data
        |
        | BLE
        v
Mobile App
```

## Planned Hardware

- ESP32 microcontroller
- IMU sensor with:
  - 3-axis accelerometer
  - 3-axis gyroscope
- BLE
- Rechargeable battery
- Battery charging circuit
- Voltage regulation
- Optional vibration motor
- Future custom PCB

Supported or candidate IMUs include:

- MPU6050
- MPU9250
- ICM-20948
- BMI160
- Similar 6-axis or 9-axis IMUs

The firmware is designed so the IMU driver can be replaced without changing the rest of the application.

## Repository Structure

```text
smart-gym-tracker/
├── README.md
├── LICENSE
├── .gitignore
├── firmware/
│   ├── README.md
│   ├── src/
│   ├── include/
│   ├── lib/
│   └── tests/
├── mobile-app/
│   ├── README.md
│   └── src/
├── hardware/
│   ├── README.md
│   ├── pcb/
│   ├── schematics/
│   ├── enclosure/
│   └── bom/
├── docs/
│   ├── architecture.md
│   ├── ble-protocol.md
│   ├── imu-data.md
│   └── rep-detection.md
├── tools/
│   ├── README.md
│   ├── sensor_visualizer/
│   └── data_logger/
└── data/
    ├── README.md
    └── sample-data/
```

## Initial Features

- BLE connection between ESP32 and mobile app
- Exercise selection from the mobile app
- Accelerometer and gyroscope reading
- IMU calibration
- Basic filtering
- Exercise-specific rep counting
- Rep duration
- Tempo tracking
- Set detection
- Rest timer
- Workout history
- Current rep and set display

## Future Features

- Partial repetition detection
- Excessively fast rep detection
- Pause detection
- Range-of-motion estimation
- Vibration feedback
- Battery monitoring
- Custom PCB
- Compact enclosure
- Additional exercise profiles

## Development Roadmap

1. Set up ESP32 project
2. Connect and read the IMU
3. Calibrate and filter IMU data
4. Send IMU data to a computer for visualization
5. Implement BLE communication
6. Create a basic mobile app
7. Add exercise selection
8. Implement bicep curl rep detection
9. Add more exercise detectors
10. Add sets, rest timer, and tempo tracking
11. Store workout history
12. Design custom PCB
13. Design compact enclosure

## Current Status

Repository scaffold created. Hardware-specific thresholds and movement algorithms have not yet been calibrated.

## Design Rule

The app always knows which exercise is being performed because the user selects it manually. The firmware does **not** attempt to identify exercises automatically.

## License

See `LICENSE`.
