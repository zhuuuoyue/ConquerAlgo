#pragma once

#include <string>

#include "BinaryTree.hpp"

namespace binary_tree
{
std::string serialize(const BinaryTreeNode<int>* pRoot)
{
    return std::string();
}

BinaryTree<int>* deserialize(const std::string& data)
{
    if (data.empty()) { return nullptr; }
    std::vector<std::string> items;
    auto iter = data.begin();
    while (iter != data.end())
    {
        auto end = iter;
        while (end != data.end() && *end != ',')
        {
            ++end;
        }
        items.emplace_back(std::string(iter, end));
        iter = end + 1;
    }
    std::vector<BinaryTreeNode<int>*> nodes;
    for (std::size_t i = 0; i < items.size(); ++i)
    {
        const std::string& item = items[i];
        if ("x" == item)
        {
            nodes.emplace_back(nullptr);
        }
        else
        {
            int value = std::atoi(item.c_str());
            BinaryTreeNode<int>* pNode = new BinaryTreeNode<int>(value);
            nodes.emplace_back(pNode);
            if (i)
            {
                std::size_t parentIndex = (i - 1) / 2;
                if (i % 2)
                {
                    nodes[parentIndex]->left = pNode;
                }
                else
                {
                    nodes[parentIndex]->right = pNode;
                }
            }
        }
    }
    BinaryTree<int>* pBT = new BinaryTree<int>();
    pBT->root = nodes.front();
    return pBT;
}
}