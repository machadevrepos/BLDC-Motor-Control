# CUSTOM PROJECT TEST RUNNER - NOT PART OF THE ORIGINAL NXP FIRMWARE
#
# Builds and runs the isolated relative position-controller tests with a native
# C compiler. It also checks the custom encoder/application integration contracts
# without modifying NXP-generated build files.

$ErrorActionPreference = 'Stop'

$testRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = (Resolve-Path (Join-Path $testRoot '..\..')).Path
$buildRoot = Join-Path $testRoot 'build'

New-Item -ItemType Directory -Force -Path $buildRoot | Out-Null

$encoderHeader = Get-Content -Raw (Join-Path $repoRoot 'src\pospe_sensor.h')
$encoderSource = Get-Content -Raw (Join-Path $repoRoot 'src\pospe_sensor.c')
if ($encoderHeader -notmatch 'uint16_t\s+correctedWrappedMechanicalCount\s*;') {
    throw 'ENCODER_CONTRACT_MISSING: corrected wrapped count is not public.'
}
if ($encoderSource -notmatch 'correctedWrappedMechanicalCount\s*=\s*\(uint16_t\)Absolut_position\s*;') {
    throw 'ENCODER_CONTRACT_MISSING: corrected wrapped count is not assigned from the existing calculation.'
}
if ($encoderSource -notmatch 'correctedWrappedMechanicalCount\s*=\s*0U\s*;') {
    throw 'ENCODER_CONTRACT_MISSING: corrected wrapped count is not cleared on reset.'
}

$applicationSource = Get-Content -Raw (Join-Path $repoRoot 'src\main.c')
foreach ($requiredPattern in @(
    '#include\s+"position_control\.h"',
    'volatile\s+PositionControlCommandStaged\s+g_positionCommandStaged',
    'volatile\s+PositionControlCommand\s+g_positionCommand',
    'volatile\s+PositionControlStatus\s+g_positionStatus',
    'PositionControl_UpdateEncoder\s*\(\s*&s_positionControl\s*,\s*encoderPospe\.correctedWrappedMechanicalCount',
    'cntrState\.state\s*==\s*run',
    'cntrState\.usrControl\.FOCcontrolMode\s*==\s*speedControl',
    'switchSensor\s*==\s*encoder',
    'pos_mode\s*==\s*encoder1',
    'PositionControl_Run\s*\(',
    'drvFOC\.pospeControl\.wRotElReq\s*=\s*positionOutput\.electricalRadPerSec'
)) {
    if ($applicationSource -notmatch $requiredPattern) {
        throw "APPLICATION_CONTRACT_MISSING: $requiredPattern"
    }
}

$compiler = $null
foreach ($candidate in @('gcc', 'clang')) {
    $command = Get-Command $candidate -ErrorAction SilentlyContinue
    if ($null -ne $command) {
        $compiler = $command.Source
        break
    }
}

if ($null -eq $compiler) {
    Write-Error 'NO_HOST_C_COMPILER: install gcc or clang, or add it to PATH.'
}

$executable = Join-Path $buildRoot 'test_position_control.exe'
$source = Join-Path $repoRoot 'src\position_control.c'
$test = Join-Path $testRoot 'test_position_control.c'
$include = Join-Path $repoRoot 'src'

& $compiler '-std=c99' '-Wall' '-Wextra' '-Wpedantic' '-Werror' "-I$include" $source $test '-lm' '-o' $executable
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

& $executable
exit $LASTEXITCODE
