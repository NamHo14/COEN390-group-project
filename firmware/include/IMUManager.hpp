#pragma once

#include "Models.hpp"

namespace smart_gym {

class IMUManager {
public:
    bool initialize();
    bool calibrate();
    IMUSample readSample() const;
};

} // namespace smart_gym
