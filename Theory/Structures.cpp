#include <iostream>
#include <memory>

struct{
    int a;
    std::string b;
} myStruct1, myStruct2;

struct Person{
    private:
        int age;
    public:
        void setAge(int age)
        {
            this->age = age;
        }
        int getAge()
        {
            return age;
        }
};



int main(){
    std::cout << "\n=================Unnamed Structs=================\n";
    myStruct1.a = 1;
    myStruct1.b = "abc";
    myStruct2.a = 2;
    myStruct2.b = "cde";
    std::cout << "myStruct1.a + myStruct2.a = " << myStruct1.a + myStruct2.a << std::endl;
    std::cout << "myStruct1.b + myStruct2.b = " << myStruct1.b + myStruct2.b << std::endl;

    std::cout << "\n=================Named Structs=================\n";
    Person person;
    person.setAge(23);
    std::cout << "The age is " << person.getAge() << std::endl;

    return 0;
}