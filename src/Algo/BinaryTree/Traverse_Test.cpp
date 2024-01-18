#include "gtest/gtest.h"
#include "Traverse.hpp"
#include "Build.hpp"
#include "compare.hpp"

namespace binary_tree_traverse
{
class BinaryTreeTest : public testing::Test
{
protected:

    virtual void SetUp() override
    {
        _spTree = createBinaryTree<int>({ 1, 2, 3, nullptr, nullptr, 4, 5, nullptr, nullptr, nullptr, 6, nullptr, 7, 8, nullptr, nullptr, nullptr });
    }

protected:

    std::shared_ptr<BinaryTree<int>> _spTree{ nullptr };
};

TEST_F(BinaryTreeTest, TraverseByLevelOrder)
{
    const std::vector<int> values = traverseByLevelOrder(_spTree->root);
    const std::vector<int> answer{ 1, 2, 6, 3, 4, 7, 5, 8 };
    const bool eq = equals(values, answer);
    ASSERT_TRUE(eq);
}

TEST_F(BinaryTreeTest, TraverseByPreOrderUsingRecursion)
{
    const std::vector<int> values = traverseByPreOrderUsingRecursion(_spTree->root);
    const std::vector<int> answer{ 1, 2, 3, 4, 5, 6, 7, 8 };
    const bool eq = equals(values, answer);
    ASSERT_TRUE(eq);
}

TEST_F(BinaryTreeTest, TraverseByPreOrderUsingIteration)
{
    const std::vector<int> values = traverseByPreOrderUsingIteration(_spTree->root);
    const std::vector<int> answer{ 1, 2, 3, 4, 5, 6, 7, 8 };
    const bool eq = equals(values, answer);
    ASSERT_TRUE(eq);
}

TEST_F(BinaryTreeTest, TraverseByInOrderUsingRecursion)
{
    const std::vector<int> values = traverseByInOrderUsingRecursion(_spTree->root);
    const std::vector<int> answer{ 3, 2, 5, 4, 1, 6, 8, 7 };
    const bool eq = equals(values, answer);
    ASSERT_TRUE(eq);
}

TEST_F(BinaryTreeTest, TraverseByInOrderUsingIteration)
{
    const std::vector<int> values = traverseByInOrderUsingIteration(_spTree->root);
    const std::vector<int> answer{ 3, 2, 5, 4, 1, 6, 8, 7 };
    const bool eq = equals(values, answer);
    ASSERT_TRUE(eq);
}

TEST_F(BinaryTreeTest, TraverseByPostOrderUsingRecursion)
{
    const std::vector<int> values = traverseByPostOrderUsingRecursion(_spTree->root);
    const std::vector<int> answer{ 3, 5, 4, 2, 8, 7,  6, 1 };
    const bool eq = equals(values, answer);
    ASSERT_TRUE(eq);
}

TEST_F(BinaryTreeTest, TraverseByPostOrderUsingIteration)
{
    const std::vector<int> values = traverseByPostOrderUsingIteration(_spTree->root);
    const std::vector<int> answer{ 3, 5, 4, 2, 8, 7, 6, 1 };
    const bool eq = equals(values, answer);
    ASSERT_TRUE(eq);
}
}