#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/sum-of-floored-pairs/description/
*/

TO_DO
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        long long sum{ 0 };
        for (std::size_t i = 0; i < nums.size(); ++i) {
            for (std::size_t j = 0; j < nums.size(); ++j) {
                sum += (nums[i] / nums[j]);
            }
        }
        return sum % 1000000007;
    }
};

TEST(T1862, C1) {
    std::vector<int> nums{ 2, 5, 9 };
    int ret = Solution().sumOfFlooredPairs(nums);
    EXPECT_EQ(ret, 10);
}

TEST(T1862, C2) {
    std::vector<int> nums{ 7, 7, 7, 7, 7, 7, 7 };
    int ret = Solution().sumOfFlooredPairs(nums);
    EXPECT_EQ(ret, 49);
}
