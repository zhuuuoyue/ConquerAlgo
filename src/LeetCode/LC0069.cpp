#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
 *https://leetcode.cn/problems/sqrtx/description/
 */

class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) {
            return 0;
        }
        double guess = x / 2.0;
        constexpr double tol = 0.000001;
        while (abs(x - guess * guess) > tol) {
            guess = (guess + x / guess) / 2;
        }
        return static_cast<int>(guess);
    }
};
TEST(T69, C1)
{
    constexpr int answer{ 2 };
    const int result = Solution{}.mySqrt(4);
    EXPECT_EQ(answer, result);
}

TEST(T69, C2)
{
    constexpr int answer{ 2 };
    const int result = Solution{}.mySqrt(8);
    EXPECT_EQ(answer, result);
}
