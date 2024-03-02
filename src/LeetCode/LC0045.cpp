#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/jump-game-ii/description/
*/

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int steps = 0;
        int current = 0;
        int ii = nums.size() - 1;
        while (current + 1 < nums.size())
        {
            int next = current;
            int further = 0;
            for (int offset = 1; offset <= nums[current]; ++offset)
            {
                int nextCandidate = current + offset;
                int nextStep = 0;
                if (nextCandidate < nums.size())
                {
                    nextStep = nums[nextCandidate];
                }
                if (nextCandidate + nextStep >= further || nextCandidate + nextStep >= ii)
                {
                    int furtherCandidate = nextCandidate + nextStep;
                    next = nextCandidate;
                    further = furtherCandidate;
                }
            }
            current = next;
            ++steps;
        }
        return steps;
    }
};

TEST(T45, C1)
{
    std::vector<int> nums{ 2, 3, 1, 1, 4 };
    int res = Solution{}.jump(nums);
    EXPECT_EQ(res, 2);
}

TEST(T45, C2)
{
    std::vector<int> nums{ 2, 3, 0, 1, 4 };
    int res = Solution{}.jump(nums);
    EXPECT_EQ(res, 2);
}

TEST(T45, C3)
{
    std::vector<int> nums{ 2, 1 };
    int res = Solution{}.jump(nums);
    EXPECT_EQ(res, 1);
}

TEST(T45, C4)
{
    std::vector<int> nums{ 3, 2, 1 };
    int res = Solution{}.jump(nums);
    EXPECT_EQ(res, 1);
}

TEST(T45, C5)
{
    std::vector<int> nums{ 2, 3, 1 };
    int res = Solution{}.jump(nums);
    EXPECT_EQ(res, 1);
}
