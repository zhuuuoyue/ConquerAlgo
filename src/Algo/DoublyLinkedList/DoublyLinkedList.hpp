#pragma once

#include <vector>

template<class T>
class DoublyLinkedList
{
public:

    struct Node
    {
        Node(const T& d) : data{ d } {}

        Node* prev{ nullptr };
        T data;
        Node* next{ nullptr };
    };

    DoublyLinkedList() = default;
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList(DoublyLinkedList&&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(DoublyLinkedList&&) = delete;

    ~DoublyLinkedList()
    {
        Node* ptr = _head;
        while (ptr)
        {
            Node* pNext = ptr->next;
            delete ptr;
            ptr = pNext;
        }
        _head = nullptr;
    }

    bool empty() const
    {
        return nullptr == _head;
    }

    std::size_t size() const
    {
        Node* pNode = _head;
        std::size_t s{ 0 };
        while (pNode)
        {
            ++s;
            pNode = pNode->next;
        }
        return s;
    }

    DoublyLinkedList<T>& push_front(const T& value)
    {
        Node* pNext = _head;
        _head = new Node(value);
        _head->next = pNext;
        if (pNext)
        {
            pNext->prev = _head;
        }
        return *this;
    }

    DoublyLinkedList<T>& push_back(const T& value)
    {
        if (nullptr == _head)
        {
            return push_front(value);
        }

        Node* pBack = _head;
        while (pBack->next) { pBack = pBack->next; }
        Node* pNode = new Node(value);
        pNode->prev = pBack;
        pBack->next = pNode;
        return *this;
    }

    DoublyLinkedList<T>& insert(std::size_t index, const T& value)
    {
        if (0 == index) { return push_front(value); }
        Node* pPrevious = node_at(index - 1);
        if (nullptr == pPrevious) { return *this; }
        Node* pNext = pPrevious->next;
        Node* pNode = new Node(value);
        pNode->next = pNext;
        pNode->prev = pPrevious;
        if (pNext)
        {
            pNext->prev = pNode;
        }
        pPrevious->next = pNode;
        return *this;
    }

    DoublyLinkedList<T>& remove(std::size_t index, T* pValue = nullptr)
    {
        Node* pNode = node_at(index);
        if (pNode)
        {
            Node* pPrevious = pNode->prev;
            Node* pNext = pNode->next;
            if (pPrevious)
            {
                pPrevious->next = pNext;
            }
            else
            {
                _head = pNext;
            }
            if (pNext)
            {
                pNext->prev = pPrevious;
            }
            if (pValue)
            {
                *pValue = pNode->data;
            }
            delete pNode;
        }
        return *this;
    }

    const T& operator[](std::size_t index) const
    {
        return node_at(index)->data;
    }

    T& operator[](std::size_t index)
    {
        return node_at(index)->data;
    }

    std::vector<T> traverse(bool reverse = false) const
    {
        std::vector<T> items;
        if (reverse)
        {
            const Node* pNode = _head;
            while (pNode && pNode->next) { pNode = pNode->next; }
            while (pNode)
            {
                items.emplace_back(pNode->data);
                pNode = pNode->prev;
            }
        }
        else
        {
            const Node* pNode = _head;
            while (pNode)
            {
                items.emplace_back(pNode->data);
                pNode = pNode->next;
            }
        }
        return items;
    }

private:

    Node* node_at(std::size_t index)
    {
        return const_cast<Node*>(
            const_cast<const DoublyLinkedList<T>*>(this)->node_at(index)
            );
    }

    const Node* node_at(std::size_t index) const
    {
        Node* pNode = _head;
        std::size_t steps{ 0 };
        while (pNode)
        {
            if (steps == index) { return pNode; }
            pNode = pNode->next;
            ++steps;
        }
        return nullptr;
    }

private:

    Node* _head{ nullptr };

};
