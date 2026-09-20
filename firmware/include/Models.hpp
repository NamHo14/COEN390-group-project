#pragma once

#include <cstdint>

namespace smart_gym {

enum class ExerciseType {
    NONE = 0,
    BICEP_CURL,
    BENCH_PRESS,
    SQUAT,
    SHOULDER_PRESS,
    ROW
};

struct Vector3 {
    float x {0.0F};
    float y {0.0F};
    float z {0.0F};
};

struct IMUSample {
    std::uint32_t timestampMs {0U};
    Vector3 accelerometerMps2 {};
    Vector3 gyroscopeDps {};
};

struct WorkoutStats {
    std::uint32_t repCount {0U};
    std::uint32_t setCount {0U};
    float lastRepDurationSec {0.0F};
    float averageTempoSec {0.0F};
    std::uint32_t restTimeSec {0U};
    std::uint8_t batteryPercent {0U};
};

struct WorkoutState {
    bool workoutActive {false};
    ExerciseType selectedExercise {ExerciseType::NONE};
    WorkoutStats stats {};
};

} // namespace smart_gym
