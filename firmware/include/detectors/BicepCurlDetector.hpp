#pragma once

#include "RepDetector.hpp"

namespace smart_gym {

class BicepCurlDetector : public RepDetector {
public:
    enum class State {
        BOTTOM = 0,
        MOVING_UP,
        TOP,
        MOVING_DOWN
    };

    void reset() override;
    bool update(const IMUSample& sample) override;

private:
    State state_ {State::BOTTOM};

    bool isMovingUp(const IMUSample& sample) const;
    bool reachedTop(const IMUSample& sample) const;
    bool isMovingDown(const IMUSample& sample) const;
    bool reachedBottom(const IMUSample& sample) const;
};

} // namespace smart_gym
