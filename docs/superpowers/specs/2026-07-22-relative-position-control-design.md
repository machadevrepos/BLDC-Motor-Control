# Relative Mechanical Position Control Design

## Scope

Add an optional, isolated, relative multi-turn mechanical position controller around the latest tuned encoder-based speed controller. Position control is disabled after reset and alignment. Existing current control, speed control, encoder observer, electrical-angle generation, state machine, PWM, measurement, protection, and hardware-fault behavior remain unchanged when position mode is disabled.

Position is relative within one aligned application run. Firmware restart or completion of the existing alignment sequence resets the multi-turn origin. Software zero changes the relative control/diagnostic coordinate only; it is not absolute homing.

## Authoritative Firmware Findings

- `src/config/PMSM_appconfig.h` is the active MCAT-generated configuration. It defines seven pole pairs, 128 encoder lines, 512 quadrature counts per mechanical revolution, a 100 us current/encoder period, and a 1 ms speed-loop period.
- `Bctu_FIFO1_WatermarkNotification()` is the fast control callback. It acquires measurements, calls `POSPE_GetPospeElEnc()`, performs fault detection, dispatches the application state, and calls the FreeMASTER recorder.
- `StateRun()` calls `FocSlowLoop()` every `SPEED_LOOP_CNTR == 10` fast callbacks, then calls `FocFastLoop()` on every callback.
- `encoderPospe.wRotMec.raw` is mechanical rad/s. `POSPE_GetPospeElEnc()` multiplies it by `MOTOR_PP` to produce electrical rad/s. `drvFOC.pospeControl.wRotElReq` and `wRotEl` are therefore electrical rad/s at the `AMCLIB_FWSpeedLoop()` boundary.
- Encoder direction is formed by subtracting the corrected CCW edge count from the corrected CW edge count. Alignment captures CW and CCW counter offsets after the existing encoder/observer reset.
- The corrected wrapped mechanical count is currently computed inside `pospe_sensor.c` but is not exposed through a narrow read-only interface.
- The application sequence is init, ready, calibration, alignment, and run. Stop returns the application through initialization. Position ownership is permitted only in run, speed control, encoder sensor, and encoder position mode.
- FreeMASTER uses the ELF symbol table and read/write memory access. TSA is disabled. Global RAM command, staging, and status structures can therefore be accessed through normal Variable Watch and Recorder operation.

The existing encoder function always returns success and there is no separate RS-422 receiver-valid input. Position-output validity will use the existing state/mode permissions, wrapped-count range checks, initialized unwrapping state, and plausible sample-to-sample count movement. This does not add or modify a hardware fault.

## Architecture

Create `src/position_control.h` and `src/position_control.c`. The module has no hardware access and no dependency on application globals or AMMCLIB current/speed controller internals.

The existing encoder module exposes its already corrected wrapped mechanical count through one read-only structure field or accessor. Its hardware reads, direction calculation, offsets, observer, speed calculation, mechanical/electrical angles, and FOC behavior are otherwise unchanged.

The fast callback passes the corrected wrapped count into `PositionControl_UpdateEncoder()` immediately after `POSPE_GetPospeElEnc()`. This function performs validation and multi-turn unwrapping only; it does not run the position PI calculation.

At the existing 1 kHz slow-loop boundary, the application processes staged FreeMASTER commands, calls `PositionControl_Run()`, and arbitrates speed-reference ownership. The controller produces mechanical rad/s internally and converts its bounded output to electrical rad/s by multiplying by the configured pole-pair count copied from the authoritative firmware configuration.

The application assigns the returned electrical rad/s value to `drvFOC.pospeControl.wRotElReq` only while the position output is valid, enabled, and application permission remains true. Otherwise the original speed-command path executes unchanged.

## Public Interface

The exact type prefixes may be adjusted to match repository conventions, while preserving this narrow API:

```c
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
```

`PositionControlConfig` contains encoder counts/revolution, pole-pair count, encoder direction, encoder sample period, position-loop sample period, the absolute safe ceiling for position-mode mechanical speed, and a derived maximum plausible encoder delta per fast sample. The delta ceiling is calculated once from the safe mechanical-speed ceiling, encoder resolution, and encoder sample period, with only a documented small quantization margin.

