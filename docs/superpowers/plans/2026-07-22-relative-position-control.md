# Relative Mechanical Position Control Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add a default-disabled, relative multi-turn mechanical position outer loop that safely commands the existing tuned encoder speed loop.

**Architecture:** Expose one corrected wrapped-count value from the encoder module, unwrap it inside a hardware-independent `position_control` module at 10 kHz, and run a bounded P/optional-PI position calculation at the existing 1 kHz slow-loop boundary. The application layer alone validates run/mode/sensor permission and arbitrates ownership of the existing electrical-rad/s speed reference.

**Tech Stack:** C99, NXP S32M276, S32 Design Studio GCC 10.2, AMMCLIB v1.1.44, FreeMASTER ELF symbols, a freestanding C host-test executable.

## Global Constraints

- Treat the current working tree and `src/config/PMSM_appconfig.h` dated 17 July 2026 as the only firmware/configuration authority.
- Do not modify MCAT-generated tuning, current/speed controllers, encoder observer, electrical angle, PWM, ADC, transformations, field weakening, state transitions, or hardware-fault behavior.
- Position is relative; restart or completion of existing alignment resets its origin.
- Position control is disabled by default and cannot move on enable; only a later target command arms movement.
- The isolated module has no eMIOS, ADC, PWM, AMMCLIB-loop-internal, or application-global dependencies.
- Use no dynamic allocation, recursion, direct position-to-Iq command, or direct current/voltage/PWM command.
- Preserve the original speed-command path exactly while position ownership is inactive, except for one deterministic zero-reference boundary when relinquishing ownership.
- Do not create a branch, commit, push, or pull request; the user explicitly prohibited those actions.
- Do not hand-edit MCAT output or generated Debug_FLASH makefiles. Refresh/regenerate the build through S32 Design Studio if source discovery requires it.

## File Map

- Create `src/position_control.h`: public types, units, diagnostics, and narrow API.
- Create `src/position_control.c`: validation, unwrapping, targets/software zero, PI, anti-windup, motion limiting, dwell, and output conversion.
- Modify `src/pospe_sensor.h`: add one corrected wrapped-count output field to `encoderPospe_t`.
- Modify `src/pospe_sensor.c`: populate that field from the existing corrected `Absolut_position` calculation without changing the existing angle/observer path.
- Modify `src/main.c`: instantiate/configure the module, define FreeMASTER staging/command/status globals, call fast/slow APIs, and arbitrate speed-reference ownership.
- Create `tests/position_control/test_position_control.c`: host tests with no target hardware dependency.
- Create `tests/position_control/run_tests.ps1`: locate an available C compiler, compile with strict warnings, and run the test executable.
- Create `docs/position-control-commissioning.md`: low-energy hardware commissioning procedure and validation boundary.

---

### Task 1: Define the Hardware-Independent Position-Control Contract

**Files:**
- Create: `src/position_control.h`
- Create: `tests/position_control/test_position_control.c`
- Create: `tests/position_control/run_tests.ps1`

**Interfaces:**
- Consumes: C99 standard integer, Boolean, and floating-point facilities only.
- Produces: `PositionControl_Init`, `PositionControl_Reset`, `PositionControl_UpdateEncoder`, `PositionControl_Enable`, `PositionControl_Disable`, `PositionControl_ApplyTuning`, `PositionControl_SetTargetCounts`, `PositionControl_SetTargetDegrees`, `PositionControl_SetSoftwareZero`, `PositionControl_Run`, and `PositionControl_GetOutput`.

- [ ] **Step 1: Write compile-time API and default-state tests**

  Define a small assertion harness in `test_position_control.c`, instantiate every public structure, call every public function, and assert that reset state is disabled, invalid for ownership, zero-output, Ki-neutral, and not motion-armed. Add explicit `sizeof(int64_t) == 8` and configuration-field unit checks through compile-time/static assertions supported by C99 typedefs.

- [ ] **Step 2: Add a strict host-test build script**

  `run_tests.ps1` must search, in order, for `gcc`, `clang`, and a configured S32DS-host compiler; compile `src/position_control.c` plus the test file using `-std=c99 -Wall -Wextra -Wpedantic -Werror`; run the executable; and return nonzero if no compiler is available or any assertion fails. It must write only beneath `tests/position_control/build`.

