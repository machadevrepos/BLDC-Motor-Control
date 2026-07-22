# Position-Control Code Ownership Markers Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Clearly distinguish every new relative-position-control section from original NXP firmware using detailed, behavior-neutral ownership comments.

**Architecture:** Original NXP files receive balanced `CUSTOM POSITION CONTROL INTEGRATION - BEGIN/END` blocks around each position-control insertion. Entirely custom position-control and test files receive ownership banners and contract-focused function comments; executable code and generated tuning remain byte-for-byte unchanged apart from shifted line positions caused by comments.

**Tech Stack:** C99 comments, PowerShell source checks, Git diff inspection, Arm GCC strict compilation.

## Global Constraints

- Mark only the relative position-control work added in this project.
- Do not label earlier encoder enablement, motor parameters, MCAT tuning, or other pre-existing changes as part of this work.
- Add comments only; do not change declarations, expressions, constants, conditions, call order, formatting-sensitive generated configuration, or runtime behavior.
- Do not edit MCAT parameter files or `src/config/PMSM_appconfig.h`.
- Use detailed section comments, not per-line narration.
- Do not create a commit, branch, pull request, or worktree.

---

### Task 1: Mark Position-Control Integration in Original NXP Files

**Files:**
- Modify: `src/main.c`
- Modify: `src/pospe_sensor.h`
- Modify: `src/pospe_sensor.c`

**Interfaces:**
- Consumes: the existing position-control include, types, globals, helper functions, encoder count field, and integration calls.
- Produces: balanced ownership boundaries around every position-control insertion in an NXP-delivered file.

- [ ] **Step 1: Record the current executable additions**

  Run:

  ```powershell
  git diff -U0 -- src/main.c src/pospe_sensor.h src/pospe_sensor.c
  ```

  Confirm the position-control additions match the approved specification and distinguish them from the earlier `ENCODER = 1` and `switchSensor = encoder` changes.

- [ ] **Step 2: Add detailed boundaries in `src/main.c`**

  Use the following exact outer structure around every contiguous custom insertion:

  ```c
  /*==================================================================================================
   * CUSTOM POSITION CONTROL INTEGRATION - BEGIN
   *
   * Purpose:
   * Explain this integration point, the data crossing the NXP/custom boundary,
   * and the relevant ownership or safety behavior.
   *
   * Ownership:
   * Custom project code. This section is not part of the original NXP firmware.
   *==================================================================================================*/
  /* existing custom position-control code */
  /*==================================================================================================
   * CUSTOM POSITION CONTROL INTEGRATION - END
   * NXP ORIGINAL CODE RESUMES BELOW
   *==================================================================================================*/
  ```

  Apply it to the include, configuration/types, globals, prototypes, initialization call, fast encoder update, permission release, helper implementation block, initialization reset, alignment reset, and slow-loop call. Do not include `#define ENCODER 1` or `switchSensor = encoder` inside markers.

- [ ] **Step 3: Mark the encoder accessor additions**

  Add balanced blocks around `correctedWrappedMechanicalCount` in `src/pospe_sensor.h`, its assignment from `Absolut_position`, and its reset to `0U`. Explain that these expose an already computed count without modifying NXP observer or hardware processing.

- [ ] **Step 4: Check marker balance**

  Run:

  ```powershell
  $files = 'src/main.c','src/pospe_sensor.h','src/pospe_sensor.c'
  foreach ($file in $files) {
      $text = Get-Content -Raw $file
      $begin = ([regex]::Matches($text, 'CUSTOM POSITION CONTROL INTEGRATION - BEGIN')).Count
      $end = ([regex]::Matches($text, 'CUSTOM POSITION CONTROL INTEGRATION - END')).Count
      if ($begin -ne $end) { throw "$file marker mismatch: $begin BEGIN / $end END" }
  }
  ```

  Expected: no output and exit code `0`.

### Task 2: Document the Entirely Custom Position-Control Module

**Files:**
- Modify: `src/position_control.h`
- Modify: `src/position_control.c`

**Interfaces:**
- Consumes: the existing public API and implementation.
- Produces: file ownership banners, grouped type/API documentation, and function contracts without executable changes.

- [ ] **Step 1: Add whole-file ownership banners**

  State near the top of both files that the entire file is custom project code, not NXP-delivered code, and implements only the relative mechanical position outer loop.

- [ ] **Step 2: Document header groups**

  Add section comments above diagnostic flags, configuration, active tuning, runtime input, output/status, internal state, and public API declarations. Include the relevant units and clarify which structures are active controller state versus application/FreeMASTER-facing data.

- [ ] **Step 3: Document private helpers**

  Add concise contract comments for finite/absolute/clamp helpers as a group, overflow-safe count arithmetic, count-to-degree/status mirroring, safe motion-state clearing, configuration validation, tuning validation, and rate limiting.

- [ ] **Step 4: Document public functions**

  Add detailed comments above initialization, reset, encoder update, enable, disable, tuning apply, count target, degree target, software zero, controller run, and output accessor. Explain prerequisites, state changes, units, validation, and safe failure behavior.

### Task 3: Mark Custom Test Files

**Files:**
- Modify: `tests/position_control/test_position_control.c`
- Modify: `tests/position_control/run_tests.ps1`

**Interfaces:**
- Consumes: current tests and source-contract checks.
- Produces: a short whole-file ownership banner in each test file.

- [ ] **Step 1: Add test ownership banners**

  State that each file is project-specific verification for the custom relative-position controller and is not part of NXP firmware. Do not change test cases, commands, assertions, or compiler flags.

### Task 4: Prove the Annotation Change Is Behavior-Neutral

**Files:**
- Inspect: all files from Tasks 1-3

**Interfaces:**
- Consumes: fully annotated sources.
- Produces: diff, marker, and compilation evidence.

- [ ] **Step 1: Review the focused diff**

  Run:

  ```powershell
  git diff -- src/main.c src/pospe_sensor.h src/pospe_sensor.c src/position_control.h src/position_control.c tests/position_control/test_position_control.c tests/position_control/run_tests.ps1
  ```

  Confirm the new patch adds comments only and does not alter existing executable tokens.

- [ ] **Step 2: Check whitespace and marker balance**

  Run `git diff --check`, followed by the Task 1 marker-balance command. Expected: exit code `0` for both.

- [ ] **Step 3: Strict-compile the custom module and test translation unit**

  Use the available Arm GCC with `-std=c99 -Wall -Wextra -Wpedantic -Werror` to compile `src/position_control.c` and `tests/position_control/test_position_control.c`. Expected: both object compilations exit `0` with no diagnostics.

- [ ] **Step 4: Run the source-contract test script**

  Run:

  ```powershell
  powershell -ExecutionPolicy Bypass -File tests/position_control/run_tests.ps1
  ```

  Expected in the current environment: encoder/application source-contract checks pass, followed by the already documented `NO_HOST_C_COMPILER` result. Do not report the C unit tests as executed.

- [ ] **Step 5: Report verification boundaries**

  State separately: comment-only diff inspection, strict Arm compilation, host runtime tests, complete S32DS build, and motor bench testing. Do not claim any unexecuted level.
