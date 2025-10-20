#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks." << endl;
    }
};

// Derived Class
class Dog : public Animal {
public:
    void speak() override  {
        cout << "Dog barks." << endl;
    }
};

// Derived Class
class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows." << endl;
    }
};

int main() {
  
    // Base class pointer to derived class object
    Animal* animalPtr = new Dog();
    animalPtr->speak();

    // Downcasting
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

    // Checking if the typecasting is successfull
    if (dogPtr) {
        dogPtr->speak();
    }
    else {
        cout << "Failed to cast to Dog." << endl;
    }

    // Typecasting to other dervied class
    //now animalPtr points to Dog* so the casting will fail and return nullptr
    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
    if (catPtr) {
        catPtr->speak();
    }
    else {
        cout << "Failed to cast to Cat." << endl;
    }

    delete animalPtr;
    return 0;
}