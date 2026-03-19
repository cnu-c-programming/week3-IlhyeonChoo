@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"

set "path_code=code"
set "path_test=testset"
set "CC=gcc"

for %%X in ("%path_code%\*.c") do (
    set "name=%%~nX"
    set "expected=%path_test%\!name!-out.txt"
    if exist "!expected!" (
        %CC% "%%~fX" -o "%path_code%\!name!.exe" 2>nul
        if exist "%path_code%\!name!.exe" (
            set "infile=%path_test%\!name!-in.txt"
            if exist "!infile!" (
                "%path_code%\!name!.exe" < "!infile!" > "%path_test%\actual-!name!.txt"
            ) else (
                "%path_code%\!name!.exe" > "%path_test%\actual-!name!.txt"
            )
            fc /b "%path_test%\actual-!name!.txt" "!expected!" >nul
            if errorlevel 1 (
                echo !name!.txt: FAIL
            ) else (
                echo !name!.txt: PASS
            )
            del "%path_test%\actual-!name!.txt" 2>nul
        ) else (
            echo !name!: COMPILE FAIL
        )
    ) else (
        echo !name!: SKIP ^(no !name!.txt in Test^)
    )
)

endlocal
