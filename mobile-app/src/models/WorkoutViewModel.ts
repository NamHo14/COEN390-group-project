export type ExerciseName =
  | 'BICEP_CURL'
  | 'BENCH_PRESS'
  | 'SQUAT'
  | 'SHOULDER_PRESS'
  | 'ROW';

export interface WorkoutViewModel {
  exerciseName: ExerciseName;
  currentSet: number;
  repCount: number;
  lastRepDurationSec: number;
  averageRepTempoSec: number;
  restTimerSec: number;
  batteryLevelPercent: number;
  isRunning: boolean;
}

export const initialWorkoutViewModel: WorkoutViewModel = {
  exerciseName: 'BICEP_CURL',
  currentSet: 1,
  repCount: 0,
  lastRepDurationSec: 0,
  averageRepTempoSec: 0,
  restTimerSec: 0,
  batteryLevelPercent: 0,
  isRunning: false,
};

// TODO: Bind BLE telemetry to this model.
// TODO: Persist completed workouts for history screen.
