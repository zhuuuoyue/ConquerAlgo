#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/maximum-units-on-a-truck/description/
*/

class Solution
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        int count = 0;
        std::sort(boxTypes.begin(), boxTypes.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) -> bool
            {
                return lhs.back() >= rhs.back();
            }
        );
        int i = 0;
        while (truckSize > 0 && i < boxTypes.size())
        {
            int n = boxTypes[i].front();
            if (n > truckSize)
            {
                n = truckSize;
            }
            int s = boxTypes[i].back();
            count += (n * s);
            truckSize -= n;
            ++i;
        }
        return count;
    }
 };

TEST(T1710, C1)
{
    std::vector<std::vector<int>> boxTypes
    {
        {1, 3}, {2, 2}, {3, 1}
    };
    int res = Solution{}.maximumUnits(boxTypes, 4);
    EXPECT_EQ(res, 8);
}

TEST(T1710, C2)
{
    std::vector<std::vector<int>> boxTypes
    {
        {5, 10}, {2, 5}, {4, 7}, {3, 9}
    };
    int res = Solution{}.maximumUnits(boxTypes, 10);
    EXPECT_EQ(res, 91);
}
