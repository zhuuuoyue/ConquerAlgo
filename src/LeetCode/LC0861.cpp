#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/score-after-flipping-matrix/description/
*/

class Solution
{
public:
    int matrixScore(vector<vector<int>>& grid)
    {
        const int ROWS = grid.size();
        const int COLS = grid.front().size();

        for (int i = 0; i < ROWS; ++i)
        {
            std::vector<int>& row = grid[i];
            if (row.front() == 0)
            {
                for (int j = 0; j < COLS; ++j)
                {
                    row[j] = 1 - row[j];
                }
            }
        }

        int res{ 0 };
        int base{ 1 };
        for (int i = COLS - 1; i >= 0; --i)
        {
            int ones{ 0 };
            for (int j = 0; j < ROWS; ++j)
            {
                if (grid[j][i] == 1)
                {
                    ++ones;
                }
            }
            int zeros = ROWS - ones;
            if (ones >= zeros)
            {
                res += (base * ones);
            }
            else
            {
                res += (base * zeros);
            }
            base *= 2;
        }
        return res;
    }
};

TEST(T861, C1)
{
    std::vector<std::vector<int>> grid
    {
        { 0, 0, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 0 },
    };
    int res = Solution{}.matrixScore(grid);
    EXPECT_EQ(res, 39);
}

TEST(T861, C2)
{
    std::vector<std::vector<int>> grid
    {
        { 0 }
    };
    int res = Solution{}.matrixScore(grid);
    EXPECT_EQ(res, 1);
}
