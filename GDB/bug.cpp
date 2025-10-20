// bug.cpp
#include <iostream>

void cause_segfault() {
    int* p = nullptr;
    *p = 42; // <- definite segmentation fault (use-after-null)
}

int main(int argc, char** argv) {
    std::cout << "Starting program\n";
    cause_segfault();
    std::cout << "This line will not run\n";
    return 0;
}
