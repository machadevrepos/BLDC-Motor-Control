#include "position_control.h"

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

#define POSITION_CONTROL_TWO_PI (6.28318530717958647692F)
#define POSITION_CONTROL_DEGREES_PER_REV (360.0F)

static bool PositionControl_IsFinite(float value)
{
    return isfinite(value) != 0;
}

static float PositionControl_AbsFloat(float value)
{
    return (value < 0.0F) ? -value : value;
}

static int64_t PositionControl_AbsCounts(int64_t value)
{
    if (value == INT64_MIN)
    {
        return INT64_MAX;
    }
    return (value < 0) ? -value : value;
}

static float PositionControl_ClampFloat(float value, float lower, float upper)
{
    if (value > upper)
    {
        return upper;
    }
    if (value < lower)
    {
        return lower;
    }
    return value;
}

static int64_t PositionControl_SubtractCounts(int64_t left, int64_t right)
{
    if ((right > 0) && (left < (INT64_MIN + right)))
    {
        return INT64_MIN;
    }
    if ((right < 0) && (left > (INT64_MAX + right)))
    {
        return INT64_MAX;
    }
    return left - right;
}

static int64_t PositionControl_GetRelativeCounts(const PositionControlState *state)
{
    return PositionControl_SubtractCounts(state->accumulatedPositionCounts,
                                          state->softwareZeroOffsetCounts);
}

static float PositionControl_CountsToDegrees(const PositionControlState *state,
                                             int64_t counts)
{
    double degrees;

    if ((state == NULL) || (state->config.countsPerMechanicalRev == 0U))
    {
        return 0.0F;
    }

    degrees = ((double)counts * (double)POSITION_CONTROL_DEGREES_PER_REV) /
              (double)state->config.countsPerMechanicalRev;
    if ((degrees > (double)FLT_MAX) || (degrees < (double)-FLT_MAX))
    {
        return (degrees < 0.0) ? -FLT_MAX : FLT_MAX;
    }
    return (float)degrees;
}

static void PositionControl_UpdatePositionOutput(PositionControlState *state)
{
    int64_t positionCounts = PositionControl_GetRelativeCounts(state);

    state->output.multiTurnPositionCounts = positionCounts;
    state->output.multiTurnPositionDegrees =
        PositionControl_CountsToDegrees(state, positionCounts);
    state->output.targetPositionCounts = state->targetPositionCounts;
    state->output.positionErrorCounts =
        PositionControl_SubtractCounts(state->targetPositionCounts,
                                       positionCounts);
    state->output.encoderValid = state->encoderValid;
    state->output.targetArmed = state->targetArmed;
    state->output.targetClamped = state->targetClamped;
    state->output.integratorMechanicalRadPerSec =
        state->integratorMechanicalRadPerSec;
    state->output.diagnosticFlags = state->encoderDiagnosticFlags;
}

static void PositionControl_ClearMotionState(PositionControlState *state)
{
    state->integratorMechanicalRadPerSec = 0.0F;
    state->previousLimitedMechanicalRadPerSec = 0.0F;
    state->atTargetCounter = 0U;
    state->output.atTarget = false;
    state->output.requestedMechanicalRadPerSec = 0.0F;
    state->output.limitedMechanicalRadPerSec = 0.0F;
    state->output.electricalRadPerSec = 0.0F;
    state->output.speedLimited = false;
    state->output.accelerationLimited = false;
    state->output.integratorMechanicalRadPerSec = 0.0F;
}

