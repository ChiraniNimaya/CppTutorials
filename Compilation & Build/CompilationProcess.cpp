//01 - Source Code
#include <iostream> // The '<' and '>' brackets tell the compiler to look for the file in the standard directory
#include <memory>
#include "math_utils.h" // double quotes ( " " ) tell the compiler to search for the header file in the source file's directory

//So the Compile Command should be corrected like below:
    // g++ CompilationProcess.cpp math_utils.cpp -o a
    // ./a.exe


int main()
{
    std::cout << "\n=================Use of Header File=================\n";
    int result = add(10, 5);
    std::cout << "Result: " << result << std::endl;

    std::cout << "\n=================User defined macro=================\n";
    printf("%.2f", AREA(3, 4));

    std::cout << "\n\n=================Predefined Macros=================\n";
    printf("Line number is: %d\n", __LINE__);
    printf("File name of this program is: %s\n", __FILE__);
    printf("Program Compilation Date: %s\n", __DATE__);
    return 0;
}

//02 - Preprocessing => g++ -E main.cpp -o main.i
//The preprocessor handles lines that start with # (like #include, #define, etc.) and prepares the code for the compiler. 
//It:
    // Replaces #include <....> with actual code from the included files.
    // Expands macros
    // Handles conditional compilation (#ifdef, etc.)

//03 - Compilation => g++ -S main.i -o main.s
//The compiler translates preprocessed C++ code into assembly language, which is human readable low-level code, 
//It :
    // Does Syntax checking
    // Converts C++ to Assembly code (.s file)
    // main.s contains low-level assembly instructions.

//04 - Assembly => g++ -c main.cpp -o main.o
// The assembler converts the assembly code into object code, which is machine-readable binary (.o file).
// A .o (object file) that contains machine code, not yet executable on its own

//05 - Linking => g++ main.o math_utils.o -o main
// The linker combines multiple object files (main.o, math_utils.o) and links in external libraries (like iostream), creating a final executable. 
// It:
    // Connects the main() function in main.o to add() in math_utils.o
    // Resolves symbols from the standard library
    // An executable file (usually called main or whatever name you give)

//06 - Excecution => ./main
// It is the final executable produced by the linker.
// Output will be shown => Result: 15