#include "detectors/BicepCurlDetector.hpp"

namespace smart_gym {

void BicepCurlDetector::reset() {
    state_ = State::BOTTOM;
}

bool BicepCurlDetector::update(const IMUSample& sample) {
    switch (state_) {
        case State::BOTTOM:
            if (isMovingUp(sample)) {
                state_ = State::MOVING_UP;
            }
            break;
        case State::MOVING_UP:
            if (reachedTop(sample)) {
                state_ = State::TOP;
            }
            break;
        case State::TOP:
            if (isMovingDown(sample)) {
                state_ = State::MOVING_DOWN;
            }
            break;
        case State::MOVING_DOWN:
            if (reachedBottom(sample)) {
                state_ = State::BOTTOM;
                return true;
            }
            break;
    }

    return false;
}

bool BicepCurlDetector::isMovingUp(const IMUSample& sample) const {
    // TODO: Replace with calibrated threshold from real IMU experiments.
    return sample.gyroscopeDps.y > 30.0F;
}

bool BicepCurlDetector::reachedTop(const IMUSample& sample) const {
    // TODO: Replace with calibrated top-position condition.
    return sample.accelerometerMps2.z > 7.0F;
}

bool BicepCurlDetector::isMovingDown(const IMUSample& sample) const {
    // TODO: Replace with calibrated threshold from real IMU experiments.
    return sample.gyroscopeDps.y < -30.0F;
}

bool BicepCurlDetector::reachedBottom(const IMUSample& sample) const {
    // TODO: Replace with calibrated bottom-position condition.
    return sample.accelerometerMps2.z < 3.0F;
}

} // namespace smart_gym
