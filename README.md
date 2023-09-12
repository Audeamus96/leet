# Leet
My solutions to leetcode and other algorithm questions.

<br>

## Usage

createProblem.bat:

    - Used to create new solution/test files.
    - Takes in a single argument which is used as the file name. (do not include a file extension)
    - Creates header, source, and test files.

compileTest.bat:

    - Used to compile a source and its corresponding test file
    - Takes in a single argument which is the name of the source file (do not include a file extension)
    - Compiles the source and test files, then links them to the test_main.o object file.
    * If test_main.o does not exist, create it with "g++ -c tests_main.cpp -o build/tests_main.o"
