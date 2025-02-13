#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<int> findProdExceptSelf(std::vector<int>& arr) 
    {
        int zeroIndex;
        int zeroCount = 0;
        int totalProd = 1;
        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == 0)
            {
                zeroCount++;
                if (zeroCount >= 2)
                    break;
                zeroIndex = i;
            }
            else
            {
                totalProd *= arr[i];
            }
            
        }

        std::vector<int> prods(n,0);
        if (zeroCount == 1)
        {
            prods[zeroIndex] = totalProd;
        }
        else if (zeroCount == 0)
        {
            for (int i = 0; i < arr.size(); i++)
                prods[i] = totalProd / arr[i];
        }
        return prods;
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    Solution obj;
    std::vector<int> prods = obj.findProdExceptSelf(arr);

    for (int i = 0; i < prods.size(); i++)
    {
        std::cout << prods[i] << "  ";
    }

    return 0;
}