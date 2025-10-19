#include <iostream>
#include <algorithm>

//Templates allows generic programming
//template functions and classes can work with any data type, without having to write seperate versions for each type

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
template <typename T> T findMax(T arr[], int size)
{
    T maxElement = arr[0];
    for (int i = 1; i < size; ++i)
    {
        maxElement = std::max(maxElement, arr[i]);
    }
    return maxElement;
}

int main()
{
    //Template class
    myClass<int> myClass1;
    myClass1.setA(1);
    myClass<double> myClass2;
    myClass2.setA(2.3);

    //Template function
    int arrInt[] = {1, 2, 8, 3, 4, 5};
    double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << findMax(arrInt, 6) << std::endl;
    std::cout << findMax(arrDouble, 5) << std::endl;

    return 0;
}