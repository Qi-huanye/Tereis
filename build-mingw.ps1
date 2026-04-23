param(
    [switch]$Run
)

$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectDir = Join-Path $Root "src"
$BuildDir = Join-Path $Root ".vscode-build\mingw"
$ExePath = Join-Path $BuildDir "Tetris.exe"

$GxxCandidates = @(
    "g++.exe",
    "C:\mingw64\bin\g++.exe"
)

$Gxx = $null
foreach ($Candidate in $GxxCandidates) {
    try {
        $Resolved = Get-Command $Candidate -ErrorAction Stop
        $Gxx = $Resolved.Source
        break
    } catch {
        if (Test-Path $Candidate) {
            $Gxx = $Candidate
            break
        }
    }
}

if (-not $Gxx) {
    throw "g++.exe not found. Add MinGW to PATH or install it at C:\mingw64\bin\g++.exe."
}

New-Item -ItemType Directory -Force -Path $BuildDir | Out-Null

$Sources = @(
    (Join-Path $ProjectDir "stdafx.cpp"),
    (Join-Path $ProjectDir "Tetris.cpp"),
    (Join-Path $ProjectDir "TetrisLogic.cpp"),
    (Join-Path $ProjectDir "TetrisRender.cpp")
)

& $Gxx `
    -std=c++17 `
    -g `
    -O0 `
    -municode `
    -mwindows `
    -DUNICODE `
    -D_UNICODE `
    -D_WINDOWS `
    -I $ProjectDir `
    @Sources `
    -lwinmm `
    -lgdi32 `
    -luser32 `
    -o $ExePath

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

if ($Run) {
    Start-Process -FilePath $ExePath -WorkingDirectory $ProjectDir
}
