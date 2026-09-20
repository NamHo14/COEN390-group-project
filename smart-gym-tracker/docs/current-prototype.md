# Current Prototype Hardware

Current available hardware:

- ESP32-WROOM-32 development board
- MPU9250 IMU

This is enough to begin the project.

Recommended first connection using I2C on a typical ESP32 development board:

```text
MPU9250     ESP32
VCC   ->    3.3V
GND   ->    GND
SDA   ->    GPIO 21
SCL   ->    GPIO 22
```

Verify the exact MPU9250 breakout board voltage requirements before powering it.
