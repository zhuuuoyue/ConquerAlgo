#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/
*/

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count{ 0 };
        std::stack<char> lefts;
        for (char c : s)
        {
            if (c == '(')
            {
                lefts.push(c);
            }
            else
            {
                if (lefts.empty())
                {
                    ++count;
                }
                else
                {
                    lefts.pop();
                }
            }
        }
        count += lefts.size();
        return count;
    }
};

TEST(T921, C1)
{
    std::string s{ "())" };
    int res = Solution{}.minAddToMakeValid(s);
    EXPECT_EQ(res, 1);
}

TEST(T921, C2)
{
    std::string s{ "(((" };
    int res = Solution{}.minAddToMakeValid(s);
    EXPECT_EQ(res, 3);
}
