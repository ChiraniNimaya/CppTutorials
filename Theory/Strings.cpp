#include <iostream>
#include <limits>
#include <cstring>

int main(){
    // C-style strings
    char str_array1[7] = {'S', 'c', 'a', 'l', 'e', 'r', '\0'};
    // or 
    char str_array2[] = "Scaler";
    // or
    char str_name3[] = {'S', 'c', 'a', 'l', 'e', 'r', '\0'};
    // or
    char str_name4[7] = "Scaler"; /*or */ char str_name5[50] = "Scaler";

    // C++ String is a class
    std::string str_name6 = "hello";
    // or 
    std::string str_name7("hello");

    //Input functions
    std::cout << "\n=================Input functions=================\n";
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline
    char str[50];
    std::cout << "Enter your city name: ";
    std::cin.getline(str, 50);
    std::cout << str << std::endl;

    name.push_back('s');
    name.pop_back();

    //Capacity functions
    std::cout << "\n=================Capacity functions=================\n";
    int length = name.length();
    int size = name.size(); //same as length
    int capacity = name.capacity(); //maximum number of characters the string can hold before reallocation happens
    name.resize(2);  //increase or decrease the size of a string.
    name.reserve(10); //increases capacity to 10, does not change size
    name.shrink_to_fit(); //Requests the string to reduce its capacity to fit its current size
    std::cout << "Name: " << name << " Length: " << name.size() << " Capacity: " << name.capacity() << std::endl;

    //Iterator functions
    std::cout << "\n=================Iterator functions=================\n";
    std::string address = "Colombo";
    std::string::iterator it = address.begin(); //same as end(), rbegin(), rend()
    std::cout << *(it+1) << std::endl;

    //Manipulating Functions
    std::cout << "\n=================Manipulating functions=================\n";
    std::string phrase = "Hello World";
    char buffer[20];
    phrase.std::string::copy(buffer, 5, 6); //copy 5 characters of std::string starting from 6 into char array
    std::cout << buffer << std::endl;

    std::string fruit1 = "Apple";
    std::string fruit2 = "Orange";
    fruit1.swap(fruit2); //swaps 2 strings
    std::cout << "After swap - fruit 1 is: " << fruit1 << std::endl;
    std::cout << "After swap - fruit 2 is: " << fruit2 << std::endl;


    //Concatenation
    std::cout << "\n=================Concatenation=================\n";
    char s1[] = "aaa";
    char s2[4] = "bbb";
    strcat(s1, s2);
    std::cout << s1 << std::endl;

    std::string s3 = "ccc";
    std::string s4 = "ddd";
    s3.append(s4);
    std::cout << s3 << std::endl;

    std::string s5 = "eee";
    std::string s6 = "fff";
    std::cout << s5+s6 << std::endl;

    //Comparing strings
    std::cout << "\n=================Comparing=================\n";
    std::string a = "cat";
    std::string b = "dog";

    std::cout << a.compare(b) << std::endl;  // negative (cat < dog)
    std::cout << b.compare(a) << std::endl;  // positive (dog > cat)
    std::cout << a.compare("cat") << std::endl; // 0 (equal)


    return 0;
}