/******************************************************************************
 * CUSTOM PROJECT TEST - NOT PART OF THE ORIGINAL NXP FIRMWARE
 *
 * Host/target-independent behavioral tests for the custom relative multi-turn
 * position controller. These tests do not exercise NXP hardware drivers or claim
 * motor-bench validation.
 ******************************************************************************/

#include "position_control.h"

#include <math.h>
#include <stdio.h>

typedef char position_control_requires_64_bit_counts[(sizeof(int64_t) == 8U) ? 1 : -1];

static int s_failures;
static int s_checks;

#define CHECK(condition)                                                        \
    do                                                                          \
    {                                                                           \
        ++s_checks;                                                             \
        if (!(condition))                                                       \
        {                                                                       \
            ++s_failures;                                                       \
            (void)printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
        }                                                                       \
    } while (0)

#define CHECK_NEAR(actual, expected, tolerance) \
    CHECK(fabsf((actual) - (expected)) <= (tolerance))

static PositionControlConfig TestConfig(void)
{
    PositionControlConfig config = {0};
    config.countsPerMechanicalRev = 512U;
    config.polePairs = 7.0F;
    config.encoderDirection = 1;
    config.encoderSampleSec = 0.0001F;
    config.positionLoopSampleSec = 0.01F;
    config.safeMaxMechanicalRadPerSec = 100.0F;
    return config;
}

static PositionControlTuning TestTuning(void)
{
    PositionControlTuning tuning = {0};
    tuning.kpMechanicalRadPerSecPerCount = 0.1F;
    tuning.kiMechanicalRadPerSecPerCountSec = 0.0F;
    tuning.integratorLimitMechanicalRadPerSec = 10.0F;
    tuning.maxMechanicalRadPerSec = 20.0F;
    tuning.maxAccelMechanicalRadPerSec2 = 1000.0F;
    tuning.maxDecelMechanicalRadPerSec2 = 1000.0F;
    tuning.positionToleranceCounts = 1;
    tuning.stoppedMechanicalRadPerSec = 0.1F;
    tuning.atTargetDwellSec = 0.02F;
    return tuning;
}

static PositionControlInput PermittedInput(void)
{
    PositionControlInput input = {0};
    input.encoderValid = true;
    input.controlPermitted = true;
    return input;
}

static void InitTunedState(PositionControlState *state)
{
    PositionControlConfig config = TestConfig();
    PositionControlTuning tuning = TestTuning();
    CHECK(PositionControl_Init(state, &config));
    CHECK(PositionControl_ApplyTuning(state, &tuning));
}

static void InitEnabledState(PositionControlState *state)
{
    InitTunedState(state);
    CHECK(PositionControl_UpdateEncoder(state, 100U, true));
    CHECK(PositionControl_Enable(state, true));
}

static void Test_DefaultStateAndApi(void)
{
    PositionControlConfig config = TestConfig();
    PositionControlTuning tuning = TestTuning();
    PositionControlInput input = {0};
    PositionControlState state = {0};
    PositionControlOutput output;

    CHECK(PositionControl_Init(&state, &config));
    PositionControl_Reset(&state);
    CHECK(!PositionControl_UpdateEncoder(&state, 0U, false));
    CHECK(!PositionControl_Enable(&state, false));
    PositionControl_Disable(&state);
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(!PositionControl_SetTargetCounts(&state, 0));
    CHECK(!PositionControl_SetTargetDegrees(&state, 0.0F));
    PositionControl_SetSoftwareZero(&state);
    output = PositionControl_Run(&state, &input);
    CHECK(PositionControl_GetOutput(&state) != NULL);
    CHECK(!output.enabled);
    CHECK(!output.valid);
    CHECK(output.limitedMechanicalRadPerSec == 0.0F);
    CHECK(state.integratorMechanicalRadPerSec == 0.0F);
    CHECK(!state.targetArmed);
}

