#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/maximum-subarray/description/
*/

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int res{ nums.front() };
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] = std::max(nums[i], nums[i] + nums[i - 1]);
            res = std::max(nums[i], res);
        }
        return res;
    }
};

TEST(T53, C1)
{
    std::vector<int> nums{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int res = Solution{}.maxSubArray(nums);
    EXPECT_EQ(res, 6);
}

TEST(T53, C2)
{
    std::vector<int> nums{ 1 };
    int res = Solution{}.maxSubArray(nums);
    EXPECT_EQ(res, 1);
}

TEST(T53, C3)
{
    std::vector<int> nums{ 5, 4, -1, 7, 8 };
    int res = Solution{}.maxSubArray(nums);
    EXPECT_EQ(res, 23);
}
