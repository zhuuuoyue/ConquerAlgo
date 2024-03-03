#include "gtest/gtest.h"
#include "LeetCode.hpp"

/*
 * https://leetcode.cn/problems/find-smallest-letter-greater-than-target/description/
 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        const int N = static_cast<int>(letters.size());
        int right = N - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mid + 1 < N)
            {
                if (letters[mid] <= target && letters[mid + 1] > target)
                {
                    return letters[mid + 1];
                }
            }
            if (letters[mid] > target)
            {
                right = mid;
            }
            else if (letters[mid] <= target)
            {
                left = mid + 1;
            }
        }
        return letters.front();
    }
};

TEST(T744, C1)
{
    std::vector<char> letters{ 'c', 'f', 'j' };
    char res = Solution{}.nextGreatestLetter(letters, 'a');
    EXPECT_EQ(res, 'c');
}

TEST(T744, C2)
{
    std::vector<char> letters{ 'c', 'f', 'j' };
    char res = Solution{}.nextGreatestLetter(letters, 'c');
    EXPECT_EQ(res, 'f');
}

TEST(T744, C3)
{
    std::vector<char> letters{ 'x', 'x', 'y', 'y'};
    char res = Solution{}.nextGreatestLetter(letters, 'z');
    EXPECT_EQ(res, 'x');
}
