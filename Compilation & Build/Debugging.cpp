#include <iostream>
#include <cassert>

int main()
{
    std::cout << "\n=================IDE Debugging=================\n";
    //Create a C++ project, set breakpoints, and use the debugger features

    //Other ways
        //use print statements
        //use of logging libraries to record program events, variable values and error messages to a file(e.g., spdlog, Boost.Log)
        //Exception handling
        //Using assert() statements to verify assumptions about program state. 
            //If an assertion fails, the program terminates, indicating a potential bug.
        int a = 1;
        int b = 0;
        assert(b != 0 && "Error: Division by zero!");
        std::cout << a/b;

    std::cout << "\n=================GDB Debugging=================\n";
    //Compile your code with debugging symbols (-g flag with GCC/Clang), 
    //then run gdb <executable> and use GDB commands to set breakpoints, step, and inspect.

    std::cout << "\n=================Valgrind=================\n";

    std::cout << "\n=================AddressSanitizer=================\n";
}