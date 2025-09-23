#include <iostream>

int main(){
    //Address
    std::cout << "\n=================Address=================\n";
    int a = 2;
    std::cout << "Addres of a: " << &a << std::endl;

    //Pointer
    std::cout << "\n=================Pointer=================\n";
    int* aPtr = &a;
    std::cout << "Pointer of a: " << aPtr << std::endl;
    std::cout << "Pointed value of aPtr is " << *aPtr << std::endl; //dereference operator

    //Pointers and Arrays
    std::cout << "\n=================Pointers and Arrays=================\n";
    int arr[3] = {8,5,2};
    int* ptr = arr; //points to address of first element of array
    std::cout << "Second element is " << *(ptr + 1) << std::endl;

    //Reference
    std::cout << "\n=================Reference=================\n";
    std::string city = "Paris";
    std::string& ref = city;
    std::cout << "Variable Value: " << city << std::endl;
    std::cout << "Reference Value: " << ref << std::endl;

    return 0;
}