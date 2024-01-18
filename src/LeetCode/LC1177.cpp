#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/can-make-palindrome-from-substring/description/
*/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        std::vector<std::vector<std::size_t>> lut(26, std::vector<std::size_t>(s.size(), 0));
        for (std::size_t i = 0; i < s.size(); ++i) {
            std::size_t j = s[i] - 'a';
            for (std::size_t k = 0; k < 26; ++k) {
                if (k == j) {
                    lut[k][i] = 0 == i ? 1 : (lut[k][i - 1] + 1);
                }
                else {
                    lut[k][i] = 0 == i ? 0 : lut[k][i - 1];
                }
            }
        }
        std::vector<bool> ret;
        for (const std::vector<int>& query : queries) {
            std::size_t ogg{ 0 };
            for (std::size_t i = 0; i < 26; ++i) {
                std::size_t c = query[0] ? (lut[i][query[1]] - lut[i][query[0] - 1]) : lut[i][query[1]];
                if (c % 2) { ++ogg; }
            }
            ret.emplace_back((query[2] * 2 + 1) >= ogg);
        }
        return ret;
    }
};

TEST(T1177, C1) {
    std::vector<bool> answer{ true, false, false, true, true };
    std::vector<std::vector<int>> queries{
        std::vector<int>{ 3, 3, 0 },
        std::vector<int>{ 1, 2, 0 },
        std::vector<int>{ 0, 3, 1 },
        std::vector<int>{ 0, 3, 2 },
        std::vector<int>{ 0, 4, 1 }
    };
    std::vector<bool> result = Solution().canMakePaliQueries("abcda", queries);
    bool eq = equals(answer, result);
    EXPECT_TRUE(eq);
}
