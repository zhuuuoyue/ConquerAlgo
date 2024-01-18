#include "gtest/gtest.h"
#include "Tree.hpp"

class Int {
public:
    static int diff;
    int value{ 0 };
    Int(int v) : value{ v } { ++diff; }
    Int(const Int& other) : value{ other.value } { ++diff; }
    Int(Int&& other) noexcept : value{ other.value } { ++diff; }
    ~Int() { --diff; }
};

int Int::diff{ 0 };

TEST(TreeTest, Destruction) {
    using Node = TreeNode<Int>;
    {
        Node* pOne = new Node(1);
        Node* pTwo = new Node(2);
        Node* pThree = new Node(3);
        Node* pFour = new Node(4);
        Node* pFive = new Node(5);
        Node* pSix = new Node(6);
        pOne->children.emplace_back(pThree);
        pOne->children.emplace_back(pTwo);
        pOne->children.emplace_back(pFour);
        pThree->children.emplace_back(pFive);
        pThree->children.emplace_back(pSix);
        Tree<Int> tree;
        tree.root = pOne;
    }
    EXPECT_EQ(Int::diff, 0);
}
