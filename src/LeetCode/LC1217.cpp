#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position/description/
*/

class Solution
{
public:
    int minCostToMoveChips(vector<int>& position)
    {
        int count[2]{ 0, 0 };
        for (int pos : position)
        {
            ++count[pos % 2];
        }
        return std::min(count[0], count[1]);
    }
};

TEST(T1217, C1)
{
    std::vector<int> position{ 1, 2, 3 };
    int res = Solution{}.minCostToMoveChips(position);
    EXPECT_EQ(res, 1);
}

TEST(T1217, C2)
{
    std::vector<int> position{ 2, 2, 2, 3, 3 };
    int res = Solution{}.minCostToMoveChips(position);
    EXPECT_EQ(res, 2);
}

TEST(T1217, C3)
{
    std::vector<int> position{ 1, 100000000 };
    int res = Solution{}.minCostToMoveChips(position);
    EXPECT_EQ(res, 1);
}
