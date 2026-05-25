param(
    [Parameter(Mandatory = $true)]
    [string]$Problem
)

$ErrorActionPreference = "Stop"

$repoRoot = Split-Path -Parent $PSScriptRoot
$practiceRoot = Join-Path $repoRoot "csp-practice"

$problemDir = Join-Path $practiceRoot "problems\$Problem"
if (-not (Test-Path -LiteralPath $problemDir)) {
    $problemDir = Join-Path $practiceRoot $Problem
}

$mainFile = Join-Path $problemDir "main.c"
$inputFile = Join-Path $problemDir "input.txt"
$exeFile = Join-Path $problemDir "main.exe"

if (-not (Test-Path -LiteralPath $problemDir)) {
    throw "Problem directory not found: $problemDir"
}

if (-not (Test-Path -LiteralPath $mainFile)) {
    throw "main.c not found: $mainFile"
}

if (-not (Test-Path -LiteralPath $inputFile)) {
    throw "input.txt not found: $inputFile"
}

Write-Host "Compiling $Problem..."
gcc -Wall -Wextra -std=c11 $mainFile -o $exeFile

Write-Host "Running $Problem..."
Get-Content -LiteralPath $inputFile | & $exeFile
