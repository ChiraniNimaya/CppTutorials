#include <iostream>
#include <memory>

// A constructor has same name as the class itself
// Don't have return type
// Automatically called when an object is created.
// If we do not specify a constructor, C++ compiler generates a default constructor for us (expects no parameters and has an empty body)
class Wall{
    private:
        double length;
    public:
        //default constructor
        Wall() : length{4.5} {
            std::cout << "Default Wall Constructor is called\n";
            std::cout << "Length: " << length << std::endl;
        }
        //Destructor
        ~Wall() {
            std::cout << "Wall Destructor is called" << std::endl;
        }
};
class Square{
    private:
        //initialize with default value
        double side {7.8};
    public:
        //defaulted constructor
        Square() = default;
        double getSide() {
            return side;
        }
};

class Rectangle{
    private:
        double length;
        double width;
    public:
        // parameterized constructor to initialize variables
        Rectangle (double len, double wit) : length{len}, width(wit) {
            std::cout << "Parameterized Rectangle Constructor is called\n";
        }
        // copy constructor with a Rectangle object as parameter
        // copies data of the obj parameter
        Rectangle (const Rectangle& obj) : length{obj.length}, width{obj.width} {
            std::cout << "Copy Constructor is called\n";
        }
        double getArea()
        {
            return length*width;
        }
};

class Tringle{
    private:
        double length;
        double width;
    public:
        Tringle (double len, double wit) : length{len}, width(wit) {
            std::cout << "Parameterized Triangle Constructor is called\n";
        }
        double getArea()
        {
            return 0.5*length*width;
        }
};

class MyClass {
private:
    int b;

public:
    // Move Constructor
    MyClass(int &&a) : b(std::move(a)) {
        std::cout << "Move constructor called!" << std::endl;
    }

    void display() {
            std::cout << b << std::endl;
    }
};

class Image{
    private:
        double* length;
        double* height;
    public:
        Image(double len = 1.0, double het = 1.0) : length{new double{len}}, height{new double{het}} {
            std::cout << "Image parameterized constructor is called\n";
        }
        Image(Image& img) : length{new double{*(img.length)}}, height{new double{*(img.height)}} {
            std::cout << "Image copy constructor is called\n";
        }
        void setLength(double len) {
        *length = len;
    }
    
    double calculateArea() {
      return *length * *height;
    }
    
    // destructor to deallocate memory
    ~Image() {
        delete length;
        delete height;
        std::cout << "Image destructor is called and deallocated memory\n";
    }

};


int main(){
    std::cout << "\n=================Default Constructor=================\n";
    Wall wall;

    std::cout << "\n=================Defaulted Constructor=================\n";
    Square square;
    std::cout << "Default side: " << square.getSide() << std::endl;

    std::cout << "\n=================Parameterized Constructor=================\n";
    Rectangle rec1(3,4);
    Rectangle rec2(2,6.7);
    std::cout << "Area of rec1: " << rec1.getArea() << std::endl;
    std::cout << "Area of rec2: " << rec2.getArea() << std::endl;

    std::cout << "\n=================Copy Constructor=================\n";
    //Create object and copy its content to another object
    Rectangle rec3(5,7);
    std::cout << "Area of rec3: " << rec3.getArea() << std::endl;
    Rectangle rec4 = rec3;
    std::cout << "Area of rec4: " << rec4.getArea() << std::endl;
    Rectangle rec5(rec3);
    std::cout << "Area of rec5: " << rec5.getArea() << std::endl;

    std::cout << "\n=================Move Constructor=================\n";
    //instead of copying the object in the new memory, 
    //it makes use of move semantics to transfer the ownership of the already created object to the new object 
    //without creating extra copies.
    int a = 4;
    MyClass obj1(std::move(a));  // Move constructor is called
    obj1.display();

    std::cout << "\n=================Default Copy Constructor=================\n";
    //If we don't define any copy constructor, move constructor, or move assignment in our class, 
    // then the C++ compiler will automatically create a default copy constructor 
    // that does memberwise copy assignment
    Tringle tr1(3,4);
    Tringle tr2(tr1);
    std::cout << "Area of tr1: " << tr1.getArea() << std::endl;
    std::cout << "Area of tr2: " << tr2.getArea() << std::endl;

    std::cout << "\n=================Destructor=================\n";
    Image img1(10.5, 8.6);
    Image img2 = img1;
    img2.setLength(11.5);
    std::cout << "Area of Image 1: " << img1.calculateArea() << std::endl;
    std::cout << "Area of Image 2: " << img2.calculateArea() << std::endl;

    std::cout << "Now objects will be descoped and its destructor will be called" << std::endl;
    return 0;
}