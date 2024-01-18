#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/range-sum-query-immutable/description/
*/

class NumArray {
private:
    std::vector<int> m_data;
public:
    NumArray(vector<int>& nums) : m_data{ nums } {
        for (std::size_t index = 1; index < m_data.size(); ++index) {
            m_data[index] = m_data[index] + m_data[index - 1];
        }
    }

    int sumRange(int left, int right) {
        return 0 == left ? m_data[right] : (m_data[right] - m_data[left - 1]);
    }
};

TEST(T303, C1) {
    std::vector<int> nums{ -2, 0, 3, -5, 2, -1 };
    NumArray arr(nums);

    int a = arr.sumRange(0, 2);
    EXPECT_EQ(a, 1);

    int b = arr.sumRange(2, 5);
    EXPECT_EQ(b, -1);

    int c = arr.sumRange(0, 5);
    EXPECT_EQ(c, -3);
}