static void Test_ConfigValidation(void)
{
    PositionControlState state = {0};
    PositionControlConfig config = TestConfig();

    CHECK(!PositionControl_Init(NULL, &config));
    CHECK(!PositionControl_Init(&state, NULL));
    config.countsPerMechanicalRev = 2U;
    CHECK(!PositionControl_Init(&state, &config));
    config = TestConfig();
    config.encoderDirection = 0;
    CHECK(!PositionControl_Init(&state, &config));
    config = TestConfig();
    config.encoderSampleSec = 0.0F;
    CHECK(!PositionControl_Init(&state, &config));
    config = TestConfig();
    config.positionLoopSampleSec = NAN;
    CHECK(!PositionControl_Init(&state, &config));
    config = TestConfig();
    config.polePairs = INFINITY;
    CHECK(!PositionControl_Init(&state, &config));
    config = TestConfig();
    config.polePairs = 7.5F;
    CHECK(!PositionControl_Init(&state, &config));
}

static void Test_UnwrapNormalAndWrap(void)
{
    PositionControlState state = {0};
    PositionControlConfig config = TestConfig();
    uint16_t count;

    config.safeMaxMechanicalRadPerSec = 1000.0F;
    CHECK(PositionControl_Init(&state, &config));
    CHECK(PositionControl_UpdateEncoder(&state, 123U, true));
    CHECK(state.accumulatedPositionCounts == 0);
    CHECK(PositionControl_UpdateEncoder(&state, 124U, true));
    CHECK(state.accumulatedPositionCounts == 1);
    CHECK(PositionControl_UpdateEncoder(&state, 123U, true));
    CHECK(state.accumulatedPositionCounts == 0);

    PositionControl_Reset(&state);
    CHECK(PositionControl_UpdateEncoder(&state, 511U, true));
    CHECK(PositionControl_UpdateEncoder(&state, 0U, true));
    CHECK(state.accumulatedPositionCounts == 1);

    PositionControl_Reset(&state);
    CHECK(PositionControl_UpdateEncoder(&state, 0U, true));
    CHECK(PositionControl_UpdateEncoder(&state, 511U, true));
    CHECK(state.accumulatedPositionCounts == -1);

    PositionControl_Reset(&state);
    CHECK(PositionControl_UpdateEncoder(&state, 0U, true));
    for (count = 1U; count < 512U; ++count)
    {
        CHECK(PositionControl_UpdateEncoder(&state, count, true));
    }
    CHECK(PositionControl_UpdateEncoder(&state, 0U, true));
    CHECK(state.accumulatedPositionCounts == 512);
    CHECK_NEAR(PositionControl_GetOutput(&state)->multiTurnPositionDegrees,
               360.0F, 0.001F);
}

static void Test_UnwrapDirectionInvalidAndReset(void)
{
    PositionControlState state = {0};
    PositionControlConfig config = TestConfig();

    config.encoderDirection = -1;
    config.safeMaxMechanicalRadPerSec = 1000.0F;
    CHECK(PositionControl_Init(&state, &config));
    CHECK(PositionControl_UpdateEncoder(&state, 10U, true));
    CHECK(PositionControl_UpdateEncoder(&state, 11U, true));
    CHECK(state.accumulatedPositionCounts == -1);

    PositionControl_Reset(&state);
    CHECK(PositionControl_UpdateEncoder(&state, 400U, true));
    CHECK(state.accumulatedPositionCounts == 0);
    CHECK(!PositionControl_UpdateEncoder(&state, 512U, true));
    CHECK((state.encoderDiagnosticFlags & POSITION_CONTROL_DIAG_ENCODER_RANGE) != 0U);
    CHECK(!state.encoderInitialized);
    CHECK(!PositionControl_UpdateEncoder(&state, 0U, false));
}

