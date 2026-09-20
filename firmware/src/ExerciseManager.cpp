#include "ExerciseManager.hpp"

#include "detectors/BenchPressDetector.hpp"
#include "detectors/BicepCurlDetector.hpp"
#include "detectors/RowDetector.hpp"
#include "detectors/ShoulderPressDetector.hpp"
#include "detectors/SquatDetector.hpp"

namespace smart_gym {

ExerciseManager::ExerciseManager()
    : selected_(ExerciseType::NONE) {}

void ExerciseManager::setExercise(ExerciseType type) {
    selected_ = type;
    createDetectorForSelection();
}

ExerciseType ExerciseManager::selectedExercise() const {
    return selected_;
}

bool ExerciseManager::processSample(const IMUSample& sample) {
    if (!detector_) {
        return false;
    }
    return detector_->update(sample);
}

void ExerciseManager::resetDetector() {
    if (detector_) {
        detector_->reset();
    }
}

void ExerciseManager::createDetectorForSelection() {
    switch (selected_) {
        case ExerciseType::BICEP_CURL:
            detector_ = std::make_unique<BicepCurlDetector>();
            break;
        case ExerciseType::BENCH_PRESS:
            detector_ = std::make_unique<BenchPressDetector>();
            break;
        case ExerciseType::SQUAT:
            detector_ = std::make_unique<SquatDetector>();
            break;
        case ExerciseType::SHOULDER_PRESS:
            detector_ = std::make_unique<ShoulderPressDetector>();
            break;
        case ExerciseType::ROW:
            detector_ = std::make_unique<RowDetector>();
            break;
        case ExerciseType::NONE:
        default:
            detector_.reset();
            break;
    }
}

} // namespace smart_gym
