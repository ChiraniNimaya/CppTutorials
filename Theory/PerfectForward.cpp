#include <iostream>
#include <utility>  // for std::forward

//perfect forwarding is passing arguments along **without changing** whether they’re temporary or not(Rvalue or Lvalue).

void print_type(const std::string& s) { std::cout << "Lvalue\n"; }
void print_type(std::string&& s) { std::cout << "Rvalue\n"; }

template<typename T>
void wrapper(T&& arg) {
    // forward the argument to print_type, keeping its original type
    print_type(std::forward<T>(arg));
}

int main() {
    std::string name = "Chirani";
    wrapper(name);            // lvalue → prints "Lvalue"
    wrapper("Hello World");   // rvalue → prints "Rvalue"
}
