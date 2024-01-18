#include "gtest/gtest.h"
#include "Sort.hpp"
#include "compare.hpp"
#include <algorithm>
#include <functional>

class SortTestBase : public testing::Test {
public:
    void init(const std::vector<int>& items) {
        for (int item : items) {
            a.emplace_back(item);
            b.emplace_back(item);
        }
        std::sort(a.begin(), a.end(), std::less<int>());
    }
protected:
    std::vector<int> a;
    std::vector<int> b;
};

class SortTestA : public SortTestBase {
public:
    virtual void SetUp() override {
        init({ 3, 1, 4, 1, 5, 9, 2, 6 });
    }
};

TEST_F(SortTestA, BubbleSort) {
    bubbleSort(b);
    EXPECT_TRUE(equals(a, b));
}

TEST_F(SortTestA, SelectionSort) {
    selectionSort(b);
    EXPECT_TRUE(equals(a, b));
}

TEST_F(SortTestA, InsertionSort) {
    insertionSort(b);
    EXPECT_TRUE(equals(a, b));
}

namespace recursion {
    TEST_F(SortTestA, MergeSort) {
        mergeSort(b);
        EXPECT_TRUE(equals(a, b));
    }
}

namespace iteration {

}

TEST_F(SortTestA, ShellSort) {
    shellSort(b);
    EXPECT_TRUE(equals(a, b));
}

namespace recursion {
TEST_F(SortTestA, QuickSort) {
    quickSort(b);
    EXPECT_TRUE(equals(a, b));
}
}

TEST_F(SortTestA, HeapSort) {
    heapSort(b);
    EXPECT_TRUE(equals(a, b));
}

TEST_F(SortTestA, CountSort) {
    countSort(b);
    EXPECT_TRUE(equals(a, b));
}