- [ ] **Step 3: Run the test and confirm the expected failure**

  Run:

  ```powershell
  powershell -ExecutionPolicy Bypass -File tests/position_control/run_tests.ps1
  ```

  Expected before implementation: failure because `src/position_control.h`/`.c` API definitions are incomplete, or a clear `NO_HOST_C_COMPILER` result if the environment still has no compiler.

- [ ] **Step 4: Define complete public types and declarations**

  Use `uint16_t`, `uint32_t`, `int32_t`, `int64_t`, `float`, and `bool`. Include explicit unit suffixes such as `countsPerMechanicalRev`, `encoderSampleSec`, `positionLoopSampleSec`, `maxMechanicalRadPerSec`, `maxAccelMechanicalRadPerSec2`, `kpMechanicalRadPerSecPerCount`, and `kiMechanicalRadPerSecPerCountSec`. Define diagnostic bits for configuration, encoder range, ambiguous half-turn, physical delta, permission, and numeric errors.

- [ ] **Step 5: Re-run the compile-only/API test**

  Expected: compilation progresses to link failures for functions not yet implemented, or the same explicit compiler-unavailable result. Review the header to confirm it includes no project/hardware headers.

### Task 2: Implement and Test Count Validation and Multi-turn Unwrapping

**Files:**
- Create: `src/position_control.c`
- Modify: `tests/position_control/test_position_control.c`

**Interfaces:**
- Consumes: `PositionControlConfig`, `PositionControlState`, and `PositionControl_UpdateEncoder` declared in Task 1.
- Produces: validated configuration, initialized wrapped-count tracking, signed 64-bit relative position, physical-delta diagnostics, degrees conversion, and safe reset behavior.

- [ ] **Step 1: Add failing unwrapping tests**

  Add named test functions for arbitrary first count, forward increments, reverse increments, `511 -> 0`, `0 -> 511`, multiple revolutions, invalid count `>= countsPerMechanicalRev`, invalid resolution, exact half-turn ambiguity, reset-first-sample safety, and a wrap-corrected delta exceeding the configured physical ceiling. For 512 counts/revolution, assert `512` accumulated counts equals `360.0F` within a small float tolerance.

- [ ] **Step 2: Run tests and verify behavioral failures**

  Expected: the new assertions fail while the API compiles.

- [ ] **Step 3: Implement initialization, reset, and encoder update**

  Validate finite positive periods, resolution greater than two, positive finite pole pairs/speed ceiling, and a derived plausible delta:

  ```text
  ceil(maxMechanicalRadPerSec * encoderSampleSec
       * countsPerMechanicalRev / (2*pi)) + 1 count margin
  ```

  Cap the physical ceiling below half a revolution. On first valid sample, set `previousWrappedCount` without adding motion. Calculate signed delta, correct across the revolution boundary using arithmetic comparisons, reject exact half-turn and corrected magnitudes over the physical ceiling, then accumulate into `int64_t` only after all checks pass.

- [ ] **Step 4: Run all unwrapping tests**

  Expected: all unwrapping/configuration/reset tests pass with strict warnings.

- [ ] **Step 5: Inspect isolation**

  Run:

  ```powershell
  rg -n "Emios|ADC|PWM|SVM|drvFOC|encoderPospe|cntrState|pos_mode|AMCLIB" src/position_control.*
  ```

  Expected: no matches.

### Task 3: Implement and Test Targets, PI Control, Limits, and Dwell

**Files:**
- Modify: `src/position_control.c`
- Modify: `tests/position_control/test_position_control.c`

**Interfaces:**
- Consumes: valid unwrapped state from Task 2 and tuning/input structures from Task 1.
- Produces: bumpless enable, explicit target arming, software zero, bounded mechanical speed, electrical-rad/s conversion, and complete status flags.

- [ ] **Step 1: Add failing controller tests**

  Add tests for disabled output, rejected enable without permission/encoder initialization, target capture on enable, zero speed immediately after enable, no motion until later target, positive/negative target, exact P-only response, Ki accumulation, integrator clamp, same-direction saturation anti-windup, deadband integrator clear, speed clamp, acceleration limit, deceleration limit, positive/negative soft limits and target-clamped flag, stopped-speed dwell, invalid encoder input, tuning rejection without partial activation, software zero, disable, and reset/fault-equivalent permission loss.

- [ ] **Step 2: Run tests and verify the new assertions fail**

  Expected: failures identify the unimplemented target/controller/limiter behavior.

