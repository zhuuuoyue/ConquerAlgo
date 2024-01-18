#pragma once

#include <memory>

#include "BinaryTree.hpp"
#include "Optional.hpp"

template<class T>
void buildBinaryTree(BinaryTreeNode<T>* pParent, const std::vector<Optional<T>>& items, std::size_t& index)
{
    if (nullptr == pParent || index >= items.size()) { return; }
    const Optional<T>& left = items[index];
    if (left)
    {
        pParent->left = new BinaryTreeNode<T>(left.data);
        ++index;
        buildBinaryTree(pParent->left, items, index);
    }
    ++index;
    if (index >= items.size()) { return; }
    const Optional<T>& right = items[index];
    if (right)
    {
        pParent->right = new BinaryTreeNode<T>(right.data);
        ++index;
        buildBinaryTree(pParent->right, items, index);
    }
}

template<class T>
std::shared_ptr<BinaryTree<T>> createBinaryTree(const std::vector<Optional<T>>& items)
{
    const Optional<T>& first = items.front();
    if (!first) { return nullptr; }
    std::shared_ptr<BinaryTree<T>> spBT = std::make_shared<BinaryTree<T>>();
    spBT->root = new BinaryTreeNode<T>(first.data);
    std::size_t index{ 1 };
    buildBinaryTree(spBT->root, items, index);
    return spBT;
}