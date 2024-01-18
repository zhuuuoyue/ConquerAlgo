#include "gtest/gtest.h"

/*
* https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/
*/

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        std::size_t dst{ 0 }, cur{ 0 };
        const std::size_t N = nums.size();
        while (dst < N && cur < N) {
            std::size_t end{ cur };
            while (end < N && nums[cur] == nums[end]) { ++end; }
            std::size_t e = std::min(cur + 2, end);
            while (cur < e) {
                nums[dst] = nums[cur];
                ++cur;
                ++dst;
            }
            cur = end;
        }
        return static_cast<int>(dst);
    }
};

TEST(T80, C1) {
    std::vector<int> nums{ 1, 1, 1, 2, 2, 3 };
    int ret = Solution().removeDuplicates(nums);
    EXPECT_EQ(ret, 5);
}

TEST(T80, C2) {
    std::vector<int> nums{ 0, 0, 1, 1, 1, 1, 2, 3, 3 };
    int ret = Solution().removeDuplicates(nums);
    EXPECT_EQ(ret, 7);
}
