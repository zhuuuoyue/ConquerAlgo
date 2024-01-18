#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/flip-string-to-monotone-increasing/description/
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        if (s.empty()) { return 0; }
        const int N = s.size();

        std::vector<int> pre(N, 0);
        if (s.front() == '1') { pre.front() = 1; }
        for (int i = 1; i < N; ++i) {
            pre[i] = pre[i - 1] + (s[i] == '1' ? 1 : 0);
        }

        std::vector<int> post(N, 0);
        if (s.back() == '0') { post.back() = 1; }
        for (int i = N - 2; i >= 0; --i) {
            post[i] = post[i + 1] + (s[i] == '0' ? 1 : 0);
        }

        int ans = pre.back();
        for (int i = 0; i < N; ++i) {
            int expectedZero = i;
            int expectedOne = N - i;
            int newAns = pre.back();
            if (0 == i) {
                newAns = post[0];
            }
            else if (N - 1 == i) {
                newAns = pre[i - 1] + post[i];
            }
            else {
                newAns = pre[i - 1] + post[i];
            }
            if (newAns < ans) {
                ans = newAns;
            }
        }
        return ans;
    }
};

TEST(T926, C1) {
    std::string s("00110");
    int ret = Solution().minFlipsMonoIncr(s);
    EXPECT_EQ(ret, 1);
}

TEST(T926, C2) {
    std::string s("010110");
    int ret = Solution().minFlipsMonoIncr(s);
    EXPECT_EQ(ret, 2);
}

TEST(T926, C3) {
    std::string s("00011000");
    int ret = Solution().minFlipsMonoIncr(s);
    EXPECT_EQ(ret, 2);
}
