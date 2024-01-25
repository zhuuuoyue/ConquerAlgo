#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
 * https://leetcode.cn/problems/powx-n/description/
 */

class Solution {
public:
    double myPow(double x, int n) {
        if (std::abs(x) < 0.0000001)
        {
            return 0;
        }
        double res{ 1 };
        bool neg = n < 0;
        while (n != 0)
        {
            if (n % 2 != 0)
            {
                res *= x;
            }
            x *= x;
            n /= 2;
        }
        return neg ? 1 / res : res;
    }
};

TEST(T50, C1)
{
    const double res = Solution{}.myPow(2, 10);
    EXPECT_DOUBLE_EQ(res, 1024);
}

TEST(T50, C2)
{
    const double res = Solution{}.myPow(2.1, 3);
    EXPECT_DOUBLE_EQ(res, 9.261);
}

TEST(T50, C3)
{
    const double res = Solution{}.myPow(2, -2);
    EXPECT_DOUBLE_EQ(res, 0.25);
}
