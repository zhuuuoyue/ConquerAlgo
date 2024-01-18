#include "gtest/gtest.h"
#include "BinaryTree.hpp"
#include "BinaryTreeSerialization.hpp"

namespace binary_tree
{
    TEST(BinaryTreeSerialization, Deserialize)
    {
        std::shared_ptr<BinaryTree<int>> spBT{ deserialize("1,2,3,x,x,4,5,") };
    }
}
