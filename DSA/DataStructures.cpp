#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>

class Arrays
{
    //Should specify the length - Fixed size
        std::string strArray[3] = {"aaa", "bbb", "ccc"};
        std::array<int, 4> intArray = {1, 2, 3, 4};
    public:
        
        void printStringArrayElement1(){
            std::cout << strArray[0] << std::endl;
        }
        std::array<int, 4> getIntArray(){
            return intArray;
        }

};

class Vectors{
    //no need of specifying the length - Dynamic legnth
    std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    public:
    void printCars(){
        for (std::string car : cars)
            std::cout << car << std:: endl;
    }
    std::vector<std::string> getCars(){
        return cars;
    }
};

class List{
    //no random access unlike vectors(front and back only)
    std::list<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
};

class Sets{
    //Remove duplicates and sort in descending order
    std::set<int, std::greater<int>> numbers = {1, 1, 7, 3, 2, 5, 9};

    public:
    void Add100AndPrintSet(){
        numbers.insert(100);
        for (int num : numbers) {
            std::cout << num << "\n";
        }
        numbers.erase(99);
    }
};

class Maps{
    //sorted and unique
    std::map<std::string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };
};

int main()
{
    Arrays array;
    array.printStringArrayElement1();
    auto arr = array.getIntArray();
    std::cout << "Array Length = " << arr.size() << "\n" << std::endl;

    Vectors vector;
    auto cars = vector.getCars();
    cars.at(0) = "Opel";
    cars.pop_back();
    cars.push_back("Tesla");
    std::cout <<"Cars before modified:\n";
    vector.printCars();
    std::cout <<"Cars after modified:\n";
    for (std::string car : cars)
            std::cout << car << std:: endl;
    std::cout << "\n";

    Sets set;
    set.Add100AndPrintSet();

    Maps map;


    return 0;
}