static void Test_UnwrapRejectsAmbiguousAndImpossibleDelta(void)
{
    PositionControlState state = {0};
    PositionControlConfig config = TestConfig();

    config.safeMaxMechanicalRadPerSec = 1000.0F;
    CHECK(PositionControl_Init(&state, &config));
    CHECK(PositionControl_UpdateEncoder(&state, 0U, true));
    CHECK(!PositionControl_UpdateEncoder(&state, 256U, true));
    CHECK((state.encoderDiagnosticFlags & POSITION_CONTROL_DIAG_ENCODER_HALF_TURN) != 0U);

    config.safeMaxMechanicalRadPerSec = 10.0F;
    CHECK(PositionControl_Init(&state, &config));
    CHECK(PositionControl_UpdateEncoder(&state, 0U, true));
    CHECK(!PositionControl_UpdateEncoder(&state, 3U, true));
    CHECK((state.encoderDiagnosticFlags & POSITION_CONTROL_DIAG_ENCODER_PHYSICAL_DELTA) != 0U);
    CHECK(state.accumulatedPositionCounts == 0);
}

static void Test_EnableIsBumplessAndRequiresValidState(void)
{
    PositionControlState state = {0};
    PositionControlConfig config = TestConfig();
    PositionControlTuning tuning = TestTuning();
    PositionControlInput input = PermittedInput();
    PositionControlOutput output;

    CHECK(PositionControl_Init(&state, &config));
    CHECK(!PositionControl_Enable(&state, true));
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(!PositionControl_Enable(&state, true));
    CHECK(PositionControl_UpdateEncoder(&state, 100U, true));
    CHECK(!PositionControl_Enable(&state, false));
    CHECK(PositionControl_Enable(&state, true));
    CHECK(state.targetPositionCounts == 0);
    CHECK(!state.targetArmed);
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(!state.targetArmed);
    output = PositionControl_Run(&state, &input);
    CHECK(output.valid);
    CHECK(output.enabled);
    CHECK(output.limitedMechanicalRadPerSec == 0.0F);
}

static void Test_POnlyPositiveNegativeAndElectricalConversion(void)
{
    PositionControlState state = {0};
    PositionControlInput input = PermittedInput();
    PositionControlOutput output;

    InitEnabledState(&state);
    CHECK(PositionControl_SetTargetCounts(&state, 10));
    output = PositionControl_Run(&state, &input);
    CHECK_NEAR(output.requestedMechanicalRadPerSec, 1.0F, 0.0001F);
    CHECK_NEAR(output.limitedMechanicalRadPerSec, 1.0F, 0.0001F);
    CHECK_NEAR(output.electricalRadPerSec, 7.0F, 0.0001F);

    PositionControl_Disable(&state);
    CHECK(PositionControl_Enable(&state, true));
    CHECK(PositionControl_SetTargetCounts(&state, -10));
    output = PositionControl_Run(&state, &input);
    CHECK_NEAR(output.limitedMechanicalRadPerSec, -1.0F, 0.0001F);
}

static void Test_IntegralClampAntiWindupAndDeadband(void)
{
    PositionControlState state = {0};
    PositionControlTuning tuning = TestTuning();
    PositionControlInput input = PermittedInput();

    InitEnabledState(&state);
    tuning.kpMechanicalRadPerSecPerCount = 0.0F;
    tuning.kiMechanicalRadPerSecPerCountSec = 1.0F;
    tuning.integratorLimitMechanicalRadPerSec = 0.15F;
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(PositionControl_SetTargetCounts(&state, 10));
    (void)PositionControl_Run(&state, &input);
    CHECK_NEAR(state.integratorMechanicalRadPerSec, 0.1F, 0.0001F);
    (void)PositionControl_Run(&state, &input);
    CHECK_NEAR(state.integratorMechanicalRadPerSec, 0.15F, 0.0001F);

    tuning.kpMechanicalRadPerSecPerCount = 10.0F;
    tuning.maxMechanicalRadPerSec = 1.0F;
    tuning.integratorLimitMechanicalRadPerSec = 10.0F;
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    state.integratorMechanicalRadPerSec = 0.0F;
    (void)PositionControl_Run(&state, &input);
    CHECK_NEAR(state.integratorMechanicalRadPerSec, 0.0F, 0.0001F);

    CHECK(PositionControl_SetTargetCounts(&state, 0));
    (void)PositionControl_Run(&state, &input);
    CHECK_NEAR(state.integratorMechanicalRadPerSec, 0.0F, 0.0001F);
}

