#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
 *https://leetcode.cn/problems/binary-search/description/
 */

namespace iteration
{
    class Solution {
    public:
        int search(vector<int>& nums, int target)
        {
            int first{ 0 };
            int last{ static_cast<int>(nums.size()) - 1 };
            while (first <= last)
            {
                const int mid = first + (last - first) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                if (nums[mid] < target)
                {
                    first = mid + 1;
                }
                else
                {
                    last = mid - 1;
                }
            }
            return -1;
        }
    };
}

namespace recursion
{
    class Solution {
    public:
        int search(vector<int>& nums, int target)
        {
            return find(nums, 0, static_cast<int>(nums.size()) - 1, target);
        }
        int find(const vector<int>& nums, int first, int last, int target) const
        {
            if (first > last)
            {
                return -1;
            }
            const int mid = first + (last - first) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                return find(nums, mid + 1, last, target);
            }
            return find(nums, first, mid - 1, target);
        }
    };
}

using namespace recursion;

TEST(T704, C1)
{
    std::vector<int> nums{ -1, 0, 3, 5, 9, 12 };
    constexpr int answer{ 4 };
    const int result = Solution{}.search(nums, 9);
    EXPECT_EQ(answer, result);
}

TEST(T704, C2)
{
    std::vector<int> nums{ -1, 0, 3, 5, 9, 12 };
    constexpr int answer{ -1 };
    const int result = Solution{}.search(nums, 2);
    EXPECT_EQ(answer, result);
}

TEST(T704, C3)
{
    std::vector<int> nums{ -1 };
    constexpr int answer{ -1 };
    const int result = Solution{}.search(nums, 2);
    EXPECT_EQ(answer, result);
}
