#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
*/

TO_OPTIMISE(zhuoy, 2023-12-29, 超出时间限制)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::stack<int> tops;
        for (int num : nums) {
            std::stack<int> temp;
            while (!tops.empty() && tops.top() < num) {
                temp.push(tops.top());
                tops.pop();
            }
            if (tops.size() < k) {
                tops.push(num);
            }
            while (!temp.empty() && tops.size() < k) {
                tops.push(temp.top());
                temp.pop();
            }
        }
        return tops.top();
    }
};

TEST(T215, C1) {
    std::vector<int> nums{ 3, 2, 1, 5, 6, 4 };
    int k = 2;
    int answer{ 5 };
    int result = Solution().findKthLargest(nums, k);
    EXPECT_EQ(answer, result);
}

TEST(T215, C2) {
    std::vector<int> nums{ 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    int k = 4;
    int answer{ 4 };
    int result = Solution().findKthLargest(nums, k);
    EXPECT_EQ(answer, result);
}
