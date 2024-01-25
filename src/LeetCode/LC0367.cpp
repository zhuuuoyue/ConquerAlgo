#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
 * https://leetcode.cn/problems/valid-perfect-square/description/
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;;
        int right = num;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid == 0)
            {
                return false;
            }
            if (num % mid == 0 && num / mid == mid)
            {
                return true;
            }
            else if (mid < num / mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

TEST(T367, C1)
{
    bool res = Solution{}.isPerfectSquare(16);
    EXPECT_TRUE(res);
}

TEST(T367, C2)
{
    bool res = Solution{}.isPerfectSquare(14);
    EXPECT_FALSE(res);
}

TEST(T367, C3)
{
    bool res = Solution{}.isPerfectSquare(1);
    EXPECT_TRUE(res);
}
