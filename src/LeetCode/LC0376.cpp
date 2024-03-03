#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/wiggle-subsequence/description/
*/

class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return 1;
        }

        int removed{ 0 };

        int i{ 1 };
        while (i < nums.size() && nums[i] == nums.front())
        {
            ++i;
            ++removed;
        }

        int pre{ nums[0] };
        bool pos{ nums[i] < nums[0] };
        while (i < nums.size())
        {
            if (nums[i] > pre && pos)
            {
                ++removed;
                ++i;
                continue;
            }
            if (nums[i] < pre && !pos)
            {
                ++removed;
                ++i;
                continue;
            }
            if (nums[i] == pre)
            {
                ++removed;
                ++i;
                continue;
            }

            pre = nums[i];
            pos = !pos;
            ++i;
        }
        return nums.size() - removed;
    }
};

TEST(T376, C1)
{
    std::vector<int> nums{ 1, 7, 4, 9, 2, 5 };
    int res = Solution{}.wiggleMaxLength(nums);
    EXPECT_EQ(res, 6);
}

TEST(T376, C2)
{
    std::vector<int> nums{ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    int res = Solution{}.wiggleMaxLength(nums);
    EXPECT_EQ(res, 7);
}

TEST(T376, C3)
{
    std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int res = Solution{}.wiggleMaxLength(nums);
    EXPECT_EQ(res, 2);
}

TEST(T376, C4)
{
    std::vector<int> nums{ 3, 3, 3, 2, 5 };
    int res = Solution{}.wiggleMaxLength(nums);
    EXPECT_EQ(res, 3);
}

TEST(T376, C5)
{
    std::vector<int> nums{ 33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15 };
    int res = Solution{}.wiggleMaxLength(nums);
    EXPECT_EQ(res, 67);
}
