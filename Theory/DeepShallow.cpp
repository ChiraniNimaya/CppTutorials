#include <iostream>

class A {
 public:
  int* data;
  A(int x) {
    data = new int(x);
  }
  A(const A& other) {  // Deep copy constructor
    data = new int(*other.data);
  }
  ~A() {
    delete data;
  }
};

class B {
 public:
  int* data;
  B(int x) {
    data = new int(x);
  }
  B(const B& other) {  // Shallow copy constructor
    data = other.data;
  }
  ~B() {
    delete data;
  }
};

int main() {
  A a1(10);
  A a2 = a1;  // Deep copy
  std::cout << a1.data << " " << a2.data << std::endl;  // Outputs different memory addresses

  B b1(20);
  B b2 = b1;  // Shallow copy
  std::cout << b1.data << " " << b2.data << std::endl;  // Outputs the same memory address

  return 0;
}