#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>


class Solution {
public:
    void findRepeatingNumbers(std::vector<int>& arr) 
    {
        std::unordered_set<int> readNums;
        std::unordered_set<int> repeatedNums;
        for (int number : arr)
        {
            if (readNums.count(number))
            {
                repeatedNums.insert(number);
            }
            readNums.insert(number);
        }
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 6, 3, 6, 1};
    Solution obj;
    obj.findRepeatingNumbers(arr); // Output: 1, 3, 6

    return 0;
}