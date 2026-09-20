#include "detectors/RowDetector.hpp"

namespace smart_gym {

void RowDetector::reset() {
    // TODO: Reset detector state machine for RowDetector.
}

bool RowDetector::update(const IMUSample& /*sample*/) {
    // TODO: Implement exercise-specific state machine and calibrated thresholds.
    return false;
}

} // namespace smart_gym
