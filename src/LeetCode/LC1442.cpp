#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        std::vector<int> temp{ arr.front() ^ 0 };
        for (int i = 1; i < arr.size(); ++i) {
            temp.emplace_back(arr[i] ^ temp.back());
        }
        int ans{ 0 };
        for (int i = 0; i < temp.size(); ++i) {
            int iv = i ? temp[i - 1] : 0;
            for (int k = i + 1; k < temp.size(); ++k) {
                if ((iv ^ temp[k]) == 0) {
                    ans += (k - i);
                }
            }
        }
        return ans;
    }
};

TEST(T1442, C1) {
    std::vector<int> arr{ 2, 3, 1, 6, 7 };
    int ans = Solution().countTriplets(arr);
    int ref = 4;
    EXPECT_EQ(ans, ref);
}

TEST(T1442, C2) {
    std::vector<int> arr{ 1, 1, 1, 1, 1 };
    int ans = Solution().countTriplets(arr);
    int ref = 10;
    EXPECT_EQ(ans, ref);
}

TEST(T1442, C3) {
    std::vector<int> arr{ 2, 3 };
    int ans = Solution().countTriplets(arr);
    int ref = 0;
    EXPECT_EQ(ans, ref);
}

TEST(T1442, C4) {
    std::vector<int> arr{ 1, 3, 5, 7, 9 };
    int ans = Solution().countTriplets(arr);
    int ref = 3;
    EXPECT_EQ(ans, ref);
}

TEST(T1442, C5) {
    std::vector<int> arr{ 7, 11, 12, 9, 5, 2, 7, 17, 22 };
    int ans = Solution().countTriplets(arr);
    int ref = 8;
    EXPECT_EQ(ans, ref);
}
