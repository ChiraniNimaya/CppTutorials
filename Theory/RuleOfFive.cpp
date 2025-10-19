#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:
    // 1️⃣ Default Constructor
    MyString(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
        std::cout << "Default constructor called for: " << data << std::endl;
    }

    // 2️⃣ Destructor
    ~MyString() {
        std::cout << "Destructor called for: " << (data ? data : "null") << std::endl;
        delete[] data;
    }

    // 3️⃣ Copy Constructor
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy constructor called for: " << data << std::endl;
    }

    // 4️⃣ Copy Assignment Operator
    MyString& operator=(const MyString& other) {
        std::cout << "Copy assignment called from " << other.data << std::endl;
        if (this == &other) return *this; // self-assignment guard

        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        return *this;
    }

    // 5️⃣ Move Constructor
    MyString(MyString&& other) noexcept {
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
        std::cout << "Move constructor called!" << std::endl;
    }

    // 6️⃣ Move Assignment Operator
    MyString& operator=(MyString&& other) noexcept {
        std::cout << "Move assignment called!" << std::endl;
        if (this == &other) return *this; // self-assignment guard

        delete[] data; // clean up old data
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
        return *this;
    }

    // Utility function
    void print() const {
        std::cout << (data ? data : "null") << std::endl;
    }
};

int main() {
    std::cout << "\n--- Creating s1 ---\n";
    MyString s1("Hello");

    std::cout << "\n--- Copy constructing s2 from s1 ---\n";
    MyString s2 = s1;  // invokes copy constructor

    std::cout << "\n--- Move constructing s3 from temporary ---\n";
    MyString s3 = MyString("World");  // invokes move constructor

    std::cout << "\n--- Copy assigning s2 = s1 ---\n";
    s2 = s1;  // invokes copy assignment

    std::cout << "\n--- Move assigning s3 = std::move(s1) ---\n";
    s3 = std::move(s1);  // invokes move assignment

    std::cout << "\n--- Final States ---\n";
    std::cout << "s1: "; s1.print();
    std::cout << "s2: "; s2.print();
    std::cout << "s3: "; s3.print();

    std::cout << "\n--- Program End ---\n";
    return 0;
}