- [ ] **Step 3: Implement atomic tuning validation**

  Copy the candidate tuning into a local snapshot, reject non-finite values, negative gains/limits/tolerances/dwell, zero integrator limit when Ki is nonzero, inconsistent enabled soft limits, and maximum speed above the immutable configuration ceiling. Assign the active structure only after the full snapshot passes. Initialize factory Ki to `0.0F`.

- [ ] **Step 4: Implement bumpless enable and commands**

  Enable only with permission, valid tuning, initialized valid encoder state, and no active encoder diagnostic. Capture current relative count as target, clear PI/dwell/rate state, output zero, and leave `targetArmed` false. `SetTargetCounts` and `SetTargetDegrees` clamp against soft limits before setting `targetArmed`. `SetSoftwareZero` adjusts an offset so current displayed/control position becomes zero and shifts the active target consistently to prevent motion.

- [ ] **Step 5: Implement P/optional-PI and anti-windup**

  Calculate count error, P term, conditional integral candidate, integrator clamp, speed clamp, and rate limit in that order. Commit the integral candidate only when output is not saturated in the error direction. Clear the integrator while disabled, invalid, inside tolerance, or without permission.

- [ ] **Step 6: Implement acceleration/deceleration and at-target dwell**

  Select acceleration when requested magnitude is increasing and deceleration when it is decreasing or reversing. Limit delta-speed by `limit * positionLoopSampleSec`. Require both position tolerance and stopped mechanical-speed threshold for `ceil(dwellSec / positionLoopSampleSec)` consecutive updates.

- [ ] **Step 7: Run all host tests**

  Expected: every test passes and the test program prints a deterministic total such as `PASS: <count> tests`.

### Task 4: Expose the Existing Corrected Wrapped Encoder Count

**Files:**
- Modify: `src/pospe_sensor.h:45-63`
- Modify: `src/pospe_sensor.c:52-57`
- Modify: `tests/position_control/test_position_control.c`

**Interfaces:**
- Consumes: the already computed corrected wrapped count in `POSPE_GetPospeElEnc()`.
- Produces: `encoderPospe.correctedWrappedMechanicalCount` in `[0, 4 * ENC_PULSES - 1]` for the integration layer.

- [ ] **Step 1: Add a source-contract test/inspection assertion**

  Add a scripted check to the test runner that confirms the public encoder structure contains the named field and `pospe_sensor.c` assigns it from the existing corrected count before observer error calculation.

- [ ] **Step 2: Add the read-only output field**

  Add `uint16_t correctedWrappedMechanicalCount` to `encoderPospe_t`. After the existing `Absolut_position` expression, assign the converted value to that field. Do not alter the expression, counter offsets, observer input/error, speed, or angle code.

- [ ] **Step 3: Initialize the output safely**

  Set the field to zero in `POSPE_ClearPospeElEnc()` so alignment/reset cannot expose stale data.

- [ ] **Step 4: Review the focused diff**

  Run:

  ```powershell
  git diff -- src/pospe_sensor.h src/pospe_sensor.c
  ```

  Expected: one field, one normal-path assignment, and one reset assignment only.

### Task 5: Integrate State Permission, FreeMASTER Handshake, and Speed Ownership

**Files:**
- Modify: `src/main.c:49-61,128-147,356-373,561-564,599-713,1062-1125,1142-1328`
- Modify: `tests/position_control/test_position_control.c`

**Interfaces:**
- Consumes: position-control API from Tasks 1-3 and corrected wrapped count from Task 4.
- Produces: default-disabled application instance, staged FreeMASTER commands, deterministic 10 kHz/1 kHz calls, permission arbitration, and one-boundary zero on ownership release.

- [ ] **Step 1: Add integration-policy tests around a pure permission helper**

  Test a small file-local/pure helper or module-level input policy for all combinations that matter: run + speed control + encoder + encoder1 permits ownership; fault, init, ready, calibration, alignment, other FOC modes, sensorless selection, or non-encoder position mode denies it. Test that disabled mode returns the original reference unchanged and ownership loss requests one zero boundary.

- [ ] **Step 2: Add application-owned instances and FreeMASTER structures**

  Include `position_control.h`; define one controller state plus `volatile` staged-command, command-sequence, and status-mirror globals with stable external symbol names. Keep active controller configuration private to the module. Initialize from `4U * ENC_PULSES`, `MOTOR_PP`, `0.0001F`, `0.001F`, and an existing authoritative speed ceiling converted from electrical to mechanical units; do not duplicate numeric motor constants.

