# Relative Position Control Commissioning

## Validation boundary

This firmware implements relative, multi-turn mechanical position control around the existing tuned encoder speed loop. It does not implement absolute position, index-based homing, or retained position across reset. The multi-turn origin is reset by application initialization and completion of the existing alignment sequence; `setSoftwareZeroSequence` changes only the current relative coordinate.

Source compilation and offline tests are not substitutes for validation on the Faulhaber 3216 W 012 BXT H motor. Do not describe the feature as hardware-tested until every bench step below has been completed and recorded.

## FreeMASTER interface

The ELF exposes three global RAM symbols:

- `g_positionCommandStaged` — writable staging values. Write all desired fields before changing a command sequence.
- `g_positionCommand` — writable command sequence counters. Increment a counter to request that action; do not hold or toggle it as a Boolean.
- `g_positionStatus` — firmware-owned, read-only status. Do not write it from FreeMASTER.

Staged fields and units:

- `tuning.kpMechanicalRadPerSecPerCount`: mechanical rad/s per encoder count.
- `tuning.kiMechanicalRadPerSecPerCountSec`: mechanical rad/s per count-second. Keep at `0.0` for initial commissioning.
- `tuning.integratorLimitMechanicalRadPerSec`: mechanical rad/s.
- `tuning.maxMechanicalRadPerSec`: mechanical rad/s; values above the firmware-derived safe ceiling are rejected.
- `tuning.maxAccelMechanicalRadPerSec2` and `maxDecelMechanicalRadPerSec2`: mechanical rad/s².
- `tuning.positionToleranceCounts`: quadrature counts.
- `tuning.stoppedMechanicalRadPerSec`: mechanical rad/s.
- `tuning.atTargetDwellSec`: seconds.
- `tuning.negativeSoftLimitEnabled`, `negativeSoftLimitCounts`, `positiveSoftLimitEnabled`, and `positiveSoftLimitCounts`: relative software-limit configuration.
- `targetCounts`: signed relative quadrature counts when `targetUnits` is `0`.
- `targetDegrees`: signed relative mechanical degrees when `targetUnits` is `1`.

Command priority at each 1 kHz boundary is disable/lost permission, apply tuning, software zero, enable, then target. An enable command captures the current position, clears motion state, and produces zero speed. A target command received in the same boundary is deferred until the following boundary, so enable alone cannot start motion.

Recommended command order:

1. Write every staged tuning field.
2. Increment `applySequence` and confirm `g_positionStatus.applyAccepted` and `tuningResult` indicate acceptance.
3. Increment `enableSequence`; confirm enabled ownership with a zero speed request.
4. Write a small target and its units.
5. Increment `setTargetSequence`.
6. Increment `disableSequence` to relinquish position ownership.

## Bench preparation

1. Secure the motor unloaded or with a known low-inertia fixture. Keep personnel and wiring clear of the rotor.
2. Provide an immediate means of removing motor-bus power independently of firmware and FreeMASTER.
3. Use a current-limited 12 V supply and begin below the normal current limit where the drive hardware permits it. Do not weaken firmware fault thresholds.
4. Confirm the existing speed-control firmware still starts, stops, aligns, changes direction, and faults exactly as expected while position mode remains disabled.
5. Record the starting firmware revision, power-supply limits, mechanical load, and oscilloscope/FreeMASTER channels.

Monitor at minimum:

- corrected wrapped count and multi-turn count;
- mechanical position degrees, target, and error;
- measured mechanical speed, requested mechanical speed, and converted electrical speed request;
- D/Q current feedback and request, especially Iq;
- DC-bus voltage during deceleration;
- speed/current saturation and position limiting flags;
- existing fault words and position diagnostic flags.

## Direction and scaling checks

Perform these checks with PWM disabled:

1. Rotate the shaft slowly in the intended positive direction. Confirm the corrected wrapped count and multi-turn position increase.
2. Cross the wrap in both directions. Confirm `511 -> 0` adds one count and `0 -> 511` subtracts one count.
3. Rotate exactly one mechanical revolution. Confirm the multi-turn change is 512 counts and 360 mechanical degrees.
4. Rotate several revolutions in both directions and return to the start. Confirm the count returns within encoder accuracy and mechanical backlash.
5. If the sign is wrong, correct the application-level encoder direction configuration and repeat these checks before energizing the motor. Do not compensate by changing speed-loop, current-loop, or electrical-angle signs.

## First powered moves

1. Leave `Ki` at `0.0`.
2. Apply a deliberately low position-mode speed limit and low acceleration/deceleration limits.
3. Enter the existing normal run state using encoder-based speed control. Confirm `controlPermitted`, `encoderValid`, and zero position diagnostics.
4. Increment `enableSequence`. Confirm the target captures the current position and both requested speeds remain zero. Remove power immediately if the shaft moves.
5. Command `+5` mechanical degrees. Verify direction, Iq polarity, speed limiting, deceleration, final error, and DC-bus behavior.
6. Return to zero, then command `-5` mechanical degrees and repeat the checks.
7. Increment `disableSequence`. Confirm one zero-reference boundary and clean return to the original speed-reference path with no stale position-generated command.
8. Repeat enable/disable, application stop, existing fault injection, fault clear, alignment, and re-enable checks. Position ownership must be absent outside the permitted run/mode/sensor combination.

## Gain and limit progression

1. Increase `Kp` in small steps while keeping `Ki = 0`. Use small targets and wait for the stopped-speed dwell indication after each move.
2. Reduce `Kp` if position or current oscillates, the speed loop saturates, or mechanical noise increases.
3. Increase speed and acceleration limits gradually. Watch DC-bus rise during deceleration; reduce deceleration if regeneration approaches the existing overvoltage threshold.
4. Test soft limits from both directions and confirm target clamping before requesting larger moves.
5. Only after stable P-only operation under the intended load, introduce a small `Ki` if persistent load error requires it. Confirm integrator limiting and anti-windup during saturated moves.
6. Progress from small moves to one revolution, then multi-turn moves. Repeat stop, fault, encoder-invalid, and permission-loss tests at each stage.

## Acceptance record

Record these levels separately:

- Firmware compiled with the configured NXP S32DS GCC toolchain.
- Isolated unit tests executed on a host and all checks passed.
- Integration inspected or exercised without motor power.
- Direction/scaling validated with PWM disabled.
- Low-energy powered moves completed.
- Full-load and full-range bench validation completed.

Do not mark a later level complete based only on an earlier one.
