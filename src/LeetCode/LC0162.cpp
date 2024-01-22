#include "gtest/gtest.h"
#include "LeetCode.hpp"

/**
 * https://leetcode.cn/problems/find-peak-element/description/
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                if (left == mid)
                {
                    return nums[left] > nums[right] ? left : right;
                }
                left = mid;
            }
        }
        return left;
    }
};

TEST(T162, C1)
{
    std::vector<int> nums{ 1, 2, 3, 1 };
    const int res = Solution{}.findPeakElement(nums);
    EXPECT_EQ(res, 2);
}

TEST(T162, C2)
{
    std::vector<int> nums{ 1, 2, 1, 3, 5, 6, 4 };
    const int res = Solution{}.findPeakElement(nums);
    const bool cmp = res == 1 || res == 5;
    EXPECT_TRUE(cmp);
}