`PositionControlTuning` contains Kp, Ki, integrator limit, maximum position-mode speed, acceleration and deceleration limits, position tolerance, stopped-speed threshold, at-target dwell time, and optional positive/negative soft limits.

`PositionControlInput` contains measured mechanical speed, encoder-valid status, and application-level permission.

`PositionControlState` contains active configuration/tuning, previous wrapped count, initialization state, signed 64-bit accumulated count, software-zero offset, target, integrator, rate-limiter state, dwell counter, command-armed state, output, and diagnostics.

`PositionControlOutput` contains validity, enabled/encoder-valid/at-target flags, raw and limited mechanical speed, converted electrical speed, multi-turn position counts and degrees, target, error, integrator state, target/speed/acceleration limiting flags, tuning result, and diagnostic flags.

## Units

- Wrapped and multi-turn position: encoder quadrature counts.
- Diagnostic and command position: mechanical degrees, converted using configured counts/revolution.
- Internal requested/limited speed: mechanical rad/s.
- Existing speed-loop boundary: electrical rad/s.
- Acceleration and deceleration: mechanical rad/s squared.
- Kp: mechanical rad/s per count.
- Ki: mechanical rad/s per count-second.
- Sample periods and dwell input: seconds; dwell is converted once to deterministic position-loop ticks.

## Multi-turn Unwrapping

The first valid wrapped sample initializes `previousWrappedCount` and produces no accumulated movement. For each later valid sample:

1. Validate that the count is less than configured counts/revolution.
2. Compute signed `delta = current - previous` without unsigned wrap.
3. If `delta` is greater than half a revolution, subtract counts/revolution.
4. If `delta` is less than negative half a revolution, add counts/revolution.
5. Reject an exactly half-revolution movement as ambiguous.
6. Reject the wrap-corrected delta when its magnitude exceeds the configured physical maximum derived from safe mechanical speed and sample time.
7. Add the corrected delta to the signed 64-bit accumulator and update the previous sample.

The algorithm uses arithmetic comparisons and configured resolution, not a power-of-two mask. It handles both directions, including 511 to 0 and 0 to 511 for the active 512-count encoder.

Wrapped samples alone cannot mathematically distinguish every greater-than-half-turn movement from a smaller movement in the opposite direction. The physical delta ceiling resolves this for the configured operating envelope: movement beyond the safe speed capability is rejected even when modulo arithmetic could otherwise alias it. An invalid or ambiguous sample invalidates position output and relinquishes ownership but does not set or modify existing hardware-fault status.

## Controller and Motion Limits

At each valid 1 kHz update:

```text
errorCounts = targetCounts - actualRelativeCounts
rawMechanicalSpeed = Kp * errorCounts + integrator
limitedMechanicalSpeed = speedClampAndRateLimit(rawMechanicalSpeed)
electricalSpeedReference = limitedMechanicalSpeed * polePairs
```

Ki defaults to zero. The integral term is bounded. Integration is suppressed when the output is saturated in the same direction as the error. It is cleared while disabled, invalid, faulted, inside the target deadband, or without ownership permission.

Targets are clamped to enabled soft limits before error calculation, and target clamping is reported. Mechanical speed is clamped to the lesser of the active position-mode limit and the immutable safe ceiling copied during initialization. Independent acceleration/deceleration rate limits are applied using the configured 1 ms period and reported separately.

`atTarget` is asserted only when absolute position error is within tolerance and absolute measured mechanical speed is below the stopped-speed threshold for the full configured dwell period. Leaving either threshold clears the dwell and `atTarget` state.

Configuration validation rejects non-finite values, zero/negative sample periods, invalid encoder resolution or pole pairs, negative gains/limits/tolerances/dwell, inconsistent soft limits, and a requested speed above the configured firmware ceiling. Rejected staged tuning never partially modifies active tuning.

## Enable, Disable, and Ownership

Enable is accepted only in application run state with `speedControl`, encoder sensor selection, `encoder1` position source, initialized and valid encoder unwrapping, valid active tuning, and no impossible-delta diagnostic.

