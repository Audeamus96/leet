@echo off

rem Compiles input file then links it to main file to create executable
rem Arguments:
rem     ARG1: name of file in solution folder

rem Check if the correct number of arguments are provided
if "%~1"=="" (
    echo Usage: compile.bat source.cpp output.obj
    exit /b 1
)

rem Compile the C++ source file to an object file
g++ -c solutions\%1.cpp -o .\build\%1.o

rem Check the result of the compilation
if %errorlevel% equ 0 (
    echo Compilation of solutions\%1.cpp.
) else (
    echo Compilation of tests\test_%1.cpp failed.
    exit /b 1
)

rem Compile the C++ test file to an object file
g++ -c .\tests\test_%1.cpp -o .\build\test_%1.o

rem Check the result of the compilation
if %errorlevel% equ 0 (
    echo Compilation of test successful.
) else (
    echo Compilation of test failed.
    exit /b 1
)

rem Link test-main to the test file and create executable
g++ .\build\test_main.o .\build\%1.o .\build\test_%1.o -o test

rem Check the result of the compilation
if %errorlevel% equ 0 (
    echo Linking successful.
    exit /b 0
) else (
    echo Linking failed.
    exit /b 1
)