static bool PositionControl_ValidateConfig(const PositionControlConfig *config,
                                           uint32_t *maxEncoderDeltaCounts)
{
    float maximumDelta;
    uint32_t halfRevolution;
    uint32_t deltaCounts;

    if ((config == NULL) || (maxEncoderDeltaCounts == NULL))
    {
        return false;
    }
    if ((config->countsPerMechanicalRev <= 2U) ||
        ((config->encoderDirection != 1) && (config->encoderDirection != -1)) ||
        !PositionControl_IsFinite(config->polePairs) ||
        !PositionControl_IsFinite(config->encoderSampleSec) ||
        !PositionControl_IsFinite(config->positionLoopSampleSec) ||
        !PositionControl_IsFinite(config->safeMaxMechanicalRadPerSec) ||
        (config->polePairs <= 0.0F) ||
        (floorf(config->polePairs) != config->polePairs) ||
        (config->encoderSampleSec <= 0.0F) ||
        (config->positionLoopSampleSec <= 0.0F) ||
        (config->safeMaxMechanicalRadPerSec <= 0.0F))
    {
        return false;
    }

    maximumDelta = (config->safeMaxMechanicalRadPerSec *
                    config->encoderSampleSec *
                    (float)config->countsPerMechanicalRev) /
                   POSITION_CONTROL_TWO_PI;
    if (!PositionControl_IsFinite(maximumDelta) || (maximumDelta < 0.0F))
    {
        return false;
    }

    maximumDelta = ceilf(maximumDelta) + 1.0F;
    halfRevolution = (uint32_t)config->countsPerMechanicalRev / 2U;
    if (maximumDelta >= (float)halfRevolution)
    {
        deltaCounts = halfRevolution - 1U;
    }
    else
    {
        deltaCounts = (uint32_t)maximumDelta;
    }
    if (deltaCounts == 0U)
    {
        deltaCounts = 1U;
    }

    *maxEncoderDeltaCounts = deltaCounts;
    return true;
}

static PositionControlTuningResult PositionControl_ValidateTuning(
    const PositionControlState *state,
    const PositionControlTuning *tuning,
    uint32_t *dwellTicks)
{
    float ticks;

    if ((state == NULL) || (tuning == NULL) || (dwellTicks == NULL))
    {
        return POSITION_CONTROL_TUNING_REJECTED_NULL;
    }
    if (!PositionControl_IsFinite(tuning->kpMechanicalRadPerSecPerCount) ||
        !PositionControl_IsFinite(tuning->kiMechanicalRadPerSecPerCountSec) ||
        !PositionControl_IsFinite(tuning->integratorLimitMechanicalRadPerSec) ||
        !PositionControl_IsFinite(tuning->maxMechanicalRadPerSec) ||
        !PositionControl_IsFinite(tuning->maxAccelMechanicalRadPerSec2) ||
        !PositionControl_IsFinite(tuning->maxDecelMechanicalRadPerSec2) ||
        !PositionControl_IsFinite(tuning->stoppedMechanicalRadPerSec) ||
        !PositionControl_IsFinite(tuning->atTargetDwellSec))
    {
        return POSITION_CONTROL_TUNING_REJECTED_NUMERIC;
    }
    if ((tuning->kpMechanicalRadPerSecPerCount < 0.0F) ||
        (tuning->kiMechanicalRadPerSecPerCountSec < 0.0F) ||
        (tuning->integratorLimitMechanicalRadPerSec < 0.0F) ||
        ((tuning->kiMechanicalRadPerSecPerCountSec > 0.0F) &&
         (tuning->integratorLimitMechanicalRadPerSec <= 0.0F)) ||
        (tuning->maxMechanicalRadPerSec <= 0.0F) ||
        (tuning->maxMechanicalRadPerSec >
         state->config.safeMaxMechanicalRadPerSec) ||
        (tuning->maxAccelMechanicalRadPerSec2 <= 0.0F) ||
        (tuning->maxDecelMechanicalRadPerSec2 <= 0.0F) ||
        (tuning->positionToleranceCounts < 0) ||
        (tuning->stoppedMechanicalRadPerSec < 0.0F) ||
        (tuning->atTargetDwellSec < 0.0F))
    {
        return POSITION_CONTROL_TUNING_REJECTED_LIMIT;
    }
    if (tuning->negativeSoftLimitEnabled &&
        tuning->positiveSoftLimitEnabled &&
        (tuning->negativeSoftLimitCounts >= tuning->positiveSoftLimitCounts))
    {
        return POSITION_CONTROL_TUNING_REJECTED_SOFT_LIMIT;
    }

    ticks = ceilf(tuning->atTargetDwellSec /
                  state->config.positionLoopSampleSec);
    if (!PositionControl_IsFinite(ticks) || (ticks > (float)UINT32_MAX))
    {
        return POSITION_CONTROL_TUNING_REJECTED_LIMIT;
    }
    *dwellTicks = (ticks < 1.0F) ? 1U : (uint32_t)ticks;
    return POSITION_CONTROL_TUNING_ACCEPTED;
}

