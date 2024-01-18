#pragma once

#include <vector>

template<class T>
class LinkedList
{
public:

    struct Node
    {
        Node(const T& d) : data{ d }, next{ nullptr } {}
        T data;
        Node* next;
    };

    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList(LinkedList&&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    LinkedList& operator=(LinkedList&&) = delete;

    ~LinkedList()
    {
        Node* ptr = _head;
        while (ptr)
        {
            Node* next = ptr->next;
            delete ptr;
            ptr = next;
        }
        _head = nullptr;
    }

    bool empty() const
    {
        return nullptr == _head;
    }

    std::size_t size() const
    {
        Node* ptr = _head;
        std::size_t s{ 0 };
        while (ptr)
        {
            ++s;
            ptr = ptr->next;
        }
        return s;
    }

    LinkedList<T>& push_front(const T& value)
    {
        Node* pNewHead = new Node(value);
        pNewHead->next = _head;
        _head = pNewHead;
        return *this;
    }

    LinkedList<T>& push_back(const T& value)
    {
        if (nullptr == _head)
        {
            return push_front(value);
        }
        Node* ptr = _head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        Node* pNewBack = new Node(value);
        ptr->next = pNewBack;
        return *this;
    }

    T& front()
    {
        return front_node()->data;
    }

    const T& front() const
    {
        return front_node()->data;
    }

    T& back()
    {
        return back_node()->data;
    }

    const T& back() const
    {
        return back_node()->data;
    }

    T& operator[](std::size_t index)
    {
        return node_at(index)->data;
    }

    const T& operator[](std::size_t index) const
    {
        return node_at(index)->data;
    }

    LinkedList<T>& insert(std::size_t index, const T& value)
    {
        if (0 == index)
        {
            return push_front(value);
        }
        else
        {
            if (Node* pPrevious = node_at(index - 1))
            {
                Node* pNode = new Node(value);
                pNode->next = pPrevious->next;
                pPrevious->next = pNode;
            }
            return *this;
        }
    }

    LinkedList<T>& remove(std::size_t index, T* pValue = nullptr)
    {
        if (0 == index)
        {
            if (nullptr != _head)
            {
                Node* pNode = _head;
                _head = pNode->next;
                if (pValue)
                {
                    *pValue = pNode->data;
                }
                delete pNode;
            }
        }
        else
        {
            if (Node* pPrevious = node_at(index - 1))
            {
                if (Node* pCurrent = pPrevious->next)
                {
                    pPrevious->next = pCurrent->next;
                    if (pValue)
                    {
                        *pValue = pCurrent->data;
                    }
                    delete pCurrent;
                }
            }
        }
        return *this;
    }

    std::vector<T> traverse() const
    {
        std::vector<T> items;
        Node* ptr = _head;
        while (ptr)
        {
            items.emplace_back(ptr->data);
            ptr = ptr->next;
        }
        return items;
    }

private:

    Node* front_node()
    {
        return _head;
    }

    const Node* front_node() const
    {
        return _head;
    }

    Node* back_node()
    {
        return const_cast<Node*>(
            const_cast<const LinkedList<T>*>(this)->back_node()
            );
    }

    const Node* back_node() const
    {
        if (nullptr == _head)
        {
            return _head;
        }
        else
        {
            Node* ptr = _head;
            while (ptr->next)
            {
                ptr = ptr->next;
            }
            return ptr;
        }
    }

    Node* node_at(std::size_t index)
    {
        return const_cast<Node*>(
            const_cast<const LinkedList<T>*>(this)->node_at(index)
            );
    }

    const Node* node_at(std::size_t index) const
    {
        Node* ptr = _head;
        std::size_t i{ 0 };
        while (ptr)
        {
            if (i == index)
            {
                return ptr;
            }
            ptr = ptr->next;
            ++i;
        }
        return nullptr;
    }

private:

    Node* _head{ nullptr };

};
