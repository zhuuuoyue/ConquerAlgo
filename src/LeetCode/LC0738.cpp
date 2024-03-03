#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/monotone-increasing-digits/description/
*/

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // decompose
        std::vector<int> digits;
        while (n)
        {
            digits.emplace_back(n % 10);
            n /= 10;
        }

        // find first digit
        int start{ -1 };
        for (int i = 1; i < digits.size(); ++i)
        {
            if (digits[i] > digits[i - 1])
            {
                start = i;
            }
        }

        // update
        if (start != -1)
        {
            int i = start;
            --digits[i];
            --i;
            while (i >= 0)
            {
                digits[i] = 9;
                --i;
            }

            i = start;
            while (i + 1 < digits.size() && digits[i] < digits[i + 1])
            {
                digits[i] = 9;
                digits[i + 1] -= 1;
                ++i;
            }
        }

        // 
        int res{ 0 };
        int i = (int)digits.size() - 1;
        while (i >= 0)
        {
            res = res * 10 + digits[i];
            --i;
        }
        return res;
    }
};

TEST(T738, C1)
{
    int res = Solution{}.monotoneIncreasingDigits(10);
    EXPECT_EQ(res, 9);
}

TEST(T738, C2)
{
    int res = Solution{}.monotoneIncreasingDigits(1234);
    EXPECT_EQ(res, 1234);
}

TEST(T738, C3)
{
    int res = Solution{}.monotoneIncreasingDigits(332);
    EXPECT_EQ(res, 299);
}

TEST(T738, C4)
{
    int res = Solution{}.monotoneIncreasingDigits(668841);
    EXPECT_EQ(res, 667999);
}

TEST(T738, C5)
{
    int res = Solution{}.monotoneIncreasingDigits(999998);
    EXPECT_EQ(res, 899999);
}
