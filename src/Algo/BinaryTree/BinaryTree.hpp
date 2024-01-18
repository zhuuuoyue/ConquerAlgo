#pragma once

#include <deque>

template<class T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T>* left{ nullptr };
    BinaryTreeNode<T>* right{ nullptr };

    BinaryTreeNode(const T& d) : data{ d } {}
};

template<class T>
class BinaryTree
{
public:

    BinaryTree() = default;
    BinaryTree(const BinaryTree&) = delete;
    BinaryTree(BinaryTree&&) = delete;
    BinaryTree& operator=(const BinaryTree&) = delete;
    BinaryTree& operator=(BinaryTree&&) = delete;

    ~BinaryTree()
    {
        if (root)
        {
            using Node = BinaryTreeNode<T>;
            std::deque<Node*> nodes{ root };
            while (!nodes.empty())
            {
                Node* pNode = nodes.front();
                if (nullptr != pNode)
                {
                    if (pNode->left) { nodes.push_back(pNode->left); }
                    if (pNode->right) { nodes.push_back(pNode->right); }
                    delete pNode;
                }
                nodes.pop_front();
            }
            root = nullptr;
        }
    }

    BinaryTreeNode<T>* root{ nullptr };
};