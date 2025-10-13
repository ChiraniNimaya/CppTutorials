#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size();
        int candidate = 0;
        int count = 0;
        
        for (int num : nums)
        {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
    
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {0, 0, 1, 1, 1, 1, 1, 2, 3, 3, 3};
    std::cout << solution.majorityElement(nums1);

    return 0;
}
