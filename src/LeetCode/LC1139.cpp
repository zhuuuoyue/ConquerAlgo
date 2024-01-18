#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/largest-1-bordered-square/description/
*/

int countOne(const std::vector<std::vector<int>>& lut, int i, int j, int len) {
    int big = lut[i][j];
    int small = i >= len && j >= len ? lut[i - len][j - len] : 0;
    int top = i >= len ? lut[i - len ][j] : 0;
    int down = j >= len ? lut[i][j - len] : 0;
    return big - top - down + small;
}

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        std::vector<std::vector<int>> lut(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int a{ 0 }, b{ 0 }, c{ 0 };
                if (i > 0) { b = lut[i - 1][j]; }
                if (j > 0) { c = lut[i][j - 1]; }
                if (i > 0 && j > 0) { a = lut[i - 1][j - 1]; }
                lut[i][j] = grid[i][j] + b + c - a;
            }
        }

        int ans{ 0 };
        int maxLen = std::min(rows, cols);
        for (int len = 1; len <= maxLen; ++len) {
            for (int i = len - 1; i < rows; ++i) {
                for (int j = len - 1; j < cols; ++j) {
                    int cnt = countOne(lut, i, j, len);
                    if (len <= 2) {
                        if (cnt == len * len) {
                            ans = len;
                        }
                    }
                    else {
                        if (cnt - countOne(lut, i - 1, j - 1, len - 2) == 4 * len - 4) {
                            ans = len;
                        }
                    }
                    if (ans == len) {
                        break;
                    }
                }
                if (ans == len) {
                    break;
                }
            }
        }
        return ans * ans;
    }
};

TEST(T1139, C1) {
    std::vector<std::vector<int>> grid{
        { 1, 1, 1 },
        { 1, 0, 1},
        { 1, 1, 1 }
    };
    int area = Solution().largest1BorderedSquare(grid);
    EXPECT_EQ(9, area);
}

TEST(T1139, C2) {
    std::vector<std::vector<int>> grid{
        { 1, 1, 0, 0 }
    };
    int area = Solution().largest1BorderedSquare(grid);
    EXPECT_EQ(1, area);
}
