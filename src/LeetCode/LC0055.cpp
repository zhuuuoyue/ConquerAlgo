#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/jump-game/description/
*/

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() < 2)
        {
            return true;
        }
        int m = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < nums.size())
        {
            if (m >= j)
            {
                return true;
            }
            if (m == i && nums[i] == 0)
            {
                return false;
            }
            m = std::max(nums[i] + i, m);
            ++i;
        }
        return false;
    }
};

TEST(T55, C1)
{
    std::vector<int> nums{ 2, 3, 1, 1, 4 };
    bool can = Solution{}.canJump(nums);
    EXPECT_TRUE(can);
}

TEST(T55, C2)
{
    std::vector<int> nums{ 3, 2, 1, 0, 4 };
    bool can = Solution{}.canJump(nums);
    EXPECT_FALSE(can);
}