On accepted enable, the controller captures the current relative position as its target, clears the integrator/dwell/rate limiter, outputs zero speed, and disarms movement. A later explicit set-target command arms motion.

Disable or loss of permission immediately relinquishes speed-reference ownership, clears the integrator and trajectory state, disarms movement, and produces a defined zero/invalid position output. At the ownership transition, the integration layer writes a zero electrical-speed reference for one deterministic slow-loop boundary before allowing the original command source to resume; this prevents a stale position-generated reference from surviving disable. Stop, fault, calibration, alignment, shutdown, mode change, sensor change, and encoder invalidity all remove permission. Completion of the existing alignment sequence resets the relative accumulator and software-zero coordinate.

The application layer alone inspects application globals and decides ownership. The isolated module never writes `drvFOC.pospeControl.wRotElReq`.

## FreeMASTER Contract

Expose three clearly named global RAM structures:

- `g_positionCommandStaged`: writable target/tuning/motion-limit/tolerance/dwell/soft-limit staging values.
- `g_positionCommand`: writable apply, enable, disable, set-target, and set-software-zero command counters or flags.
- `g_positionStatus`: read-only diagnostic mirror containing actual/target/error position, speed requests, converted speed reference, measured speed, integrator, active limits, validity, enable, at-target, limiting flags, and apply result/error code.

FreeMASTER writes the complete staging structure and changes the apply command last. At a 1 kHz boundary, the integration layer copies a stable snapshot, validates it, and activates all values together or rejects the entire update.

Command priority is disable/loss of permission, apply tuning, software zero, enable, then set target. This ensures a simultaneous stop cannot be overridden by another command.

Active controller configuration is not directly writable from FreeMASTER. Position mode and Ki are disabled by default.

## Minimal Integration Sites

- Application initialization/`MCAT_Init()` vicinity: initialize position configuration from authoritative macros and conservative position-only defaults. Do not modify generated configuration.
- Immediately after `POSPE_GetPospeElEnc()` in the BCTU callback: pass the exposed corrected wrapped count to the unwrapping update.
- Existing `SPEED_LOOP_CNTR` boundary in `StateRun()`: process commands, calculate the outer position loop, arbitrate ownership, then call the existing slow loop.
- Initialization, alignment completion, and any non-permitted application state: reset or disable position ownership as defined above.

Edits outside the two new module files remain minimal and additive.

## Testing

Host-side tests will cover normal forward/reverse unwrapping, both wrap directions, multiple revolutions, arbitrary first sample, invalid resolution/count, and ambiguous/impossible deltas.

Controller tests will cover disabled output, bumpless enable and target capture, explicit target arming, positive/negative targets, P-only calculation, integral accumulation/clamp/anti-windup, deadband, speed and acceleration/deceleration limits, both soft limits, dwell behavior, invalid encoder/tuning, software zero, reset, and permission/fault behavior.

Integration-focused tests or inspection will verify that the original speed path remains active while position mode is disabled, ownership is granted only under the permitted run/mode/sensor conditions, and no current, voltage, PWM, electrical-angle, observer, alignment, or fault calculations are changed.

Verification will include host tests, the available Debug_FLASH build without new warnings, and a final diff inspection. Compilation and host/integration testing will be distinguished from motor bench testing.

## Commissioning Boundary

No hardware operation is performed or claimed by this change. The commissioning guide will require an unloaded/low-energy setup, immediate power removal capability, confirmation of unchanged speed mode, manual direction and count verification, bumpless enable, Ki equal to zero, low speed/acceleration, small positive and negative moves, monitoring of position/speed/Iq/DC-bus/saturation, and gradual tuning before full-turn or multi-turn tests.

## Explicit Non-goals

- Absolute position, retained turns across restart, or homing/index implementation.
- Direct position-to-Iq, voltage, duty-cycle, or PWM control.
- Changes to MCAT output or tuned current/speed/observer parameters.
- Changes to existing hardware/software fault thresholds or fault arbitration.
- Unrelated cleanup or refactoring.
- A claim of physical safety or working motor behavior without bench evidence.
