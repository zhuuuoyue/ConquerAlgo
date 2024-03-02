#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/is-subsequence/description/
*/

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;
        int j = 0;
        while (i < s.size())
        {
            while (j < t.size() && t[j] != s[i])
            {
                ++j;
            }
            if (j == t.size())
            {
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
};

TEST(T392, C1)
{
    std::string s{ "abc" };
    std::string t{ "ahbgdc" };
    bool yes = Solution{}.isSubsequence(s, t);
    EXPECT_TRUE(yes);
}

TEST(T392, C2)
{
    std::string s{ "axc" };
    std::string t{ "ahbgdc" };
    bool yes = Solution{}.isSubsequence(s, t);
    EXPECT_FALSE(yes);
}
