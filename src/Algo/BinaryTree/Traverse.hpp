#pragma once

#include <vector>
#include <deque>
#include <stack>

#include "BinaryTree.hpp"

template<class T>
std::vector<T> traverseByLevelOrder(const BinaryTreeNode<T>* pRoot)
{
    /*
    * �������Ĳ���������Ը������������
    * ����Ҫ˼·�ǣ�ģ�¶��У����Σ�
    * 1. �Ӷ���ͷ��ȡ��Ԫ�� pNode
    * 2. ���� pNode ��ֵ
    * 3. ��˳�����ӽ��������β��
    * ��ʱ�����У������ң�
    * - ǰ���Ԫ�ص����ϲ��Ԫ��
    * - �����Ԫ�����²��Ԫ��
    * ���ϴӶ���ͷ��ȡ��Ԫ�أ������β��׷��Ԫ�أ�ֱ������Ϊ��
    */
    std::vector<T> items;
    if (nullptr == pRoot) { return items; }
    // �������Ԫ�ؼ�������У���Ϊ��ʼ״̬
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
    * �ݹ鷽ʽ�ȸ�˳�������������˼·��
    * - �ȱ�������㣬�ٱ������������ٱ���������
    * - ��ֹ�����Ǵ���ĵ�ǰ���������Ϊ��
    */
    if (nullptr == pNode) { return; }
    items.emplace_back(pNode->data);
    traverseByPreOrderUsingRecursion(pNode->left, items);
    traverseByPreOrderUsingRecursion(pNode->right, items);
}

/// <summary>
/// ʹ�õݹ鷽ʽ�ȸ�˳�����������
/// </summary>
/// <returns>�������ֵ�б�</returns>
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
    * ������ʽ�ȸ�˳�������������˼·��
    * - ʹ�� stack ģ��ݹ������ѹջ�뵯ջ��Ϊ
    * - �ȷ��ʸ���㣬�ٽ��ӽ��ѹջ
    * - ��ѹջʱ�����Һ����ڵ�ջʱ�������������
    */
    std::vector<T> items;
    if (nullptr == pRoot) { return items; }
    // ����ջ����ѹ�����㣬��Ϊ��ʼ״̬
    std::stack<const BinaryTreeNode<T>*> nodes;
    nodes.push(pRoot);
    while (!nodes.empty())
    {
        // �ȷ���ջ��Ԫ��
        const BinaryTreeNode<T>* pNode = nodes.top();
        nodes.pop();
        items.emplace_back(pNode->data);
        // ��ѹ�����ӽ�㣬�����ӽ�㣬��һ�ֵ����в����������
        // ��һ�ֵ�����ֻ����һ��Ԫ�أ���ѹ���������ӽ��
        // ���������ӽ��Խ��Խ������ȱ���������
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
        // �ӵ�ǰ����������һ·ֱ�ﵱǰ������������Ľ��
        while (pNode)
        {
            s.push(pNode);
            pNode = pNode->left;
        }
        // ����ǰջ��Ϊ�գ���ǰջ��Ԫ����������
        if (!s.empty())
        {
            // ��Ϊ��ǰ���û�������ӽ�㣬�����ӽ���Ѿ������ʹ���
            // ���Ӧ����ǰ���ֵ�����б�
            pNode = s.top();
            s.pop();
            items.emplace_back(pNode->data);
            // ����һ�ֵ����У��ӵ�ǰ�������ӽ�㿪ʼ
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
    * ������ʽ���˳���������������Ҫ˼·��
    * - ���������˳���ǣ��� - �� - ��
    * - �ȸ��������ȷ����ҽ���˳���ǣ��� - �� - ��
    * - ���������෴����˿������Һ�����ȸ��������ٽ�����Ӻ���ǰ���
    * ��ʵ�ַ�ʽ�ϣ������ַ�����
    * - ʹ�� vector �洢ֵ��ʹ�� std::reverse ��������
    * - ʹ������ stack �ı����˳��
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