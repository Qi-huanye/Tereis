param(
    [switch]$Run
)

$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectDir = Join-Path $Root "src"
$IncludeDir = Join-Path $ProjectDir "include"
$SourceDir = Join-Path $ProjectDir "source"
$ResourceDir = Join-Path $ProjectDir "resources"
$AssetsDir = Join-Path $Root "assets"
$IconDir = Join-Path $AssetsDir "icons"
$BuildDir = Join-Path $Root ".vscode-build\mingw"
$ExePath = Join-Path $BuildDir "Tetris.exe"
$RcPath = Join-Path $ResourceDir "Tetris.rc"
$RcUtf8Path = Join-Path $BuildDir "Tetris.utf8.rc"
$ResObjPath = Join-Path $BuildDir "Tetris.res.o"

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

$WindresCandidates = @(
    "windres.exe",
    "C:\mingw64\bin\windres.exe"
)

$Windres = $null
foreach ($Candidate in $WindresCandidates) {
    try {
        $Resolved = Get-Command $Candidate -ErrorAction Stop
        $Windres = $Resolved.Source
        break
    } catch {
        if (Test-Path $Candidate) {
            $Windres = $Candidate
            break
        }
    }
}

New-Item -ItemType Directory -Force -Path $BuildDir | Out-Null

$Sources = @(
    (Join-Path $SourceDir "stdafx.cpp"),
    (Join-Path $SourceDir "Tetris.cpp"),
    (Join-Path $SourceDir "TetrisLogic.cpp"),
    (Join-Path $SourceDir "TetrisRender.cpp")
)

$LinkInputs = @()

if ($Windres -and (Test-Path $RcPath)) {
    $RcContent = Get-Content -Path $RcPath -Raw -Encoding Unicode
    $RcContent = $RcContent.Replace('"Tetris.ico"', ('"' + ((Join-Path $IconDir "Tetris.ico") -replace '\\', '/') + '"'))
    $RcContent = $RcContent.Replace('"small.ico"', ('"' + ((Join-Path $IconDir "small.ico") -replace '\\', '/') + '"'))
    [System.IO.File]::WriteAllText($RcUtf8Path, $RcContent, [System.Text.UTF8Encoding]::new($false))

    & $Windres `
        -I $IncludeDir `
        $RcUtf8Path `
        -O coff `
        -o $ResObjPath

    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }

    $LinkInputs += $ResObjPath
}

& $Gxx `
    -std=c++17 `
    -g `
    -O0 `
    -municode `
    -mwindows `
    -DUNICODE `
    -D_UNICODE `
    -D_WINDOWS `
    -I $IncludeDir `
    @Sources `
    @LinkInputs `
    -lwinmm `
    -lgdi32 `
    -luser32 `
    -o $ExePath

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

if ($Run) {
    Start-Process -FilePath $ExePath -WorkingDirectory $Root
}
