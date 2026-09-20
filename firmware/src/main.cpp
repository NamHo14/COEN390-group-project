#include "BLEManager.hpp"
#include "ExerciseManager.hpp"
#include "IMUManager.hpp"

namespace {

void appLoop() {
    smart_gym::IMUManager imuManager;
    smart_gym::BLEManager bleManager;
    smart_gym::ExerciseManager exerciseManager;

    (void)imuManager.initialize();
    (void)imuManager.calibrate();
    (void)bleManager.initialize();

    // TODO: In target firmware, map BLE commands to exercise selection/workout state transitions.
    // TODO: Poll IMU sample rate and pass samples into selected detector.
    // TODO: Update and publish workout statistics over BLE.

    (void)exerciseManager;
}

} // namespace

int main() {
    appLoop();
    return 0;
}
