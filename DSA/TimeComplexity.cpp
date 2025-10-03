#include <iostream>
#include <memory>
#include <cmath>

//n - input size
//O - Bog-O notation

int main()
{
    std::cout << "\n================= O(1) =================\n";
    //O(1) - Constant Time: The number of operations remains constant regardless of the input size.
    //Eg 01
    int a = 1;
    int b = 2;
    int sum = a + b; // Single operation
    std::cout << "Sum= " << a+b << std::endl;
    //O(2) = O(1) since 2 is Constant
    //Eg 02
    std::cout << "Hello World\n";

    std::cout << "\n================= O(n) =================\n";
    //O(n) - n Times:  Every time, a linear amount of time is required to execute code.
    int n = 8;
    int i;
    for (i = 0; i < n; ++i)
    {
        std::cout << "Hello " << i << std::endl;
    }

    std::cout << "\n================= O(log2(n)) =================\n";
    for (i = 1; i <= n; i=i*2) {
        std::cout << "Hello " << i << std::endl;
    }

    std::cout << "\n================= O(log(log2(n))) =================\n";
    for (i = 2; i <= n; i=pow(i,2)) {
        std::cout << "Hello " << i << std::endl;
    }
    return 0;
}