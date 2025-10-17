#include <iostream>

//Inheritance
class Shape{
    private:
        int area;
    public:
        void showArea()
        {
            std::cout << "This has an Area\n";
        }
};
class Triangles : public Shape{};
class AcuteTriangles : public Triangles{ //Multi level inheritance
    //inherits showArea
    };
//Multiple inheritance- A class can also be derived from more than one base class, using a comma-separated list
//(Allows in C++)

//Runtime Polymorphism
class Polygon{
    protected:
        int width;
        int height;
    public:
        //Since below fn is not virtual, it will only call on ref pointers of child classes
        void setValues(int width, int height){
            this->width = width;
            this->height = height;
        }
        //will search for overriden fns in child classes too
        virtual double getArea(){
            return 0;
        }
        // if above fn is pure virtual fn, the Polygon is an abstract class
        // virtual double getArea() = 0;
};
class Triangle: public Polygon{
    public:
        void setValues(int width, int height){
            this->width = height;
            this->height = height;
        }
        double getArea(){
            return 0.5*width*height;
        }
};
class Rectangle : public Polygon{
    public:
        double getArea(){
            return width*height;
        }
};

//Compile time Polymorphism
//Function overloading
class Addition{
    public:
        int add(int a, int b)
        {
            return a+b;
        }
        double add(double a, double b)
        {
            return a+b;
        }
};
//Operator overloading
class Complex{
    public:
        int real;
        int img;
        Complex(int r=0, int i=0) : real(r), img(i) {};
        Complex operator+(const Complex &obj){
            return Complex(real+obj.real, img+obj.img);
        }
};

//Encapsulation - ensure that sensitive data is hidden from users
class Student{
    private:
        int age;
        int marks;
        std::string address;
    public:
        void setAge(int age)
        {
            this->age=age;
        }
        int getAge()
        {
            return age;
        }
};

//Abstraction
//Control abstraction - the process is hidden from the user
//Data abstraction - always hides the information about the data in the program
//1.Abstraction In Header Files eg: sort()
//2.Abstraction Using Classes - access specifiers

int main()
{
    std::cout << "\n=================Inheritance=================\n";
    AcuteTriangles acuteTriangles;
    acuteTriangles.showArea();

    std::cout << "\n=================Runtime Polymorphism=================\n";
    Polygon polygon;
    Triangle triangle;
    Rectangle rectangle;
    Triangle tr;
    Polygon* poly1 = &polygon;
    Polygon* poly2 = &triangle;
    Polygon* poly3 = &rectangle;
    poly1->setValues(2,3);
    poly2->setValues(4,5); //will call parent class fn
    poly3->setValues(5,6);
    tr.setValues(7,8); //will call child class fn
    std::cout << poly1->getArea() << std::endl;
    std::cout << poly2->getArea() << std::endl; //will call child class fn
    std::cout << poly3->getArea() << std::endl;
    std::cout << tr.getArea() << std::endl; //will call child class fn

    std::cout << "\n=================Compile time Polymorphism=================\n";
    std::cout << "\nFunction overloading=================\n";
    Addition addition;
    std::cout << addition.add(1,2) << std::endl;
    std::cout << addition.add(1.1,2.2) << std::endl;

    std::cout << "\nOperator overloading=================\n";
    Complex c1(1,2);       // Direct initialization 
    Complex c2 = Complex(3,1);  // Copy initialization 
    Complex c3{4,5};       // Uniform initialization (modern C++) 
    //Complex c4 = (1,2);    --> becomes Complex(2,0)
    std::cout << c3.real << " + i" << c3.img << std::endl;

    return 0;
}