static void Test_SpeedAccelerationAndDecelerationLimits(void)
{
    PositionControlState state = {0};
    PositionControlTuning tuning = TestTuning();
    PositionControlInput input = PermittedInput();
    PositionControlOutput output;

    InitEnabledState(&state);
    tuning.kpMechanicalRadPerSecPerCount = 1.0F;
    tuning.maxAccelMechanicalRadPerSec2 = 100000.0F;
    tuning.maxDecelMechanicalRadPerSec2 = 100000.0F;
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(PositionControl_SetTargetCounts(&state, 100));
    output = PositionControl_Run(&state, &input);
    CHECK_NEAR(output.requestedMechanicalRadPerSec, 100.0F, 0.001F);
    CHECK_NEAR(output.limitedMechanicalRadPerSec, 20.0F, 0.001F);
    CHECK(output.speedLimited);

    PositionControl_Disable(&state);
    CHECK(PositionControl_Enable(&state, true));
    tuning.maxMechanicalRadPerSec = 100.0F;
    tuning.maxAccelMechanicalRadPerSec2 = 10.0F;
    tuning.maxDecelMechanicalRadPerSec2 = 10.0F;
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(PositionControl_SetTargetCounts(&state, 100));
    output = PositionControl_Run(&state, &input);
    CHECK_NEAR(output.limitedMechanicalRadPerSec, 0.1F, 0.0001F);
    CHECK(output.accelerationLimited);

    tuning.maxAccelMechanicalRadPerSec2 = 100000.0F;
    tuning.maxDecelMechanicalRadPerSec2 = 10.0F;
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(PositionControl_SetTargetCounts(&state, 10));
    output = PositionControl_Run(&state, &input);
    CHECK_NEAR(output.limitedMechanicalRadPerSec, 10.0F, 0.001F);
    CHECK(PositionControl_SetTargetCounts(&state, 0));
    output = PositionControl_Run(&state, &input);
    CHECK_NEAR(output.limitedMechanicalRadPerSec, 9.9F, 0.001F);
    CHECK(output.accelerationLimited);
}

static void Test_SoftLimitsAndAtomicTuning(void)
{
    PositionControlState state = {0};
    PositionControlTuning tuning = TestTuning();
    PositionControlTuning invalid;

    InitEnabledState(&state);
    tuning.negativeSoftLimitEnabled = true;
    tuning.negativeSoftLimitCounts = -20;
    tuning.positiveSoftLimitEnabled = true;
    tuning.positiveSoftLimitCounts = 20;
    CHECK(PositionControl_ApplyTuning(&state, &tuning));
    CHECK(PositionControl_SetTargetCounts(&state, 30));
    CHECK(state.targetPositionCounts == 20);
    CHECK(state.targetClamped);
    CHECK(PositionControl_SetTargetCounts(&state, -30));
    CHECK(state.targetPositionCounts == -20);

    invalid = tuning;
    invalid.maxMechanicalRadPerSec = -1.0F;
    CHECK(!PositionControl_ApplyTuning(&state, &invalid));
    CHECK_NEAR(state.tuning.maxMechanicalRadPerSec, 20.0F, 0.0001F);
    invalid = tuning;
    invalid.positiveSoftLimitCounts = -30;
    CHECK(!PositionControl_ApplyTuning(&state, &invalid));
    CHECK(state.tuning.positiveSoftLimitCounts == 20);
}

