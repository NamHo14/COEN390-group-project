#include "IMUManager.hpp"

namespace smart_gym {

bool IMUManager::initialize() {
    // TODO: Initialize selected IMU hardware driver and configure sample rate.
    return true;
}

bool IMUManager::calibrate() {
    // TODO: Collect stationary samples and compute gyro/accel bias correction.
    return true;
}

IMUSample IMUManager::readSample() const {
    IMUSample sample {};
    // TODO: Read real accelerometer/gyroscope data from selected IMU driver.
    return sample;
}

} // namespace smart_gym
