#pragma once

#include "Models.hpp"

namespace smart_gym {

class RepDetector {
public:
    virtual ~RepDetector() = default;

    virtual void reset() = 0;
    virtual bool update(const IMUSample& sample) = 0;
};

} // namespace smart_gym
