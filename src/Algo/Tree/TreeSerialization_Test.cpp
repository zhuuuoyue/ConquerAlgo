#include "gtest/gtest.h"
#include "TreeSerialization.hpp"

TEST(TreeSerializationTest, Serialize) {
    TreeNode<int>* n1 = new TreeNode<int>(1);
    TreeNode<int>* n2 = new TreeNode<int>(2);
    TreeNode<int>* n3 = new TreeNode<int>(3);
    TreeNode<int>* n4 = new TreeNode<int>(4);
    TreeNode<int>* n5 = new TreeNode<int>(5);
    TreeNode<int>* n6 = new TreeNode<int>(6);
    TreeNode<int>* n7 = new TreeNode<int>(7);
    TreeNode<int>* n9 = new TreeNode<int>(9);
    TreeNode<int>* n10 = new TreeNode<int>(10);
    TreeNode<int>* n11 = new TreeNode<int>(11);

    n1->children.emplace_back(n3);
    n1->children.emplace_back(n2);
    n1->children.emplace_back(n4);

    n3->children.emplace_back(n5);
    n3->children.emplace_back(n6);

    n2->children.emplace_back(n7);
    n4->children.emplace_back(n9);
    n5->children.emplace_back(n10);
    n7->children.emplace_back(n11);

    std::shared_ptr<Tree<int>> tree = std::make_shared<Tree<int>>();
    tree->root = n1;

    std::string result = serialize(n1);
    std::string answer{ "1;3,2,4;5,6;7;9;10;;11" };
    EXPECT_EQ(result, answer);
}

TEST(TreeSerializationTest, Deserialize) {
    std::string data{ "1;3,2,4;5,6;7;9;10;;11" };
    TreeNode<int>* pRoot = deserialize(data);
    Tree<int> tree;
    tree.root = pRoot;
    std::string result = serialize(pRoot);
    EXPECT_EQ(data, result);
}