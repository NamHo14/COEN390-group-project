#include "detectors/SquatDetector.hpp"

namespace smart_gym {

void SquatDetector::reset() {
    // TODO: Reset detector state machine for SquatDetector.
}

bool SquatDetector::update(const IMUSample& /*sample*/) {
    // TODO: Implement exercise-specific state machine and calibrated thresholds.
    return false;
}

} // namespace smart_gym