bool PositionControl_Init(PositionControlState *state,
                          const PositionControlConfig *config)
{
    uint32_t maximumDelta = 0U;

    if (state == NULL)
    {
        return false;
    }
    (void)memset(state, 0, sizeof(*state));
    if (!PositionControl_ValidateConfig(config, &maximumDelta))
    {
        state->output.diagnosticFlags = POSITION_CONTROL_DIAG_CONFIG;
        return false;
    }

    state->config = *config;
    state->maxEncoderDeltaCounts = maximumDelta;
    state->configValid = true;
    state->output.tuningResult = POSITION_CONTROL_TUNING_NOT_APPLIED;
    PositionControl_Reset(state);
    return true;
}

void PositionControl_Reset(PositionControlState *state)
{
    PositionControlConfig config;
    PositionControlTuning tuning;
    uint32_t maximumDelta;
    uint32_t dwellTicks;
    bool configValid;
    bool tuningValid;
    PositionControlTuningResult tuningResult;

    if (state == NULL)
    {
        return;
    }

    config = state->config;
    tuning = state->tuning;
    maximumDelta = state->maxEncoderDeltaCounts;
    dwellTicks = state->atTargetDwellTicks;
    configValid = state->configValid;
    tuningValid = state->tuningValid;
    tuningResult = state->output.tuningResult;
    (void)memset(state, 0, sizeof(*state));
    state->config = config;
    state->tuning = tuning;
    state->maxEncoderDeltaCounts = maximumDelta;
    state->atTargetDwellTicks = dwellTicks;
    state->configValid = configValid;
    state->tuningValid = tuningValid;
    state->output.tuningResult = tuningResult;
    state->output.activeMaxMechanicalRadPerSec = tuning.maxMechanicalRadPerSec;
    state->output.activeMaxAccelMechanicalRadPerSec2 =
        tuning.maxAccelMechanicalRadPerSec2;
    state->output.activeMaxDecelMechanicalRadPerSec2 =
        tuning.maxDecelMechanicalRadPerSec2;
}

bool PositionControl_UpdateEncoder(PositionControlState *state,
                                   uint16_t wrappedCount,
                                   bool encoderValid)
{
    int32_t delta;
    int32_t halfRevolution;
    int32_t countsPerRevolution;
    uint32_t magnitude;

    if ((state == NULL) || !state->configValid)
    {
        return false;
    }
    if (!encoderValid)
    {
        state->encoderValid = false;
        state->encoderInitialized = false;
        PositionControl_UpdatePositionOutput(state);
        return false;
    }
    if (wrappedCount >= state->config.countsPerMechanicalRev)
    {
        state->encoderValid = false;
        state->encoderInitialized = false;
        state->encoderDiagnosticFlags = POSITION_CONTROL_DIAG_ENCODER_RANGE;
        PositionControl_UpdatePositionOutput(state);
        return false;
    }
    if (!state->encoderInitialized)
    {
        state->previousWrappedCount = wrappedCount;
        state->encoderInitialized = true;
        state->encoderValid = true;
        state->encoderDiagnosticFlags = POSITION_CONTROL_DIAG_NONE;
        PositionControl_UpdatePositionOutput(state);
        return true;
    }

    countsPerRevolution = (int32_t)state->config.countsPerMechanicalRev;
    halfRevolution = countsPerRevolution / 2;
    delta = (int32_t)wrappedCount - (int32_t)state->previousWrappedCount;
    if (((countsPerRevolution & 1) == 0) &&
        ((delta == halfRevolution) || (delta == -halfRevolution)))
    {
        state->encoderValid = false;
        state->encoderInitialized = false;
        state->encoderDiagnosticFlags = POSITION_CONTROL_DIAG_ENCODER_HALF_TURN;
        PositionControl_UpdatePositionOutput(state);
        return false;
    }
    if (delta > halfRevolution)
    {
        delta -= countsPerRevolution;
    }
    else if (delta < -halfRevolution)
    {
        delta += countsPerRevolution;
    }
    delta *= state->config.encoderDirection;
    magnitude = (uint32_t)((delta < 0) ? -delta : delta);
    if (magnitude > state->maxEncoderDeltaCounts)
    {
        state->encoderValid = false;
        state->encoderInitialized = false;
        state->encoderDiagnosticFlags =
            POSITION_CONTROL_DIAG_ENCODER_PHYSICAL_DELTA;
        PositionControl_UpdatePositionOutput(state);
        return false;
    }

    if (((delta > 0) &&
         (state->accumulatedPositionCounts > (INT64_MAX - delta))) ||
        ((delta < 0) &&
         (state->accumulatedPositionCounts < (INT64_MIN - delta))))
    {
        state->encoderValid = false;
        state->encoderInitialized = false;
        state->encoderDiagnosticFlags = POSITION_CONTROL_DIAG_NUMERIC;
        PositionControl_UpdatePositionOutput(state);
        return false;
    }

    state->accumulatedPositionCounts += delta;
    state->previousWrappedCount = wrappedCount;
    state->encoderValid = true;
    state->encoderDiagnosticFlags = POSITION_CONTROL_DIAG_NONE;
    PositionControl_UpdatePositionOutput(state);
    return true;
}

