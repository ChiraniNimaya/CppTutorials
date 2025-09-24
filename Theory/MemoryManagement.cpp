#include <iostream>

void swapByValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swapByRef(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int* a, int* b) //Discouraged
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

class Student{
    private:
        int age;
    public:
        Student () : age(12) {} //default constructor
        int getAge()
        {
            return age;
        }
};

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

    //Pass by Reference
    std::cout << "\n=================Pass By Reference=================\n";
    int x,b,c,d,e,f;
    x = 1;
    b = 1;
    c = 2;
    d = 2;
    e = 3;
    f = 4;
    std::cout << x << b << c << d << e << f << std::endl;
    swapByValue(x,c); //does not swap
    swapByRef(b, d); // swaps
    swapByPointer(&e,&f); //swaps but not in use
    std::cout << x << b << c << d << e << f << std::endl;
    
    //Memory Management
    std::cout << "\n=================Memory Management=================\n";
    //Dynamic memory allocation
    int* point_int = new int{6};
    float* point_float = new float{2.2};
    std::cout << "point_int: " << point_int << " point_float: " << point_float << std::endl;
    std::cout << "point_int value: " << *point_int << " point_float value: " << *point_float << std::endl;
    delete point_int;
    delete point_float;
    std::cout << "--After delete--\n";
    std::cout << "point_int: " << point_int << " point_float: " << point_float << std::endl; //still has memory location
    std::cout << "point_int value: " << *point_int << " point_float value: " << *point_float << std::endl; //Might show garbage
    //Safe dereferencing
    point_int = nullptr;  
    point_float = nullptr; 
    std::cout << "--After Safe dereferencing--\n";
    std::cout << "point_int: " << point_int << " point_float: " << point_float << std::endl; //no more memory is allocated
    //SO no more value or garbage value to access

    //For arrays
    float* marks = new float[]{30, 66.7, 98, 45};
    delete[] marks;
    marks = nullptr;

    //For objects - Student class
    Student* point_student = new Student(); //Default constructor is called
    std::cout << "Age: " << point_student->getAge() << std::endl;
    delete point_student;
    point_student = nullptr;

    return 0;
}