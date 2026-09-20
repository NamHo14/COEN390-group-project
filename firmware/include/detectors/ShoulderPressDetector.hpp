#pragma once

#include "RepDetector.hpp"

namespace smart_gym {

class ShoulderPressDetector : public RepDetector {
public:
    void reset() override;
    bool update(const IMUSample& sample) override;
};

} // namespace smart_gym
