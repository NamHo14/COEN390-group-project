# IMU Data Notes

## Sensor channels
- Accelerometer: `m/s^2`
- Gyroscope: `deg/s`
- Timestamp: milliseconds from firmware boot or synchronized session start

## Sample model
```text
timestamp_ms,accel_x,accel_y,accel_z,gyro_x,gyro_y,gyro_z
10234,0.02,9.78,0.34,-1.2,35.5,0.9
```

## Frame assumptions
- Device/body frame mapping must be documented once sensor orientation is fixed.
- Early detectors may use one dominant axis; final versions should validate orientation assumptions.

## Calibration placeholders
- TODO: Gyroscope bias estimation while stationary.
- TODO: Accelerometer bias/scale correction.
- TODO: Drift checks over workout sessions.

## Filtering placeholders
- TODO: Select and tune low-pass/high-pass filters experimentally.
- TODO: Evaluate smoothing window size for latency vs noise trade-off.
