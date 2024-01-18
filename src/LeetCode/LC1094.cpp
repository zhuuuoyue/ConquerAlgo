#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/car-pooling/description/
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::vector<int> buffer(1001, 0);
        for (const std::vector<int>& trip : trips) {
            int from = trip[1];
            buffer[from] += trip[0];
            int to = trip[2];
            buffer[to] -= trip[0];
        }
        bool ans{ true };
        for (int i = 0; i < 1001; ++i) {
            buffer[i] += (i ? buffer[i - 1] : 0);
            if (buffer[i] > capacity) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};

TEST(T1094, C1) {
    std::vector<std::vector<int>> trips{ { 2, 1, 5 }, { 3, 3, 7 } };
    EXPECT_FALSE(Solution().carPooling(trips, 4));
}

TEST(T1094, C2) {
    std::vector<std::vector<int>> trips{ { 2, 1, 5 }, { 3, 3, 7 } };
    EXPECT_TRUE(Solution().carPooling(trips, 5));
}
