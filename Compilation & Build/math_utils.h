//include guards (or header guards)
#ifndef MATH_UTILS_H //check if not defined
#define MATH_UTILS_H //define now
#include <stdio.h>

// Macro Definition
#define HALF 0.5
// macro with parameter
#define AREA(l, b) (HALF * l * b)

// Declaration of functions
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

#endif

// A header file contains: 
    // Function definitions : Actual body of a function.
    // Data type definitions : Explains kind of data stored.
    // Macros : Simple text replacements that make code shorter and reusable.