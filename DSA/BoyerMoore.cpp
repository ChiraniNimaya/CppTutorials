#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i<n; ++i)
        {
            if (nums[i] == candidate)
                ++count;
            else
            {
                --count;
                if (count == 0)
                {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        // Second pass to verify majority
        count = 0;
        for (int num : nums)
            if (num == candidate)
                ++count;

        return (count > nums.size() / 2) ? candidate : -1; // Return -1 if no majority
    }
    
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {0, 0, 1, 1, 1, 1, 1, 2, 3, 3, 3};
    std::cout << solution.majorityElement(nums1);

    return 0;
}
