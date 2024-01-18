#pragma once

#include <vector>
#include <deque>
#include <stack>

#include "BinaryTree.hpp"

template<class T>
std::vector<T> traverseByLevelOrder(const BinaryTreeNode<T>* pRoot)
{
    /*
    * 二叉树的层序遍历，自根结点起，逐层遍历
    * 其主要思路是：模仿队列，依次：
    * 1. 从队列头部取出元素 pNode
    * 2. 访问 pNode 的值
    * 3. 按顺序将其子结点加入队列尾部
    * 此时队列中，从左到右：
    * - 前面的元素的是上层的元素
    * - 后面的元素是下层的元素
    * 不断从队列头部取出元素，向队列尾部追加元素，直到队列为空
    */
    std::vector<T> items;
    if (nullptr == pRoot) { return items; }
    // 将根结点元素加入队列中，作为起始状态
    std::deque<const BinaryTreeNode<T>*> nodes{ pRoot };
    while (!nodes.empty())
    {
        const BinaryTreeNode<T>* pNode = nodes.front();
        nodes.pop_front();
        items.emplace_back(pNode->data);
        if (pNode->left) { nodes.emplace_back(pNode->left); }
        if (pNode->right) { nodes.emplace_back(pNode->right); }
    }
    return items;
}

template<class T>
void traverseByPreOrderUsingRecursion(const BinaryTreeNode<T>* pNode, std::vector<T>& items)
{
    /*
    * 递归方式先根顺序遍历二叉树的思路：
    * - 先遍历根结点，再遍历左子树，再遍历右子树
    * - 终止条件是传入的当前子树根结点为空
    */
    if (nullptr == pNode) { return; }
    items.emplace_back(pNode->data);
    traverseByPreOrderUsingRecursion(pNode->left, items);
    traverseByPreOrderUsingRecursion(pNode->right, items);
}

/// <summary>
/// 使用递归方式先根顺序遍历二叉树
/// </summary>
/// <returns>遍历结点值列表</returns>
template<class T>
std::vector<T> traverseByPreOrderUsingRecursion(const BinaryTreeNode<T>* pRoot)
{
    std::vector<T> items;
    traverseByPreOrderUsingRecursion(pRoot, items);
    return items;
}

template<class T>
std::vector<T> traverseByPreOrderUsingIteration(const BinaryTreeNode<T>* pRoot)
{
    /*
    * 迭代方式先根顺序遍历二叉树的思路：
    * - 使用 stack 模拟递归遍历的压栈与弹栈行为
    * - 先访问根结点，再将子结点压栈
    * - 在压栈时，先右后左，在弹栈时，才能先左后右
    */
    std::vector<T> items;
    if (nullptr == pRoot) { return items; }
    // 定义栈，先压入根结点，作为初始状态
    std::stack<const BinaryTreeNode<T>*> nodes;
    nodes.push(pRoot);
    while (!nodes.empty())
    {
        // 先访问栈顶元素
        const BinaryTreeNode<T>* pNode = nodes.top();
        nodes.pop();
        items.emplace_back(pNode->data);
        // 先压入右子结点，再左子结点，下一轮迭代中才能先左后右
        // 下一轮迭代，只弹出一个元素，再压入其左右子结点
        // 这样，右子结点越埋越深，才能先遍历左子树
        if (pNode->right) { nodes.push(pNode->right); }
        if (pNode->left) { nodes.push(pNode->left); }
    }
    return items;
}

template<class T>
void traverseByInOrderUsingRecursion(const BinaryTreeNode<T>* pNode, std::vector<T>& items)
{
    if (nullptr == pNode) { return; }
    traverseByInOrderUsingRecursion(pNode->left, items);
    items.emplace_back(pNode->data);
    traverseByInOrderUsingRecursion(pNode->right, items);
}

template<class T>
std::vector<T> traverseByInOrderUsingRecursion(const BinaryTreeNode<T>* pRoot)
{
    std::vector<T> items;
    traverseByInOrderUsingRecursion(pRoot, items);
    return items;
}

template<class T>
std::vector<T> traverseByInOrderUsingIteration(const BinaryTreeNode<T>* pRoot)
{
    std::vector<T> items;
    if (nullptr == pRoot) { return items; }
    const BinaryTreeNode<T>* pNode = pRoot;
    std::stack<const BinaryTreeNode<T>*> s;
    while (nullptr != pNode || !s.empty())
    {
        // 从当前结点出发，先一路直达当前子树最左最深的结点
        while (pNode)
        {
            s.push(pNode);
            pNode = pNode->left;
        }
        // 若当前栈不为空，则当前栈顶元素是最左结点
        if (!s.empty())
        {
            // 因为当前结点没有了左子结点，或左子结点已经被访问过了
            // 因此应将当前结点值加入列表
            pNode = s.top();
            s.pop();
            items.emplace_back(pNode->data);
            // 在下一轮迭代中，从当前结点的右子结点开始
            pNode = pNode->right;
        }
    }
    return items;
}

template<class T>
void traverseByPostOrderUsingRecursion(const BinaryTreeNode<T>* pNode, std::vector<T>& items)
{
    if (nullptr == pNode) { return; }
    traverseByPostOrderUsingRecursion(pNode->left, items);
    traverseByPostOrderUsingRecursion(pNode->right, items);
    items.emplace_back(pNode->data);
}

template<class T>
std::vector<T> traverseByPostOrderUsingRecursion(const BinaryTreeNode<T>* pRoot)
{
    std::vector<T> items;
    traverseByPostOrderUsingRecursion(pRoot, items);
    return items;
}

template<class T>
std::vector<T> traverseByPostOrderUsingIteration(const BinaryTreeNode<T>* pRoot)
{
    /*
    * 迭代方式后根顺序遍历二叉树的主要思路：
    * - 后根遍历的顺序是：左 - 右 - 根
    * - 先根遍历，先访问右结点的顺序是：根 - 右 - 左
    * - 二者正好相反，因此可以先右后左地先根遍历，再将结果从后向前输出
    * 在实现方式上，有两种方法：
    * - 使用 vector 存储值，使用 std::reverse 函数逆置
    * - 使用两个 stack 改变输出顺序
    */
    std::vector<T> items;
    if (nullptr == pRoot) { return items; }
    std::stack<const BinaryTreeNode<T>*> nodes;
    nodes.push(pRoot);
    while (!nodes.empty())
    {
        const BinaryTreeNode<T>* pNode = nodes.top();
        items.emplace_back(pNode->data);
        nodes.pop();
        if (pNode->left) { nodes.push(pNode->left); }
        if (pNode->right) { nodes.push(pNode->right); }
    }
    std::reverse(items.begin(), items.end());
    return items;
}