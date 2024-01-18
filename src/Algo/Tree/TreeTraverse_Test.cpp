#include "gtest/gtest.h"
#include "Tree.hpp"
#include "TreeTraverse.hpp"
#include "compare.hpp"

class TreeTraverseTestBase : public testing::Test {
public:
    std::shared_ptr<Tree<int>> tree;
    virtual void SetUp() override {
        TreeNode<int>* pOne = new TreeNode<int>(1);
        TreeNode<int>* pTwo = new TreeNode<int>(2);
        TreeNode<int>* pThree = new TreeNode<int>(3);
        TreeNode<int>* pFour = new TreeNode<int>(4);
        TreeNode<int>* pFive = new TreeNode<int>(5);
        TreeNode<int>* pSix = new TreeNode<int>(6);

        pOne->children.emplace_back(pThree);
        pOne->children.emplace_back(pTwo);
        pOne->children.emplace_back(pFour);
        pThree->children.emplace_back(pFive);
        pThree->children.emplace_back(pSix);

        tree = std::make_shared<Tree<int>>();
        tree->root = pOne;
    }
};

namespace iteration
{
namespace level
{
TEST_F(TreeTraverseTestBase, TreeTraverseByLevelOrderUsingIterationMethod) {
    std::vector<int> result = traverse(tree->root);
    std::vector<int> answer{ 1, 3, 2, 4, 5, 6 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}
}
namespace preorder
{
TEST_F(TreeTraverseTestBase, TreeTraverseByPreOrderUsingIterationMethod) {
    std::vector<int> result = traverse(tree->root);
    std::vector<int> answer{ 1, 3, 5, 6, 2, 4 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}
}
namespace postorder
{
TEST_F(TreeTraverseTestBase, TreeTraverseByPostOrderUsingIterationMethod) {
    std::vector<int> result = traverse(tree->root);
    std::vector<int> answer{ 5, 6, 3, 2, 4, 1 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}
}
}

namespace recursion
{
namespace preorder
{
TEST_F(TreeTraverseTestBase, TreeTraverseByPreOrderUsingRecursionMethod) {
    std::vector<int> result = traverse(tree->root);
    std::vector<int> answer{ 1, 3, 5, 6, 2, 4 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}
}
namespace postorder
{
TEST_F(TreeTraverseTestBase, TreeTraverseByPostOrderUsingRecursionMethod) {
    std::vector<int> result = traverse(tree->root);
    std::vector<int> answer{ 5, 6, 3, 2, 4, 1 };
    bool eq = equals(result, answer);
    EXPECT_TRUE(eq);
}
}
}
