#pragma once

#include <string>

#include "Models.hpp"

namespace smart_gym {

class BLEManager {
public:
    bool initialize();

    bool sendRepCount(std::uint32_t repCount);
    bool sendWorkoutStats(const WorkoutStats& stats);

    // Receives app commands, e.g. SELECT_EXERCISE:BICEP_CURL, START_WORKOUT.
    void handleIncomingCommand(const std::string& command);
};

} // namespace smart_gym
