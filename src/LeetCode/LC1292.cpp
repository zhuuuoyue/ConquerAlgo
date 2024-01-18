#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/
*/

int sum(const std::vector<std::vector<int>>& lut, int i, int j, int len) {
    int big = lut[i][j];
    int small = i >= len && j >= len ? lut[i - len][j - len] : 0;
    int top = i >= len ? lut[i - len][j] : 0;
    int down = j >= len ? lut[i][j - len] : 0;
    return big - top - down + small;
}

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat.front().size();
        std::vector<std::vector<int>> lut(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int a{ 0 }, b{ 0 }, c{ 0 };
                if (i > 0) { b = lut[i - 1][j]; }
                if (j > 0) { c = lut[i][j - 1]; }
                if (i > 0 && j > 0) { a = lut[i - 1][j - 1]; }
                lut[i][j] = mat[i][j] + b + c - a;
            }
        }

        int maxLen = std::min(rows, cols);
        for (int len = maxLen; len >= 1; --len) {
            for (int i = rows - 1; i + 1 >= len; --i) {
                for (int j = cols - 1; j + 1 >= len; --j) {
                    int s = sum(lut, i, j, len);
                    if (s <= threshold) {
                        return len;
                    }
                }
            }
        }
        return 0;
    }
};

TEST(T1292, C1) {
    std::vector<std::vector<int>> mat{
        { 1, 1, 3, 2, 4, 3, 2 },
        { 1, 1, 3, 2, 4, 3, 2 },
        { 1, 1, 3, 2, 4, 3, 2 }
    };
    int len = Solution().maxSideLength(mat, 4);
    EXPECT_EQ(len, 2);
}

TEST(T1292, C2) {
    std::vector<std::vector<int>> mat{
        { 2, 2, 2, 2, 2 },
        { 2, 2, 2, 2, 2 },
        { 2, 2, 2, 2, 2 },
        { 2, 2, 2, 2, 2 },
        { 2, 2, 2, 2, 2 }
    };
    int len = Solution().maxSideLength(mat, 1);
    EXPECT_EQ(len, 0);
}
