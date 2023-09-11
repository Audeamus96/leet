@echo off
setlocal enabledelayedexpansion

rem Get the current working directory
set current_dir="%CD%"

rem Check if an argument was provided
if "%~1"=="" (
    echo "Please provide an argument (e.g., problem_name)"
    exit /b 1
)

rem Set the argument as the problem name
set problem_name=%1

rem Create the solutions directory if it doesn't exist
if not exist "%current_dir%\solutions" mkdir "%current_dir%\solutions"

rem Create the tests directory if it doesn't exist
if not exist "%current_dir%\tests" mkdir "%current_dir%\tests"

rem Create the headers directory if it doesn't exist
if not exist "%current_dir%\solutions\headers" mkdir "%current_dir%\solutions\headers"

rem Create the solution file (solutions/problem_name.cpp)
echo #include "headers\%problem_name%.hpp">"%current_dir%\solutions\%problem_name%.cpp"


rem Create the test file (tests/test_problem_name.cpp)
echo #include "..\catch.hpp">>"%current_dir%\tests\test_%problem_name%.cpp"
echo.>>"%current_dir%\tests\test_%problem_name%.cpp"
echo TEST_CASE("Test %problem_name%") {>>"%current_dir%\tests\test_%problem_name%.cpp"
echo     // Add your test cases here>>"%current_dir%\tests\test_%problem_name%.cpp"
echo }>>"%current_dir%\tests\test_%problem_name%.cpp"

rem Create the header file (solutions/headers/problem_name.h)
echo.>"%current_dir%\solutions\headers\%problem_name%.hpp"

echo Files created successfully:
echo - %current_dir%\solutions\%problem_name%.cpp
echo - %current_dir%\tests\test_%problem_name%.cpp
echo - %current_dir%\solutions\headers\%problem_name%.hpp

endlocal