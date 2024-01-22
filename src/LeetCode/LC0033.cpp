#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) { return -1; }
        if (nums.front() == target) { return 0; }
        int last{ static_cast<int>(nums.size()) - 1 };
        if (nums.back() == target) { return last; }
        int first{ 0 };
        while (first <= last) {
            const int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[first])
            {
                if (target > nums[mid])
                {
                    first = mid + 1;
                }
                else
                {
                    if (nums[first] == target)
                    {
                        return first;
                    }
                    if (nums[first] < target)
                    {
                        last = mid - 1;
                    }
                    else
                    {
                        first = mid + 1;
                    }
                }
            }
            else
            {
                if (target < nums[mid])
                {
                    last = mid - 1;
                }
                else
                {
                    if (nums[last] == target)
                    {
                        return last;
                    }
                    if (nums[last] > target)
                    {
                        first = mid + 1;
                    }
                    else
                    {
                        last = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};

TEST(T33, C1)
{
    std::vector<int> nums{ 4, 5, 6, 7, 0, 1, 2 };
    const int result = Solution{}.search(nums, 0);
    constexpr int answer = 4;
    EXPECT_EQ(result, answer);
}

TEST(T33, C2)
{
    std::vector<int> nums{ 4, 5, 6, 7, 0, 1, 2 };
    const int result = Solution{}.search(nums, 3);
    constexpr int answer = -1;
    EXPECT_EQ(result, answer);
}

TEST(T33, C3)
{
    std::vector<int> nums{ 1 };
    const int result = Solution{}.search(nums, 0);
    constexpr int answer = -1;
    EXPECT_EQ(result, answer);
}
