#pragma once

#include "BinaryTree.hpp"

template<class T>
int binaryTreeMaxDepthUsingIteration(const BinaryTreeNode<T>* pRoot)
{
    if (nullptr == pRoot) { return 0; }
    int depth{ 0 };
    std::deque<const BinaryTreeNode<T>*> nodes{ pRoot };
    while (!nodes.empty())
    {
        ++depth;
        std::size_t n = nodes.size();
        while (n > 0)
        {
            const BinaryTreeNode<T>* pNode = nodes.front();
            nodes.pop_front();
            --n;
            if (pNode->left) { nodes.push_back(pNode->left); }
            if (pNode->right) { nodes.push_back(pNode->right); }
        }
    }
    return depth;
}

template<class T>
int binaryTreeMaxDepthUsingRecursion(const BinaryTreeNode<T>* pNode)
{
    if (nullptr == pNode) { return 0; }
    return std::max(
        binaryTreeMaxDepthUsingRecursion(pNode->left),
        binaryTreeMaxDepthUsingRecursion(pNode->right)
    ) + 1;
}