bool PositionControl_Enable(PositionControlState *state,
                            bool controlPermitted)
{
    int64_t currentPosition;

    if ((state == NULL) || !state->configValid || !state->tuningValid ||
        !controlPermitted || !state->encoderInitialized ||
        !state->encoderValid || (state->encoderDiagnosticFlags != 0U))
    {
        if (state != NULL)
        {
            PositionControl_Disable(state);
            if (!controlPermitted)
            {
                state->output.diagnosticFlags |= POSITION_CONTROL_DIAG_PERMISSION;
            }
        }
        return false;
    }

    currentPosition = PositionControl_GetRelativeCounts(state);
    state->targetPositionCounts = currentPosition;
    state->enabled = true;
    state->targetArmed = false;
    state->targetClamped = false;
    PositionControl_ClearMotionState(state);
    state->output.valid = true;
    state->output.enabled = true;
    PositionControl_UpdatePositionOutput(state);
    return true;
}

void PositionControl_Disable(PositionControlState *state)
{
    if (state == NULL)
    {
        return;
    }
    state->enabled = false;
    state->targetArmed = false;
    state->targetClamped = false;
    PositionControl_ClearMotionState(state);
    state->output.valid = false;
    state->output.enabled = false;
    PositionControl_UpdatePositionOutput(state);
}

bool PositionControl_ApplyTuning(PositionControlState *state,
                                 const PositionControlTuning *tuning)
{
    uint32_t dwellTicks = 0U;
    PositionControlTuningResult result;
    bool targetWasArmed;

    if ((state == NULL) || !state->configValid)
    {
        return false;
    }

    result = PositionControl_ValidateTuning(state, tuning, &dwellTicks);
    state->output.tuningResult = result;
    if (result != POSITION_CONTROL_TUNING_ACCEPTED)
    {
        return false;
    }

    state->tuning = *tuning;
    state->atTargetDwellTicks = dwellTicks;
    state->tuningValid = true;
    state->output.activeMaxMechanicalRadPerSec = tuning->maxMechanicalRadPerSec;
    state->output.activeMaxAccelMechanicalRadPerSec2 =
        tuning->maxAccelMechanicalRadPerSec2;
    state->output.activeMaxDecelMechanicalRadPerSec2 =
        tuning->maxDecelMechanicalRadPerSec2;

    if (state->enabled)
    {
        targetWasArmed = state->targetArmed;
        (void)PositionControl_SetTargetCounts(state,
                                              state->targetPositionCounts);
        state->targetArmed = targetWasArmed;
        state->output.targetArmed = targetWasArmed;
    }
    return true;
}

bool PositionControl_SetTargetCounts(PositionControlState *state,
                                     int64_t targetCounts)
{
    if ((state == NULL) || !state->enabled || !state->tuningValid)
    {
        return false;
    }

    state->targetClamped = false;
    if (state->tuning.negativeSoftLimitEnabled &&
        (targetCounts < state->tuning.negativeSoftLimitCounts))
    {
        targetCounts = state->tuning.negativeSoftLimitCounts;
        state->targetClamped = true;
    }
    if (state->tuning.positiveSoftLimitEnabled &&
        (targetCounts > state->tuning.positiveSoftLimitCounts))
    {
        targetCounts = state->tuning.positiveSoftLimitCounts;
        state->targetClamped = true;
    }

    state->targetPositionCounts = targetCounts;
    state->targetArmed = true;
    state->atTargetCounter = 0U;
    state->output.atTarget = false;
    PositionControl_UpdatePositionOutput(state);
    return true;
}

