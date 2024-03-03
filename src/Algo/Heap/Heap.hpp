#pragma once

#include <utility>
#include <vector>

template<class T>
struct LT
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
};

template<class T>
struct GT
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs > rhs;
    }
};

template<class T, class C>
class Heap
{
public:

    std::size_t size() const
    {
        return _data.size();
    }

    Heap<T>& push(const T& value)
    {
        return *this;
    }

    Heap<T>& pop(T* pValue = nullptr)
    {
        return *this;
    }

    T top() const
    {
        return _data.front();
    }

private:

    std::vector<T> _data;
    C _comp;
};
