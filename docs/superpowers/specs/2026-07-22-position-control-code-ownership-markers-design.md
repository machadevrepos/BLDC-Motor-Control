# Position-Control Code Ownership Markers Design

## Objective

Make every position-control addition visually distinguishable from the original NXP firmware without changing compiled behavior. The markers cover only the relative position-control work added in this project. Earlier encoder enablement, motor parameters, MCAT tuning, and other pre-existing deviations from the NXP repository are outside this annotation scope.

## Marker Convention in NXP Files

Every contiguous position-control insertion in an original NXP source or header file will be enclosed by a prominent block comment using this structure:

```c
/*==================================================================================================
 * CUSTOM POSITION CONTROL INTEGRATION - BEGIN
 *
 * Purpose:
 * A concise explanation of why this section exists, what information crosses
 * the NXP/custom boundary, and any relevant safety or ownership constraint.
 *
 * Ownership:
 * Custom project code. This section is not part of the original NXP firmware.
 *==================================================================================================*/
/* custom declarations or statements */
/*==================================================================================================
 * CUSTOM POSITION CONTROL INTEGRATION - END
 * NXP ORIGINAL CODE RESUMES BELOW
 *==================================================================================================*/
```

Comments will describe sections rather than repeat individual statements. A single inserted field or call may still receive begin/end markers because its ownership would otherwise be ambiguous when viewed in isolation.

## Files and Sections

### `src/main.c`

Markers will surround only the following position-control additions:

- `position_control.h` include;
- position-control sample-time/default macros and FreeMASTER type declarations;
- FreeMASTER globals, controller state, command-sequence state, and ownership flags;
- local integration-helper prototypes;
- controller initialization after `MCAT_Init()`;
- corrected wrapped-count delivery to the controller in the fast callback;
- permission-loss ownership release after state-machine execution;
- the complete position-control/FreeMASTER integration-helper implementation block;
- initialization-state reset/release calls;
- alignment-completion reset calls;
- position-loop execution at the existing slow-loop boundary.

The existing `ENCODER` selection, `switchSensor = encoder`, tuned NXP/MCAT control code, state transitions, FOC functions, and speed/current/PWM calculations will not be relabeled as part of this position-control work.

### `src/pospe_sensor.h`

Markers will surround `correctedWrappedMechanicalCount`, explaining that it is a read-only application-facing copy of the already calculated corrected wrapped mechanical count. The marker will state that it does not change the NXP observer, angle, speed, or hardware-counter processing.

### `src/pospe_sensor.c`

Separate markers will surround:

- copying the existing corrected wrapped calculation into the public field;
- clearing that field during the existing encoder reset path.

### `src/position_control.h` and `src/position_control.c`

Each file will receive a top-level banner stating that the entire file is custom project code and not NXP-delivered code. The header will document the purpose and units of the public type groups and API groups. The source will add function-level block comments for the main private helpers and public functions, including:

- numeric/configuration/tuning validation;
- runtime reset and safe-output handling;
- encoder unwrapping and impossible-delta rejection;
- bumpless enable and disable behavior;
- atomic tuning activation;
- count/degree target commands and software zero;
- acceleration/deceleration limiting;
- the 1 kHz P/optional-PI controller and anti-windup behavior.

Comments will focus on contracts, safety behavior, units, and ownership boundaries rather than narrating each line.

### Tests

`tests/position_control/test_position_control.c` and `run_tests.ps1` will receive short whole-file ownership banners. Test logic will not change.

## Behavioral Constraints

- Only comments and separators will be added.
- No declarations, expressions, constants, conditions, call order, state transitions, or formatting-sensitive generated configuration will change.
- No MCAT parameter or generated tuning file will be edited.
- Marker text will not claim hardware validation or absolute position capability.
- Existing line endings and surrounding NXP formatting will be preserved where practical.

## Verification

Verification will include:

1. A focused diff review confirming that every new change is comment-only.
2. A marker-balance check confirming every `BEGIN` has a corresponding `END` in NXP files.
3. `git diff --check` for whitespace errors.
4. Strict compilation of the isolated custom module and its C test translation unit using the available Arm GCC.
5. The existing source-contract test runner; its known native-host-compiler limitation will be reported accurately.

Full S32DS firmware compilation and motor bench testing remain separate from this comment-only annotation task.
