@echo off

rem Check if the correct number of arguments are provided
if "%~2"=="" (
    echo Usage: compile.bat source.cpp output.obj
    exit /b 1
)

rem Compile the C++ source file to an object file
g++ -c %1 -o .\build\%2.o

rem Check the result of the compilation
if %errorlevel% equ 0 (
    echo Compilation successful.
) else (
    echo Compilation failed.
    exit /b 1
)

rem Link test-main to the test file and create executable
g++ .\build\tests-main.o .\build\%2.o -o test

rem Check the result of the compilation
if %errorlevel% equ 0 (
    echo Linking successful.
    exit /b 0
) else (
    echo Linking failed.
    exit /b 1
)