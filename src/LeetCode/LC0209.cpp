#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/minimum-size-subarray-sum/description/
*/

TO_OPTIMISE(zhuoy, 2023-12-29, 超出时间限制，待优化)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len{ 0 };
        for (std::size_t i = 0; i < nums.size(); ++i) {
            int sum{ nums[i] };
            std::size_t j = i + 1;
            while (j < nums.size() && sum < target) {
                sum += nums[j];
                ++j;
            }
            int newLen = static_cast<int>(j - i);
            if (sum < target) {
                continue;
            }
            if (0 == len) {
                len = newLen;
            }
            else if (newLen < len) {
                len = newLen;
            }
        }
        return len;
    }
};

TEST(T209, C1) {
    std::vector<int> nums{ 2, 3, 1, 2, 4, 3 };
    int result = Solution().minSubArrayLen(7, nums);
    EXPECT_EQ(result, 2);
}

TEST(T209, C2) {
    std::vector<int> nums{ 1, 4, 4 };
    int result = Solution().minSubArrayLen(4, nums);
    EXPECT_EQ(result, 1);
}

TEST(T209, C3) {
    std::vector<int> nums{ 1, 1, 1, 1, 1, 1, 1, 1 };
    int result = Solution().minSubArrayLen(11, nums);
    EXPECT_EQ(result, 0);
}
