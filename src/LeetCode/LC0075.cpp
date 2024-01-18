#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
* https://leetcode.cn/problems/sort-colors/description/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::size_t R{ 0 }, W{ 0 }, B{ 0 };
        for (int num : nums) {
            if (num == 0) { ++R; }
            else if (num == 1) { ++W; }
            else if (num == 2) { ++B; }
        }
        B = R + W;
        W = R;
        R = 0;
        const std::size_t N = nums.size();
        std::size_t r = R;
        std::size_t w = W;
        std::size_t b = B;
        while (r < N && nums[r] == 0) { ++r; }
        while (w < N && nums[w] == 1) { ++w; }
        while (b < N && nums[b] == 2) { ++b; }

        while (r < W) {
            if (nums[r] == 0) {
                ++r;
                continue;
            }
            if (nums[r] != 0) {
                if (1 == nums[r]) {
                    std::swap(nums[r], nums[w]);
                    ++w;
                }
                else if (2 == nums[r]) {
                    std::swap(nums[r], nums[b]);
                    ++b;
                }
            }
        }

        while (w < B) {
            if (nums[w] == 1) {
                ++w;
                continue;
            }
            if (nums[w] != 1) {
                if (2 == nums[w]) {
                    std::swap(nums[w], nums[b]);
                    ++b;
                }
            }
        }
    }
};

TEST(T75, C1) {
    std::vector<int> nums{ 2, 0, 2, 1, 1, 0 };
    std::vector<int> answer{ 0, 0, 1, 1, 2, 2 };
    Solution().sortColors(nums);
    bool eq = equals(nums, answer);
    EXPECT_TRUE(eq);
}

TEST(T75, C2) {
    std::vector<int> nums{ 2, 0, 1 };
    std::vector<int> answer{ 0, 1, 2 };
    Solution().sortColors(nums);
    bool eq = equals(nums, answer);
    EXPECT_TRUE(eq);
}
