#include "gtest/gtest.h"
#include "DoublyLinkedList.hpp"
#include "compare.hpp"

namespace double_linked_list
{
TEST(DLinkedListTest, PushFront)
{
    DoublyLinkedList<int> lst;
    lst.push_front(4).push_front(1).push_front(3);
    const std::vector<int> traversed = lst.traverse();
    const std::vector<int> answer{ 3, 1, 4 };
    const bool eq = equals(traversed, answer);
    ASSERT_TRUE(eq);
}

TEST(DLinkedListTest, Size)
{
    DoublyLinkedList<int> lst;
    lst.push_front(1).push_front(2).push_front(3).push_front(4).push_front(5);
    ASSERT_EQ(lst.size(), 5);
}

TEST(DLinkedListTest, PushBack)
{
    DoublyLinkedList<int> lst;
    lst.push_back(3).push_back(1).push_back(4).push_back(1).push_back(5);
    const std::vector<int> traversed = lst.traverse();
    const std::vector<int> answer{ 3, 1, 4, 1, 5 };
    const bool eq = equals(traversed, answer);
    ASSERT_TRUE(eq);
}

TEST(DLinkedListTest, Insert)
{
    DoublyLinkedList<int> lst;
    lst.push_back(3).push_back(1).push_back(4).push_back(1).push_back(5);
    lst.insert(0, 0);
    lst.insert(2, -1);
    lst.insert(lst.size(), 9);

    std::vector<int> traversed = lst.traverse();
    std::vector<int> answer{ 0, 3, -1, 1, 4, 1, 5, 9 };
    bool eq = equals(traversed, answer);
    ASSERT_TRUE(eq);

    std::reverse(answer.begin(), answer.end());
    traversed = lst.traverse(true);
    eq = equals(traversed, answer);
    ASSERT_TRUE(eq);
}

TEST(DLinkedListTest, Access)
{
    DoublyLinkedList<int> lst;
    lst.push_back(3).push_back(1).push_back(4).push_back(1).push_back(5);

    const int value = lst[2];
    ASSERT_EQ(value, 4);

    lst[2] = -4;
    const std::vector<int> traversed = lst.traverse();
    const std::vector<int> answer{ 3, 1, -4, 1, 5 };
    const bool eq = equals(traversed, answer);
    ASSERT_TRUE(eq);
}

TEST(DLinkedListTest, Remove)
{
    DoublyLinkedList<int> lst;
    lst.push_back(3).push_back(1).push_back(4).push_back(1).push_back(5);

    int value{ 0 };
    lst.remove(0, &value);
    ASSERT_EQ(value, 3);

    lst.remove(1, &value);
    ASSERT_EQ(value, 4);

    lst.remove(2, &value);
    ASSERT_EQ(value, 5);

    const std::vector<int> traversed = lst.traverse();
    const std::vector<int> answer{ 1, 1 };
    const bool eq = equals(traversed, answer);
    ASSERT_TRUE(eq);
}
}