#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor\n";
        foo();  // Calling virtual function
    }

    virtual void foo() {
        cout << "Base::foo()\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor\n";
    }

    void foo() override {
        cout << "Derived::foo()\n";
    }
};

int main() {
    Derived d;
    return 0;
}
