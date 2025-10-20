#include <iostream>

void memoryLeakExample() {
    int* leak = new int[5];  // allocated but never freed
    leak[0] = 10;
    std::cout << "Value: " << leak[0] << std::endl;
}

void invalidAccessExample() {
    int* ptr = new int(5);
    delete ptr;              // freed
    std::cout << *ptr << std::endl;  // invalid read (use-after-free)
}

int main() {
    memoryLeakExample();
    invalidAccessExample();
    return 0;
}
