#include "gtest/gtest.h"
#include "LinkedList.hpp"
#include "compare.hpp"

namespace linked_list
{
TEST(LinkedListTest, PushFrontAndPushBack)
{
    LinkedList<int> lst;
    lst.push_front(4).push_front(1).push_front(3)
        .push_back(1).push_back(5).push_back(9);
    const std::vector<int> traversed = lst.traverse();
    const std::vector<int> answer{ 3, 1, 4, 1, 5, 9 };
    const bool eq = equals(traversed, answer);
    ASSERT_TRUE(eq);
}

TEST(LinkedListTest, Size)
{
    LinkedList<int> lst;
    lst.push_back(3).push_back(1).push_back(4);
    ASSERT_EQ(lst.size(), 3);
}

TEST(LinkedListTest, FrontAndBack)
{
    LinkedList<int> lst;
    lst.push_back(3).push_back(1).push_back(4);
    ASSERT_EQ(lst.front(), 3);
    ASSERT_EQ(lst.back(), 4);
}

TEST(LinkedListTest, RandomAccess)
{
    LinkedList<int> lst;
    lst.push_front(4).push_front(1).push_front(3)
        .push_back(1).push_back(5).push_back(9);
    ASSERT_EQ(lst[1], 1);
    ASSERT_EQ(lst[4], 5);
    lst[0] = -3;
    lst[3] = -1;
    lst[5] = -9;
    const std::vector<int> traversed = lst.traverse();
    const std::vector<int> answer{ -3, 1, 4, -1, 5, -9 };
    const bool eq = equals(traversed, answer);
    ASSERT_TRUE(eq);
}

TEST(LinkedListTest, InsertAndRemove)
{
    LinkedList<int> lst;
    lst.push_front(4).push_front(1).push_front(3)
        .push_back(1).push_back(5).push_back(9);
    lst.insert(0, 0).insert(7, 2).insert(4, -4);
    std::vector<int> traversed = lst.traverse();
    std::vector<int> answer{ 0, 3, 1, 4, -4, 1, 5, 9, 2 };
    ASSERT_TRUE(equals(traversed, answer));
    int value{ 0 };
    lst.remove(4, &value);
    ASSERT_EQ(value, -4);
    lst.remove(0, &value);
    ASSERT_EQ(value, 0);
    lst.remove(6, &value);
    ASSERT_EQ(value, 2);

    traversed = lst.traverse();
    answer = std::vector<int>{ 3, 1, 4, 1, 5, 9 };
    ASSERT_TRUE(equals(traversed, answer));
}
}