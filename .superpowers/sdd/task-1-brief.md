# Task 1: Define the Hardware-Independent Position-Control Contract

## Global constraints

- The current working tree and `src/config/PMSM_appconfig.h` dated 17 July 2026 are authoritative.
- Do not modify MCAT tuning, motor-control loops, observer, state machine, PWM/ADC, or faults.
- The isolated module must have no hardware or application-global dependency.
- Use C99, no dynamic allocation or recursion.
- Position control is disabled by default and cannot move on enable.
- Do not create a branch or commit. Preserve all pre-existing user changes.

## Files

- Create `src/position_control.h`.
- Create `tests/position_control/test_position_control.c`.
- Create `tests/position_control/run_tests.ps1`.

## Required interface

Declare `PositionControl_Init`, `PositionControl_Reset`, `PositionControl_UpdateEncoder`, `PositionControl_Enable`, `PositionControl_Disable`, `PositionControl_ApplyTuning`, `PositionControl_SetTargetCounts`, `PositionControl_SetTargetDegrees`, `PositionControl_SetSoftwareZero`, `PositionControl_Run`, and `PositionControl_GetOutput`.

Define complete public configuration, tuning, input, state, output, tuning-result, and diagnostic types using only standard C headers/types. Use explicit units in member names: counts, mechanical degrees, mechanical rad/s, electrical rad/s, mechanical rad/s squared, seconds, and Kp/Ki per-count units. State must support signed 64-bit accumulation, prior wrapped count, software-zero offset, target, integrator, rate limiter, dwell, active tuning, output, enable/valid/armed flags, and diagnostics.

## Test-first steps

1. Read `C:/Users/MachaDev/.codex/plugins/cache/openai-curated-remote/superpowers/6.1.1/skills/test-driven-development/SKILL.md` fully and follow it.
2. Write a small C assertion harness that instantiates every public type, calls every public function, and checks reset/default state is disabled, invalid for ownership, zero-output, not motion-armed, and uses a 64-bit accumulator.
3. Create `run_tests.ps1` that searches for `gcc`, `clang`, then an explicitly configured compiler; builds `src/position_control.c` plus the test with C99 and strict warnings; writes only under `tests/position_control/build`; returns nonzero for no compiler or failure.
4. Record RED evidence. The current machine may legitimately report `NO_HOST_C_COMPILER`; do not fake a passing result.
5. Create the complete header/API contract. Because Task 2 creates `position_control.c`, Task 1 may use a minimal test-only stub implementation only if needed to make API contract tests link; prefer compile-only checks and do not implement Task 2 behavior early.
6. Re-run and report exact results.

## Report

Write `.superpowers/sdd/task-1-report.md` with files changed, RED/GREEN commands and outputs, self-review, and concerns. Return status only; do not commit.
