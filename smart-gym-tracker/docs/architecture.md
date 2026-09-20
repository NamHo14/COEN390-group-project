# System Architecture

## Overview

Smart Gym Tracker is divided into four main parts:

1. Mobile application
2. ESP32 firmware
3. IMU sensor
4. Hardware platform

## Data Flow

```text
Mobile App
    |
    | BLE command: SELECT_EXERCISE:BICEP_CURL
    v
ESP32
    |
    | I2C
    v
IMU
    |
    | Ax Ay Az Gx Gy Gz
    v
Exercise-Specific Rep Detector
    |
    v
Workout Statistics
    |
    | BLE
    v
Mobile App
```

## Design Principle

The user manually selects the exercise. The firmware never tries to guess which exercise is being performed.
