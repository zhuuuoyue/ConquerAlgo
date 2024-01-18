#pragma once

#include <queue>
#include <stack>
#include "Tree.hpp"

namespace iteration
{
namespace level
{
template<class T>
std::vector<T> traverse(const TreeNode<T>* pRoot) {
    std::vector<T> values;
    if (nullptr == pRoot) { return values; }
    std::queue<const TreeNode<T>*> nodes;
    nodes.push(pRoot);
    while (!nodes.empty()) {
        std::size_t n = nodes.size();
        while (n) {
            const TreeNode<T>* pNode = nodes.front();
            values.emplace_back(pNode->data);
            nodes.pop();
            --n;
            for (std::size_t i = 0; i < pNode->children.size(); ++i) {
                nodes.push(pNode->children[i]);
            }
        }
    }
    return values;
}
}
namespace preorder
{
template<class T>
std::vector<T> traverse(const TreeNode<T>* pRoot) {
    std::vector<T> values;
    if (nullptr == pRoot) { return values; }
    std::stack<const TreeNode<T>*> nodes;
    nodes.push(pRoot);
    while (!nodes.empty()) {
        const TreeNode<T>* pNode = nodes.top();
        values.emplace_back(pNode->data);
        nodes.pop();
        for (int i = static_cast<int>(pNode->children.size()) - 1; i >= 0; --i) {
            nodes.push(pNode->children[i]);
        }
    }
    return values;
}
}
namespace postorder
{
template<class T>
std::vector<T> traverse(const TreeNode<T>* pRoot) {
    std::vector<T> values;
    if (nullptr == pRoot) { return values; }
    std::stack<const TreeNode<T>*> nodes;
    nodes.push(pRoot);
    while (!nodes.empty()) {
        const TreeNode<T>* pNode = nodes.top();
        values.emplace_back(pNode->data);
        nodes.pop();
        for (const TreeNode<T>* pChild : pNode->children) {
            nodes.push(pChild);
        }
    }
    std::reverse(values.begin(), values.end());
    return values;
}
}
}
namespace recursion
{
namespace preorder
{
template<class T>
void traverse(const TreeNode<T>* pNode, std::vector<T>& values) {
    if (nullptr == pNode) { return; }
    values.emplace_back(pNode->data);
    for (const TreeNode<T>* pChild : pNode->children) {
        traverse(pChild, values);
    }
}
template<class T>
std::vector<T> traverse(const TreeNode<T>* pRoot) {
    std::vector<T> values;
    traverse(pRoot, values);
    return values;
}
}
namespace postorder
{
template<class T>
void traverse(const TreeNode<T>* pNode, std::vector<T>& values) {
    if (nullptr == pNode) { return; }
    for (const TreeNode<T>* pChild : pNode->children) {
        traverse(pChild, values);
    }
    values.emplace_back(pNode->data);
}
template<class T>
std::vector<T> traverse(const TreeNode<T>* pRoot) {
    std::vector<T> values;
    traverse(pRoot, values);
    return values;
}
}
}