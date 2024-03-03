#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/description/
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back())
        {
            return nums.front();
        }
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[right])
            {
                --right;
            }
            else if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

TEST(T154, C1)
{
    std::vector<int> nums{ 1, 3, 5 };
    int res = Solution{}.findMin(nums);
    EXPECT_EQ(res, 1);
}

TEST(T154, C2)
{
    std::vector<int> nums{ 2, 2, 2, 0, 1 };
    int res = Solution{}.findMin(nums);
    EXPECT_EQ(res, 0);
}
