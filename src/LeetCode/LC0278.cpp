#include "gtest/gtest.h"
#include "LeetCode.hpp"

/**
 * https://leetcode.cn/problems/first-bad-version/description/
 */

class Solution {
public:
    int _bad_version{ 0 };
    Solution(int bad_version) : _bad_version{ bad_version } {}
    bool isBadVersion(int n) const { return n >= _bad_version; }
    int firstBadVersion(int n) {
        int first = 0;
        int last = n;
        while (first < last) {
            const int mid = first + (last - first) / 2;
            if (isBadVersion(mid)) {
                last = mid;
            }
            else {
                first = mid + 1;
            }
        }
        return first;
    }
};

TEST(T278, C1)
{
    int res = Solution{ 4 }.firstBadVersion(5);
    EXPECT_EQ(res, 4);
}

TEST(T278, C2)
{
    int res = Solution{ 1 }.firstBadVersion(1);
    EXPECT_EQ(res, 1);
}
