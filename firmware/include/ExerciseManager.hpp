#pragma once

#include <memory>

#include "Models.hpp"
#include "RepDetector.hpp"

namespace smart_gym {

class ExerciseManager {
public:
    ExerciseManager();

    void setExercise(ExerciseType type);
    ExerciseType selectedExercise() const;

    bool processSample(const IMUSample& sample);
    void resetDetector();

private:
    ExerciseType selected_;
    std::unique_ptr<RepDetector> detector_;

    void createDetectorForSelection();
};

} // namespace smart_gym
