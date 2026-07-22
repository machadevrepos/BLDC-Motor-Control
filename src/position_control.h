/******************************************************************************
 * CUSTOM PROJECT MODULE - NOT PART OF THE ORIGINAL NXP FIRMWARE
 *
 * Relative multi-turn mechanical position outer-loop controller.
 *
 * This module is hardware independent. It produces a bounded speed request for
 * the existing speed loop and never accesses motor-control application globals.
 * The complete contents of this file were added for this project's relative
 * position-control feature.
 *
 * Position is relative to the most recent initialization/alignment or software
 * zero. This interface does not provide absolute homing or retained position.
 ******************************************************************************/

#ifndef POSITION_CONTROL_H
#define POSITION_CONTROL_H

#include <stdbool.h>
#include <stdint.h>

/* Tuning-application result reported to the application and FreeMASTER status.
 * A rejected candidate never partially replaces the active tuning structure. */
typedef enum
{
    POSITION_CONTROL_TUNING_NOT_APPLIED = 0,
    POSITION_CONTROL_TUNING_ACCEPTED,
    POSITION_CONTROL_TUNING_REJECTED_NULL,
    POSITION_CONTROL_TUNING_REJECTED_NUMERIC,
    POSITION_CONTROL_TUNING_REJECTED_LIMIT,
    POSITION_CONTROL_TUNING_REJECTED_SOFT_LIMIT
} PositionControlTuningResult;

/* Diagnostic bit field. Encoder and numeric diagnostics invalidate the output;
 * application permission is still owned and decided by the integration layer. */
enum
{
    POSITION_CONTROL_DIAG_NONE = 0U,
    POSITION_CONTROL_DIAG_CONFIG = (1UL << 0),
    POSITION_CONTROL_DIAG_ENCODER_RANGE = (1UL << 1),
    POSITION_CONTROL_DIAG_ENCODER_HALF_TURN = (1UL << 2),
    POSITION_CONTROL_DIAG_ENCODER_PHYSICAL_DELTA = (1UL << 3),
    POSITION_CONTROL_DIAG_PERMISSION = (1UL << 4),
    POSITION_CONTROL_DIAG_NUMERIC = (1UL << 5)
};

/* Immutable controller configuration copied from authoritative firmware values
 * during initialization. Speeds are mechanical rad/s and periods are seconds. */
typedef struct
{
    uint16_t countsPerMechanicalRev;
    float polePairs;
    int32_t encoderDirection;
    float encoderSampleSec;
    float positionLoopSampleSec;
    float safeMaxMechanicalRadPerSec;
} PositionControlConfig;

/* Atomically applied runtime tuning. Position is expressed in quadrature counts,
 * speed in mechanical rad/s, and acceleration/deceleration in mechanical rad/s^2.
 * Kp has units rad/s/count; Ki has units rad/s/(count*second). */
typedef struct
{
    float kpMechanicalRadPerSecPerCount;
    float kiMechanicalRadPerSecPerCountSec;
    float integratorLimitMechanicalRadPerSec;
    float maxMechanicalRadPerSec;
    float maxAccelMechanicalRadPerSec2;
    float maxDecelMechanicalRadPerSec2;
    int64_t positionToleranceCounts;
    float stoppedMechanicalRadPerSec;
    float atTargetDwellSec;
    bool negativeSoftLimitEnabled;
    int64_t negativeSoftLimitCounts;
    bool positiveSoftLimitEnabled;
    int64_t positiveSoftLimitCounts;
} PositionControlTuning;

/* Runtime feedback and permission supplied by the application at the existing
 * speed-loop boundary. The isolated module does not inspect NXP globals itself. */
typedef struct
{
    float measuredMechanicalRadPerSec;
    bool encoderValid;
    bool controlPermitted;
} PositionControlInput;

/* Read-only result/status contract returned to the application. Mechanical speed
 * is converted to electrical rad/s only in electricalRadPerSec for the existing
 * NXP speed-loop input; no current, voltage, duty, or PWM request is produced. */
typedef struct
{
    bool valid;
    bool enabled;
    bool encoderValid;
    bool targetArmed;
    bool atTarget;
    bool targetClamped;
    bool speedLimited;
    bool accelerationLimited;
    float requestedMechanicalRadPerSec;
    float limitedMechanicalRadPerSec;
    float electricalRadPerSec;
    int64_t multiTurnPositionCounts;
    float multiTurnPositionDegrees;
    int64_t targetPositionCounts;
    int64_t positionErrorCounts;
    float integratorMechanicalRadPerSec;
    float measuredMechanicalRadPerSec;
    float activeMaxMechanicalRadPerSec;
    float activeMaxAccelMechanicalRadPerSec2;
    float activeMaxDecelMechanicalRadPerSec2;
    PositionControlTuningResult tuningResult;
    uint32_t diagnosticFlags;
} PositionControlOutput;

/* Controller-owned runtime state. The application allocates this object but must
 * modify it only through the public API below. The signed 64-bit accumulator is
 * independent of the wrapped electrical angle used by the original FOC code. */
typedef struct
{
    PositionControlConfig config;
    PositionControlTuning tuning;
    PositionControlOutput output;
    uint32_t maxEncoderDeltaCounts;
    uint32_t atTargetDwellTicks;
    uint32_t atTargetCounter;
    uint16_t previousWrappedCount;
    int64_t accumulatedPositionCounts;
    int64_t softwareZeroOffsetCounts;
    int64_t targetPositionCounts;
    float integratorMechanicalRadPerSec;
    float previousLimitedMechanicalRadPerSec;
    bool configValid;
    bool tuningValid;
    bool encoderInitialized;
    bool encoderValid;
    bool enabled;
    bool targetArmed;
    bool targetClamped;
    uint32_t encoderDiagnosticFlags;
} PositionControlState;

/* Public API
 *
 * Typical call order:
 *   Init -> ApplyTuning -> repeated UpdateEncoder -> Enable -> SetTarget -> Run.
 * Reset/Disable are safe from any state. Enable is bumpless and captures the
 * current relative position; a later target command is required to arm motion. */
bool PositionControl_Init(PositionControlState *state,
                          const PositionControlConfig *config);
void PositionControl_Reset(PositionControlState *state);
bool PositionControl_UpdateEncoder(PositionControlState *state,
                                   uint16_t wrappedCount,
                                   bool encoderValid);
bool PositionControl_Enable(PositionControlState *state,
                            bool controlPermitted);
void PositionControl_Disable(PositionControlState *state);
bool PositionControl_ApplyTuning(PositionControlState *state,
                                 const PositionControlTuning *tuning);
bool PositionControl_SetTargetCounts(PositionControlState *state,
                                     int64_t targetCounts);
bool PositionControl_SetTargetDegrees(PositionControlState *state,
                                      float targetDegrees);
void PositionControl_SetSoftwareZero(PositionControlState *state);
PositionControlOutput PositionControl_Run(PositionControlState *state,
                                          const PositionControlInput *input);
const PositionControlOutput *PositionControl_GetOutput(
    const PositionControlState *state);

#endif /* POSITION_CONTROL_H */
