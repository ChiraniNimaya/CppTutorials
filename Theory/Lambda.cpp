#include <iostream>
#include <vector>
#include <algorithm>

//lambda => [](){}
//[captures](parameters){fn body}
//if capture is given by value, its read only, if its given by reference, the latest value will be given and it can be altered

int main()
{
    std::vector<int> numbers{1,2,3,4,0,5,6,7,8,9};
    int sum = 0;
    int doNotPrintNumber = 4;

    std::for_each(numbers.begin(), numbers.end(), [&](int x) //& means capture all by reference
    {
        if (x != doNotPrintNumber)
            std::cout << x <<std::endl;
        sum += x;
    });

    std::cout << sum <<std::endl;

    return 0;
}