- [ ] **Step 3: Add the fast encoder update**

  Immediately after successful `POSPE_GetPospeElEnc(&encoderPospe)`, call `PositionControl_UpdateEncoder()` with `correctedWrappedMechanicalCount`. Encoder-valid input is true only for a range-valid sample; state/mode permission remains a slow-loop integration decision. Do not perform PI math here.

- [ ] **Step 4: Add deterministic staged-command processing**

  At the 1 kHz boundary, copy volatile staging values into a local nonvolatile snapshot, verify the apply sequence did not change during the copy, validate/apply atomically, and publish success/error status. Process command sequences in priority order: disable/lost permission, apply, software zero, enable, target.

- [ ] **Step 5: Add speed-reference arbitration**

  Preserve the original command value/path whenever position ownership is inactive. While valid enabled ownership is active, assign the returned electrical rad/s immediately before `FocSlowLoop()`. On the active-to-inactive transition, assign zero for exactly one slow-loop call, reset ownership state, and allow the original source on later boundaries. Ensure enabling captures target and produces zero until a later target command.

- [ ] **Step 6: Add reset/disable hooks without changing transitions**

  Reset during initialization and alignment completion. Deny/disable ownership in every non-run state and on existing fault. Do not add events, change `StateTable`, or write any fault bit.

- [ ] **Step 7: Mirror read-only status for FreeMASTER**

  At the slow boundary, copy output/status fields into `g_positionStatus`, including counts, degrees, target, error, raw/limited mechanical rad/s, electrical rad/s, measured mechanical speed, integrator, active limits, enabled/valid/at-target, clamp/limit flags, and apply result.

- [ ] **Step 8: Inspect forbidden-path changes**

  Confirm the diff contains no modifications to `FocFastLoop()` transformations/current/PWM calculations, AMMCLIB gains, fault thresholds, or state transition table.

### Task 6: Build, Verify, and Document Commissioning

**Files:**
- Create: `docs/position-control-commissioning.md`
- Modify only if IDE regeneration requires it: S32 Design Studio generated build metadata

**Interfaces:**
- Consumes: completed implementation and tests.
- Produces: reproducible verification evidence and a hardware commissioning guide without claiming bench validation.

- [ ] **Step 1: Run host tests from a compiler-enabled environment**

  Run `tests/position_control/run_tests.ps1`. Expected: strict-warning compile succeeds and all listed tests pass. If this machine still has no host compiler, record that exact limitation and run the tests using the S32DS GCC executable only if it can produce a runnable Windows host binary; do not misreport unexecuted tests.

- [ ] **Step 2: Refresh and build Debug_FLASH in S32 Design Studio**

  Refresh the project so `src/position_control.c` is included, regenerate managed build files, then build Debug_FLASH with the configured NXP GCC 10.2 toolchain. Expected: zero errors and no new warnings. Do not rely on the checked-in makefile's stale absolute linker-script path.

- [ ] **Step 3: Inspect symbols and map output**

  Confirm the ELF/map contains `g_positionCommandStaged`, `g_positionCommand`, `g_positionStatus`, and position-control functions. Confirm staged/command structures reside in writable RAM and status symbols are discoverable by FreeMASTER.

- [ ] **Step 4: Inspect the complete diff and tuned-file hashes/status**

  Run `git diff --stat`, `git diff -- src`, and `git status --short`. Confirm no changes to `src/config/PMSM_appconfig.h`, MCAT parameter files, generated tuning, fault thresholds, or unrelated code were introduced by this work.

- [ ] **Step 5: Write the commissioning guide**

  Document unloaded setup, emergency power removal, disabled-mode regression, manual wrapped/multi-turn direction checks, exact 512-count revolution check, bumpless enable, Ki `0`, low speed/acceleration, `+5` and `-5` degree moves, monitored position/speed/Iq/DC-bus/saturation variables, gradual Kp tuning, optional small Ki only for stable load error, full-turn/multi-turn tests, and stop/fault/re-enable checks.

- [ ] **Step 6: Report verification levels accurately**

  Separate: compiled, host unit tested, integration inspected/tested without motor, and bench tested. State explicitly that relative position resets after alignment/restart and that absolute homing/index is not implemented.

