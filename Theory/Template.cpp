#include <iostream>

//Template class
template <typename T> class myClass
{
    private:
    T a;
    public:
    int getA() {return a;}
    void setA(int a) {this->a = a;}
};

//Template function
template <typename T> T findMax(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    //Template class
    myClass<int> myClass1;
    myClass1.setA(1);
    myClass<double> myClass2;
    myClass2.setA(2.3);

    //Template function
    std::cout << findMax(4,6) << std::endl;
    std::cout << findMax(8.4,6.88) << std::endl;

    return 0;
}