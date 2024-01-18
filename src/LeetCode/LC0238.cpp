#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/product-of-array-except-self/description/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> ans(nums.size(), 0);
        if (nums.empty()) { return ans; }
        const int N = nums.size();

        for (int i = 0; i < N; ++i) {
            if (i == 0) { ans[i] = nums[i]; }
            else { ans[i] = ans[i - 1] * nums[i]; }
        }
        int suffix{ 1 };
        for (int i = N - 1; i >= 0; --i) {
            if (i != N - 1) { suffix *= nums[i + 1]; }
            int prefix = 0 == i ? 1 : ans[i - 1];
            ans[i] = prefix * suffix;
        }

        return ans;
    }
};

TEST(T238, C1) {
    std::vector<int> nums{ 1, 2, 3, 4 };
    std::vector<int> ans = Solution().productExceptSelf(nums);
    std::vector<int> ref{ 24, 12, 8, 6 };
    bool eq = equals(ans, ref);
    EXPECT_TRUE(eq);
}

TEST(T238, C2) {
    std::vector<int> nums{ -1, 1, 0, -3, 3 };
    std::vector<int> ans = Solution().productExceptSelf(nums);
    std::vector<int> ref{ 0, 0, 9, 0, 0 };
    bool eq = equals(ans, ref);
    EXPECT_TRUE(eq);
}