bool PositionControl_SetTargetDegrees(PositionControlState *state,
                                      float targetDegrees)
{
    double counts;
    int64_t roundedCounts;

    if ((state == NULL) || !PositionControl_IsFinite(targetDegrees) ||
        !state->configValid)
    {
        return false;
    }

    counts = ((double)targetDegrees *
              (double)state->config.countsPerMechanicalRev) /
             (double)POSITION_CONTROL_DEGREES_PER_REV;
    if ((counts >= (double)INT64_MAX) || (counts <= (double)INT64_MIN))
    {
        return false;
    }
    roundedCounts = (int64_t)((counts >= 0.0) ? (counts + 0.5) :
                                               (counts - 0.5));
    return PositionControl_SetTargetCounts(state, roundedCounts);
}

void PositionControl_SetSoftwareZero(PositionControlState *state)
{
    int64_t previousPosition;

    if ((state == NULL) || !state->encoderInitialized)
    {
        return;
    }

    previousPosition = PositionControl_GetRelativeCounts(state);
    state->softwareZeroOffsetCounts = state->accumulatedPositionCounts;
    state->targetPositionCounts =
        PositionControl_SubtractCounts(state->targetPositionCounts,
                                       previousPosition);
    PositionControl_UpdatePositionOutput(state);
}

static float PositionControl_ApplyRateLimit(const PositionControlState *state,
                                            float requested,
                                            bool *limited)
{
    float previous = state->previousLimitedMechanicalRadPerSec;
    float delta = requested - previous;
    bool increasingMagnitude =
        (((requested >= 0.0F) && (previous >= 0.0F)) ||
         ((requested <= 0.0F) && (previous <= 0.0F))) &&
        (PositionControl_AbsFloat(requested) >
         PositionControl_AbsFloat(previous));
    float rate = increasingMagnitude ?
        state->tuning.maxAccelMechanicalRadPerSec2 :
        state->tuning.maxDecelMechanicalRadPerSec2;
    float maximumDelta = rate * state->config.positionLoopSampleSec;

    *limited = false;
    if (delta > maximumDelta)
    {
        *limited = true;
        return previous + maximumDelta;
    }
    if (delta < -maximumDelta)
    {
        *limited = true;
        return previous - maximumDelta;
    }
    return requested;
}

