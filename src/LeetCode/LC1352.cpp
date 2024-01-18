#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/product-of-the-last-k-numbers/description/
*/

class ProductOfNumbers {
private:
    std::vector<int> m_data;
    std::vector<int> m_nums;
public:
    ProductOfNumbers() {
        m_data.push_back(1);
    }

    void add(int num) {
        m_data.emplace_back(m_data.back() * num);
        m_nums.emplace_back(num);
    }

    int getProduct(int k) {
        int previous = m_data[m_data.size() - k - 1];
        if (previous != 0) { return m_data.back() / previous; }
        int ret{ 1 };
        while (k > 0) {
            ret *= m_nums[m_nums.size() - k];
            --k;
        }
        return ret;
    }
};

TEST(T1352, C1) {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]

    int ret = productOfNumbers.getProduct(2); // ���� 20 ����� 2 �����ֵĳ˻��� 5 * 4 = 20
    EXPECT_EQ(ret, 20);
    ret = productOfNumbers.getProduct(3); // ���� 40 ����� 3 �����ֵĳ˻��� 2 * 5 * 4 = 40
    EXPECT_EQ(ret, 40);
    ret = productOfNumbers.getProduct(4); // ����  0 ����� 4 �����ֵĳ˻��� 0 * 2 * 5 * 4 = 0
    EXPECT_EQ(ret, 0);

    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    ret = productOfNumbers.getProduct(2); // ���� 32 ����� 2 �����ֵĳ˻��� 4 * 8 = 32 
    EXPECT_EQ(ret, 32);
}
