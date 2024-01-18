#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/corporate-flight-bookings/description/
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        std::vector<int> ans(n, 0);
        for (const std::vector<int>& booking : bookings) {
            int start = booking[0] - 1;
            ans[start] += booking[2];
            int end = booking[1];
            if (end < n) {
                ans[end] -= booking[2];
            }
        }
        for (int i = 1; i < ans.size(); ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};

TEST(T1109, C1) {
    std::vector<std::vector<int>> bookings{ { 1, 2, 10 }, { 2, 3, 20 }, { 2, 5, 25 } };
    std::vector<int> ans = Solution().corpFlightBookings(bookings, 5);
    std::vector<int> ref{ 10, 55, 45, 25, 25 };
    bool eq = equals(ans, ref);
    EXPECT_TRUE(eq);
}

TEST(T1109, C2) {
    std::vector<std::vector<int>> bookings{ { 1, 2, 10 }, { 2, 2, 15 } };
    std::vector<int> ans = Solution().corpFlightBookings(bookings, 2);
    std::vector<int> ref{ 10, 25 };
    bool eq = equals(ans, ref);
    EXPECT_TRUE(eq);
}
