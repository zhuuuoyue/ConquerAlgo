#include "gtest/gtest.h"
#include "LeetCode.hpp"
#include "compare.hpp"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::vector<std::vector<int>> res;
        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) -> bool
            {
                return lhs.front() < rhs.front();
            }
        );
        int i = 0;
        while (i < intervals.size())
        {
            int left = intervals[i].front();
            int right = intervals[i].back();
            ++i;
            while (i < intervals.size())
            {
                if (intervals[i].front() > right)
                {
                    break;
                }
                else
                {
                    right = std::max(intervals[i].back(), right);
                    ++i;
                }
            }
            res.emplace_back(std::vector<int>{ left, right });
        }
        return res;
    }
};

TEST(T56, C1)
{
    std::vector<std::vector<int>> intervals
    {
        { 1, 3 },
        { 2, 6 },
        { 8, 10 },
        { 15, 18 }
    };
    std::vector<vector<int>> res = Solution{}.merge(intervals);
    EXPECT_EQ(res.size(), 3);
    bool eq = equals<int>(res[0], std::vector<int>{1, 6});
    EXPECT_TRUE(eq);
    eq = equals<int>(res[1], std::vector<int>{8, 10});
    EXPECT_TRUE(eq);
    eq = equals<int>(res[2], std::vector<int>{15, 18});
    EXPECT_TRUE(eq);
}

TEST(T56, C2)
{
    std::vector<std::vector<int>> intervals
    {
        { 1, 4 },
        { 4, 5 }
    };
    std::vector<vector<int>> res = Solution{}.merge(intervals);
    EXPECT_EQ(res.size(), 1);
    bool eq = equals<int>(res[0], std::vector<int>{1, 5});
    EXPECT_TRUE(eq);
}
