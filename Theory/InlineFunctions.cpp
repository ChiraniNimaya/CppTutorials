#include <iostream>

inline int square(int x)
{
    return x*x;
}

int main(){
    int num = 9;

    int res = square(num); //here square(num) will be replaced by 5*5 in compilation
    std::cout << res << std::endl;
    return 0;
}