PositionControlOutput PositionControl_Run(PositionControlState *state,
                                          const PositionControlInput *input)
{
    PositionControlOutput emptyOutput = {0};
    int64_t positionCounts;
    int64_t errorCounts;
    float errorFloat;
    float proportional;
    float candidateIntegrator;
    float requested;
    float speedClamped;
    float limited;
    bool speedLimited;
    bool accelerationLimited;
    bool insideTolerance;
    bool stopQualified;
    bool inhibitIntegrator;

    if (state == NULL)
    {
        return emptyOutput;
    }
    if ((input == NULL) ||
        ((input != NULL) &&
         !PositionControl_IsFinite(input->measuredMechanicalRadPerSec)))
    {
        PositionControl_Disable(state);
        state->output.diagnosticFlags |= POSITION_CONTROL_DIAG_NUMERIC;
        return state->output;
    }

    state->output.measuredMechanicalRadPerSec =
        input->measuredMechanicalRadPerSec;
    if (!state->enabled)
    {
        PositionControl_Disable(state);
        state->output.measuredMechanicalRadPerSec =
            input->measuredMechanicalRadPerSec;
        return state->output;
    }
    if (!input->controlPermitted || !input->encoderValid ||
        !state->encoderValid || !state->encoderInitialized)
    {
        bool permissionDenied = !input->controlPermitted;
        if (!input->encoderValid)
        {
            state->encoderValid = false;
            state->encoderInitialized = false;
        }
        PositionControl_Disable(state);
        if (permissionDenied)
        {
            state->output.diagnosticFlags |= POSITION_CONTROL_DIAG_PERMISSION;
        }
        return state->output;
    }

    state->output.valid = true;
    state->output.enabled = true;
    PositionControl_UpdatePositionOutput(state);
    if (!state->targetArmed)
    {
        PositionControl_ClearMotionState(state);
        state->output.valid = true;
        state->output.enabled = true;
        PositionControl_UpdatePositionOutput(state);
        return state->output;
    }

    positionCounts = PositionControl_GetRelativeCounts(state);
    errorCounts = PositionControl_SubtractCounts(state->targetPositionCounts,
                                                 positionCounts);
    errorFloat = (float)errorCounts;
    insideTolerance =
        PositionControl_AbsCounts(errorCounts) <=
        state->tuning.positionToleranceCounts;
    if (insideTolerance)
    {
        state->integratorMechanicalRadPerSec = 0.0F;
    }

    proportional = state->tuning.kpMechanicalRadPerSecPerCount * errorFloat;
    candidateIntegrator = state->integratorMechanicalRadPerSec;
    if (!insideTolerance &&
        (state->tuning.kiMechanicalRadPerSecPerCountSec > 0.0F))
    {
        candidateIntegrator +=
            state->tuning.kiMechanicalRadPerSecPerCountSec * errorFloat *
            state->config.positionLoopSampleSec;
        candidateIntegrator = PositionControl_ClampFloat(
            candidateIntegrator,
            -state->tuning.integratorLimitMechanicalRadPerSec,
            state->tuning.integratorLimitMechanicalRadPerSec);
    }

    requested = insideTolerance ? 0.0F :
        (proportional + candidateIntegrator);
    if (!PositionControl_IsFinite(requested))
    {
        PositionControl_Disable(state);
        state->output.diagnosticFlags |= POSITION_CONTROL_DIAG_NUMERIC;
        return state->output;
    }
    speedClamped = PositionControl_ClampFloat(
        requested,
        -state->tuning.maxMechanicalRadPerSec,
        state->tuning.maxMechanicalRadPerSec);
    speedLimited = (speedClamped != requested);
    limited = PositionControl_ApplyRateLimit(state, speedClamped,
                                             &accelerationLimited);

    inhibitIntegrator =
        ((errorCounts > 0) && (limited < requested)) ||
        ((errorCounts < 0) && (limited > requested));
    if (!inhibitIntegrator)
    {
        state->integratorMechanicalRadPerSec = candidateIntegrator;
    }
    else if (candidateIntegrator != state->integratorMechanicalRadPerSec)
    {
        requested = insideTolerance ? 0.0F :
            (proportional + state->integratorMechanicalRadPerSec);
        speedClamped = PositionControl_ClampFloat(
            requested,
            -state->tuning.maxMechanicalRadPerSec,
            state->tuning.maxMechanicalRadPerSec);
        speedLimited = (speedClamped != requested);
        limited = PositionControl_ApplyRateLimit(state, speedClamped,
                                                 &accelerationLimited);
    }

    state->previousLimitedMechanicalRadPerSec = limited;
    stopQualified = insideTolerance &&
        (PositionControl_AbsFloat(input->measuredMechanicalRadPerSec) <=
         state->tuning.stoppedMechanicalRadPerSec);
    if (stopQualified)
    {
        if (state->atTargetCounter < state->atTargetDwellTicks)
        {
            ++state->atTargetCounter;
        }
    }
    else
    {
        state->atTargetCounter = 0U;
    }

    state->output.valid = true;
    state->output.enabled = true;
    state->output.atTarget =
        state->atTargetCounter >= state->atTargetDwellTicks;
    state->output.requestedMechanicalRadPerSec = requested;
    state->output.limitedMechanicalRadPerSec = limited;
    state->output.electricalRadPerSec = limited * state->config.polePairs;
    state->output.speedLimited = speedLimited;
    state->output.accelerationLimited = accelerationLimited;
    state->output.integratorMechanicalRadPerSec =
        state->integratorMechanicalRadPerSec;
    state->output.measuredMechanicalRadPerSec =
        input->measuredMechanicalRadPerSec;
    PositionControl_UpdatePositionOutput(state);
    return state->output;
}

const PositionControlOutput *PositionControl_GetOutput(
    const PositionControlState *state)
{
    return (state == NULL) ? NULL : &state->output;
}
