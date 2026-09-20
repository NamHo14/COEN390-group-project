# IMU Data

The first version uses six motion channels:

```text
Ax
Ay
Az
Gx
Gy
Gz
```

Where:

- `Ax, Ay, Az` are acceleration values
- `Gx, Gy, Gz` are angular velocity values

## Initial Processing Pipeline

```text
Raw IMU Data
    |
    v
Calibration
    |
    v
Basic Filtering
    |
    v
Exercise Detector
```

## Important

Do not hard-code final thresholds until real exercise data has been recorded and visualized.
