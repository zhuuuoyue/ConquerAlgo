#include "gtest/gtest.h"
#include "LeetCode.hpp"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int count{ 0 };
        std::sort(points.begin(), points.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) -> bool
            {
                return lhs.front() < rhs.front();
            }
        );
        for (int i = 0; i < points.size();)
        {
            int _min = points[i].front();
            int _max = points[i].back();
            ++i;
            while (i < points.size())
            {
                if (points[i].front() > _max)
                {
                    break;
                }
                else
                {
                    _min = std::max(_min, points[i].front());
                    _max = std::min(_max, points[i].back());
                    ++i;
                }
            }
            ++count;
        }
        return count;
    }
};

TEST(T452, C1)
{
    std::vector<std::vector<int>> points
    {
        { 10, 16 },
        { 2, 8 },
        { 1, 6 },
        { 7, 12 }
    };
    int res = Solution{}.findMinArrowShots(points);
    EXPECT_EQ(res, 2);
}

TEST(T452, C2)
{
    std::vector<std::vector<int>> points
    {
        { 1, 2 },
        { 3, 4 },
        { 5, 6 },
        { 7, 8 }
    };
    int res = Solution{}.findMinArrowShots(points);
    EXPECT_EQ(res, 4);
}

TEST(T452, C3)
{
    std::vector<std::vector<int>> points
    {
        { 1, 2 },
        { 2, 3 },
        { 3, 4 },
        { 4, 5 }
    };
    int res = Solution{}.findMinArrowShots(points);
    EXPECT_EQ(res, 2);
}
