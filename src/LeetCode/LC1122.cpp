#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/relative-sort-array/description/
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::unordered_map<int, int> m;
        for (int value : arr2) {
            m[value] = 0;
        }
        for (int value : arr1) {
            auto iter = m.find(value);
            if (iter != m.end()) {
                ++iter->second;
            }
        }
        int i = static_cast<int>(arr1.size()) - 1;
        int j = i;
        while (j >= 0) {
            auto iter = m.find(arr1[j]);
            if (iter == m.end()) {
                arr1[i] = arr1[j];
                --i;
            }
            --j;
        }
        auto iter = arr1.begin();
        for (int value : arr2) {
            int j = m[value];
            while (j > 0) {
                *iter = value;
                --j;
                ++iter;
            }
        }
        std::sort(iter, arr1.end());
        return arr1;
    }
};

TEST(T1122, C1) {
    std::vector<int> arr1{ 2,3,1,3,2,4,6,7,9,2,19 };
    std::vector<int> arr2{ 2,1,4,3,9,6 };
    std::vector<int> ans{ 2,2,2,1,4,3,3,9,6,7,19 };
    std::vector<int> ret = Solution().relativeSortArray(arr1, arr2);
    bool eq = equals(ans, ret);
    EXPECT_TRUE(eq);
}
