#include "detectors/BenchPressDetector.hpp"

namespace smart_gym {

void BenchPressDetector::reset() {
    // TODO: Reset detector state machine for BenchPressDetector.
}

bool BenchPressDetector::update(const IMUSample& /*sample*/) {
    // TODO: Implement exercise-specific state machine and calibrated thresholds.
    return false;
}

} // namespace smart_gym
