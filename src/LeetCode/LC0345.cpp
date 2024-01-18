#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
*/

bool isAEIOU(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty()) { return s; }
        int i = 0;
        int j = static_cast<int>(s.size()) - 1;
        while (i < j) {
            while (i < j && !isAEIOU(s[i])) { ++i; }
            while (j > i && !isAEIOU(s[j])) { --j; }
            std::swap(s[i], s[j]);
            ++i;
            --j;
        }
        return s;
    }
};

TEST(T345, C1) {
    std::string s{ "hello" };
    std::string answer{ "holle" };
    s = Solution().reverseVowels(s);
    EXPECT_EQ(s, answer);
}

TEST(T345, C2) {
    std::string s{ "leetcode" };
    std::string answer{ "leotcede" };
    s = Solution().reverseVowels(s);
    EXPECT_EQ(s, answer);
}

TEST(T345, C3) {
    std::string s{ "a." };
    std::string answer{ "a." };
    s = Solution().reverseVowels(s);
    EXPECT_EQ(s, answer);
}
