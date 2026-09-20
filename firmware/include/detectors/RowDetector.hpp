#pragma once

#include "RepDetector.hpp"

namespace smart_gym {

class RowDetector : public RepDetector {
public:
    void reset() override;
    bool update(const IMUSample& sample) override;
};

} // namespace smart_gym
