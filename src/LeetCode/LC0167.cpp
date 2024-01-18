#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i{ 0 };
        int j{ static_cast<int>(numbers.size()) - 1 };
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum > target) {
                --j;
            }
            else if (sum < target) {
                ++i;
            }
            else {
                return std::vector<int>{ i + 1, j + 1 };
            }
        }
        return std::vector<int>{};
    }
};

TEST(T167, C1) {
    std::vector<int> numbers{ 2, 7, 11, 15 };
    std::vector<int> result = Solution().twoSum(numbers, 9);
    std::vector<int> answer{ 1, 2 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}

TEST(T167, C2) {
    std::vector<int> numbers{ 2, 3, 4 };
    std::vector<int> result = Solution().twoSum(numbers, 6);
    std::vector<int> answer{ 1, 3 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}

TEST(T167, C3) {
    std::vector<int> numbers{ -1, 0 };
    std::vector<int> result = Solution().twoSum(numbers, -1);
    std::vector<int> answer{ 1, 2 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}
