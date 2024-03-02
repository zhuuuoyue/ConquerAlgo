#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/construct-k-palindrome-strings/description/
*/

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        std::unordered_map<char, int> m;
        for (char c : s)
        {
            auto iter = m.find(c);
            if (iter == m.end())
            {
                m[c] = 1;
            }
            else
            {
                ++m[c];
            }
        }
        int odd{ 0 };
        int even{ 0 };
        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if (iter->second % 2)
            {
                ++odd;
            }
            else
            {
                ++even;
            }
        }
        if (odd > k)
        {
            return false;
        }
        return s.size() >= k;
    }
};

TEST(T1400, C1)
{
    std::string s{ "annabelle" };
    bool can = Solution{}.canConstruct(s, 2);
    EXPECT_TRUE(can);
}

TEST(T1400, C2)
{
    std::string s{ "leetcode" };
    bool can = Solution{}.canConstruct(s, 3);
    EXPECT_FALSE(can);
}

TEST(T1400, C3)
{
    std::string s{ "true" };
    bool can = Solution{}.canConstruct(s, 4);
    EXPECT_TRUE(can);
}

TEST(T1400, C4)
{
    std::string s{ "yzyzyzyzyzyzyzy" };
    bool can = Solution{}.canConstruct(s, 2);
    EXPECT_TRUE(can);
}

TEST(T1400, C5)
{
    std::string s{ "cr" };
    bool can = Solution{}.canConstruct(s, 7);
    EXPECT_FALSE(can);
}
