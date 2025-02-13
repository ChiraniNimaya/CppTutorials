#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int maxSubarraySum(std::vector<int> arr) 
    {
        int currentSum = 0;
        int maxSum = arr[];
        for (int i = 0; i <arr.size(); ++i)
        {
            currentSum += arr[i];
            maxSum = std::max(maxSum, currentSum);
            if (currentSum < 0) 
                currentSum = 0;
        }
        return maxSum;
    }
    int maxProduct(std::vector<int> &arr) 
    {
        int maxProd = INT_MIN;
        int rightToLeft = 1;
        int leftToRight = 1;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i)
        {
            if (rightToLeft == 0)
                rightToLeft = 1;
            if (leftToRight == 0)
                leftToRight = 1;

            leftToRight *= arr[i];
            rightToLeft *= arr[n-i-1];

            maxProd = std::max(maxProd, leftToRight, rightToLeft);
        }
        return maxProd;
    }
};


int main() {
    std::vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    Solution obj;
    int sum = obj.maxSubarraySum(arr1);
    std::cout << "Maximum Sum = " << sum << std::endl;

    std::vector<int> arr2 = {-2, 6, -3, -10, 0, 2};
    int prod = obj.maxProduct(arr2);
    std::cout << "Maximum Product = " << prod << std::endl;

    return 0;
}