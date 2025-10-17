#include <iostream>
using namespace std;

class A {
public:
    int value;
};

class B : virtual public A { };  // Virtual Inheritance
class C : virtual public A { };  // Virtual Inheritance
//You’re telling the compiler:
    //Only keep one shared A no matter how many times it’s inherited through virtual paths.”

class D : public B, public C { };  // Resolves the Diamond Problem

int main() {
    D obj;
    obj.value = 10;  // No ambiguity, only one A exists
    cout << "Value: " << obj.value << endl;
    return 0;
}
/*
Now there is only ONE A inside D, solving the diamond problem by virtual inheritance
*/ 