static void Test_AtTargetDwell(void)
{
    PositionControlState state = {0};
    PositionControlInput input = PermittedInput();
    PositionControlOutput output;

    InitEnabledState(&state);
    CHECK(PositionControl_SetTargetCounts(&state, 0));
    output = PositionControl_Run(&state, &input);
    CHECK(!output.atTarget);
    output = PositionControl_Run(&state, &input);
    CHECK(output.atTarget);
    input.measuredMechanicalRadPerSec = 1.0F;
    output = PositionControl_Run(&state, &input);
    CHECK(!output.atTarget);
}

static void Test_SoftwareZeroAndDegrees(void)
{
    PositionControlState state = {0};
    PositionControlInput input = PermittedInput();
    PositionControlOutput output;
    uint16_t count;

    InitEnabledState(&state);
    for (count = 101U; count <= 110U; ++count)
    {
        CHECK(PositionControl_UpdateEncoder(&state, count, true));
    }
    CHECK(PositionControl_SetTargetCounts(&state, 20));
    output = PositionControl_Run(&state, &input);
    CHECK(output.multiTurnPositionCounts == 10);
    CHECK(output.positionErrorCounts == 10);
    PositionControl_SetSoftwareZero(&state);
    output = PositionControl_Run(&state, &input);
    CHECK(output.multiTurnPositionCounts == 0);
    CHECK(output.targetPositionCounts == 10);
    CHECK(output.positionErrorCounts == 10);
    CHECK_NEAR(output.multiTurnPositionDegrees, 0.0F, 0.0001F);
}

static void Test_InvalidInputPermissionDisableAndReset(void)
{
    PositionControlState state = {0};
    PositionControlInput input = PermittedInput();
    PositionControlOutput output;

    InitEnabledState(&state);
    CHECK(PositionControl_SetTargetCounts(&state, 10));
    input.encoderValid = false;
    output = PositionControl_Run(&state, &input);
    CHECK(!output.valid);
    CHECK(!output.enabled);
    CHECK(output.limitedMechanicalRadPerSec == 0.0F);

    CHECK(PositionControl_UpdateEncoder(&state, 100U, true));
    CHECK(PositionControl_Enable(&state, true));
    input = PermittedInput();
    input.controlPermitted = false;
    output = PositionControl_Run(&state, &input);
    CHECK(!output.enabled);
    CHECK((output.diagnosticFlags & POSITION_CONTROL_DIAG_PERMISSION) != 0U);

    CHECK(PositionControl_Enable(&state, true));
    input = PermittedInput();
    input.measuredMechanicalRadPerSec = NAN;
    output = PositionControl_Run(&state, &input);
    CHECK(!output.valid);
    CHECK((output.diagnosticFlags & POSITION_CONTROL_DIAG_NUMERIC) != 0U);

    PositionControl_Reset(&state);
    CHECK(state.configValid);
    CHECK(state.tuningValid);
    CHECK(!state.encoderInitialized);
    CHECK(!state.enabled);
    CHECK(state.accumulatedPositionCounts == 0);
}

int main(void)
{
    Test_DefaultStateAndApi();
    Test_ConfigValidation();
    Test_UnwrapNormalAndWrap();
    Test_UnwrapDirectionInvalidAndReset();
    Test_UnwrapRejectsAmbiguousAndImpossibleDelta();
    Test_EnableIsBumplessAndRequiresValidState();
    Test_POnlyPositiveNegativeAndElectricalConversion();
    Test_IntegralClampAntiWindupAndDeadband();
    Test_SpeedAccelerationAndDecelerationLimits();
    Test_SoftLimitsAndAtomicTuning();
    Test_AtTargetDwell();
    Test_SoftwareZeroAndDegrees();
    Test_InvalidInputPermissionDisableAndReset();

    if (s_failures != 0)
    {
        (void)printf("FAIL: %d of %d checks\n", s_failures, s_checks);
        return 1;
    }

    (void)printf("PASS: %d checks\n", s_checks);
    return 0;
}
