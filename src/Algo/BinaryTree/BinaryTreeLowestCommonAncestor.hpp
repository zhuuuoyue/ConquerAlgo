#pragma once

#include <stack>

#include "BinaryTree.hpp"

template<class T>
bool locateNode(const BinaryTreeNode<T>* pRoot, std::stack<const BinaryTreeNode<T>*>& path, const BinaryTreeNode<T>* pTarget)
{
    path.push(pRoot);
    if (pRoot == nullptr) { return false; }
    if (pRoot == pTarget) { return true; }
    if (locateNode(pRoot->left, path, pTarget))
    {
        return true;
    }
    else
    {
        path.pop();
    }
    if (locateNode(pRoot->right, path, pTarget))
    {
        return true;
    }
    else
    {
        path.pop();
    }
    return false;
}

template<class T>
const BinaryTreeNode<T>* lowestCommonAncestor(const BinaryTreeNode<T>* pRoot, const BinaryTreeNode<T>* pA, const BinaryTreeNode<T>* pB)
{
    return nullptr;
}
