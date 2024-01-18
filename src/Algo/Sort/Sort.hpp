#pragma once

#include <vector>
#include <stack>
#include <map>

template<class _Ty, class _Pred = std::less<_Ty>>
void bubbleSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    for (int i = 0; i < items.size(); ++i) {
        for (int j = 0; j + 1 < static_cast<int>(items.size()) - i; ++j) {
            if (pred(items[j + 1], items[j])) {
                std::swap(items[j], items[j + 1]);
            }
        }
    }
}

template<class _Ty, class _Pred = std::less<_Ty>>
void selectionSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    for (int i = 0; i < items.size(); ++i) {
        int minIndex{ i };
        for (int j = i + 1; j < items.size(); ++j) {
            if (pred(items[j], items[minIndex])) {
                minIndex = j;
            }
        }
        std::swap(items[i], items[minIndex]);
    }
}

template<class _Ty, class _Pred = std::less<_Ty>>
void insertionSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    for (int i = 1; i < items.size(); ++i) {
        for (int j = i; j - 1 >= 0; --j) {
            if (pred(items[j], items[j - 1])) {
                std::swap(items[j], items[j - 1]);
            }
        }
    }
}

namespace iteration {
template<class _Ty, class _Pred = std::less<_Ty>>
void mergeSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    // todo
}
}

namespace recursion {
template<class _Ty, class _Pred = std::less<_Ty>>
void mergeSort(std::vector<_Ty>& items, int i, int j, _Pred pred = _Pred{}) {
    if (i >= j) { return; }

    // divide
    int m = (i + j) / 2;
    mergeSort(items, i, m, pred);
    mergeSort(items, m + 1, j, pred);

    // merge
    std::vector<_Ty> temp;
    int x = i;
    int y = m + 1;
    while (x <= m && y <= j) {
        if (pred(items[x], items[y])) {
            temp.emplace_back(items[x]);
            ++x;
        }
        else {
            temp.emplace_back(items[y]);
            ++y;
        }
    }
    while (x <= m) {
        temp.emplace_back(items[x++]);
    }
    while (y <= j) {
        temp.emplace_back(items[y++]);
    }
    int offset = 0;
    while (offset < temp.size()) {
        items[i + offset] = temp[offset];
        ++offset;
    }
}

template<class _Ty, class _Pred = std::less<_Ty>>
void mergeSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    mergeSort(items, 0, static_cast<int>(items.size()) - 1, pred);
}
}

template<class _Ty, class _Pred = std::less<_Ty>>
void shellSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    int step = static_cast<int>(items.size()) / 2;
    while (true) {
        int offset = 0;
        while (offset < step) {
            for (int i = offset; i < items.size(); i += step) {
                for (int j = i; j - step >= 0; j -= step) {
                    if (pred(items[j], items[j - step])) {
                        std::swap(items[j], items[j - step]);
                    }
                }
            }
            ++offset;
        }

        if (1 == step) {
            break;
        }
        step /= 2;
    }
}

namespace iteration {
template<class _Ty, class _Pred = std::less<_Ty>>
void quickSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
}
}

namespace recursion {
template<class _Ty, class _Pred = std::less<_Ty>>
void quickSort(std::vector<_Ty>& items, int i, int j, _Pred pred = _Pred{}) {
    if (j <= i) { return; }
    int povit = i;
    int x = i + 1;
    int y = j;
    while (x < y) {
        while (x < y && pred(items[x], items[povit])) {
            ++x;
        }
        while (y > x && pred(items[povit], items[y])) {
            --y;
        }
        if (x < y) {
            std::swap(items[x], items[y]);
            ++x;
            --y;
        }
    }
    if (x == y && pred(items[povit], items[y])) {
        --y;
    }
    std::swap(items[povit], items[y]);
    quickSort(items, i, y - 1, pred);
    quickSort(items, y + 1, j, pred);
}

template<class _Ty, class _Pred = std::less<_Ty>>
void quickSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    quickSort(items, 0, static_cast<int>(items.size()) - 1, pred);
}
}

template<class _Ty, class _Pred = std::less<_Ty>>
void heapSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    for (int bottom = static_cast<int>(items.size()) - 1; bottom > 0; --bottom) {
        bool willAdjust{ true };
        while (willAdjust) {
            willAdjust = false;
            int i = bottom;
            while (i >= 0) {
                int left = 2 * i + 1;
                int right = left + 1;

                // no children
                if (left > bottom) {
                    --i;
                    continue;
                }

                // only left child
                if (right > bottom) {
                    if (pred(items[i], items[left])) {
                        std::swap(items[i], items[left]);
                        willAdjust = true;
                    }
                    --i;
                    continue;
                }

                // double children
                if (pred(items[i], items[left]) || pred(items[i], items[right])) {
                    if (pred(items[left], items[right])) {
                        std::swap(items[i], items[right]);
                    }
                    else {
                        std::swap(items[i], items[left]);
                    }
                    willAdjust = true;
                }
                --i;
            }
        }
        std::swap(items[0], items[bottom]);
    }
}

template<class _Ty, class _Pred = std::less<_Ty>>
void countSort(std::vector<_Ty>& items, _Pred pred = _Pred{}) {
    std::map<_Ty, std::size_t, _Pred> m;
    for (const _Ty& item : items) {
        auto iter = m.find(item);
        if (iter == m.end()) {
            m[item] = 1;
        }
        else {
            ++iter->second;
        }
    }
    std::vector<std::pair<_Ty, std::size_t>> c;
    for (auto iter = m.cbegin(); iter != m.cend(); ++iter) {
        c.emplace_back(std::make_pair(iter->first, iter->second));
    }
    std::sort(c.begin(), c.end(), [&pred](const std::pair<_Ty, std::size_t>& left, const std::pair<_Ty, std::size_t>& right) -> bool {
            return pred(left.first, right.first);
        });
    std::size_t count{ 0 };
    for (auto iter = c.cbegin(); iter != c.cend(); ++iter) {
        std::size_t i = count;
        count += iter->second;
        while (i < count) {
            items[i] = iter->first;
            ++i;
        }
    }
}
