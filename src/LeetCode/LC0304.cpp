#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
*/

class NumMatrix {
private:
    std::vector<std::vector<int>> m_data;
public:
    NumMatrix(vector<vector<int>>& matrix) : m_data{ matrix } {
        int rows = m_data.size();
        int cols = m_data.front().size();
        for (int i = 1; i < rows; ++i) {
            m_data[i][0] = m_data[i - 1][0] + m_data[i][0];
        }
        for (int j = 1; j < cols; ++j) {
            m_data[0][j] = m_data[0][j - 1] + m_data[0][j];
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                m_data[i][j] = m_data[i - 1][j] + m_data[i][j - 1] - m_data[i - 1][j - 1] + m_data[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int d = m_data[row2][col2];
        int c = 0;
        if (0 != col1) { c = m_data[row2][col1 - 1]; }
        int b = 0;
        if (0 != row1) { b = m_data[row1 - 1][col2]; }
        int a = 0;
        if (0 != row1 && 0 != col1) { a = m_data[row1 - 1][col1 - 1]; }
        return d - c - b + a;
    }
};

TEST(T304, C1) {
    std::vector<std::vector<int>> matrix{
        { 3, 0, 1, 4, 2 },
        { 5, 6, 3, 2, 1 },
        { 1, 2, 0, 1, 5 },
        { 4, 1, 0, 1, 7 },
        { 1, 0, 3, 0, 5 }
    };
    NumMatrix nm(matrix);

    int ret = nm.sumRegion(2, 1, 4, 3);
    EXPECT_EQ(ret, 8);

    ret = nm.sumRegion(1, 1, 2, 2);
    EXPECT_EQ(ret, 11);

    ret = nm.sumRegion(1, 2, 2, 4);
    EXPECT_EQ(ret, 12);
}
