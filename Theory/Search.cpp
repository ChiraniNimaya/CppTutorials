#include <iostream>
#include <vector>
#include <algorithm>

int linearSearch(const std::vector<int>& arr, int target)
{
    for (int i = 0; i < arr.size(); ++i){
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) //requires sorted data- below code is for ascending order
{
    int left = 0;
    int right = arr.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left)/2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1; //search right half
        else
            right = mid - 1; //search left half
    }
    return -1;
}

int main()
{
    return 0;
}