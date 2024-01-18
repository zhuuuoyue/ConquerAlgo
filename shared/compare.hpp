#pragma once

#include <algorithm>
#include <vector>

//template<class Iter>
//bool equals(Iter i, Iter j, Iter x, Iter y)
//{
//    std::ptrdiff_t s1 = std::distance(i, j);
//    std::ptrdiff_t s2 = std::distance(x, y);
//    if (s1 != s2) { return false; }
//    auto a = i;
//    auto b = x;
//    while (a != j)
//    {
//        if (*a != *b) { return false; }
//        ++a;
//        ++b;
//    }
//    return true;
//}

template<class T>
bool equals(const std::vector<T>& a, const std::vector<T>& b)
{
    if (a.size() != b.size()) { return false; }
    for (std::size_t index = 0; index < a.size(); ++index)
    {
        if (a[index] != b[index])
        {
            return false;
        }
    }
    return true;
}
