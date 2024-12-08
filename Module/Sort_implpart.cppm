module;
#include <algorithm>
#include <cstring>
#include <functional>
#include <iterator>
#include <vector>
module Sort:impl;

import :interface;

void m_sort::bubble(std::vector<int> &_vec)
{

    int  len = _vec.size();
    bool is_changed;

    for (int i = 0; i < len - 1; i++)
    {
        is_changed = false;

        for (int j = 1; j < len - i; j++)
        {
            if (_vec[j] < _vec[j - 1])
            {
                is_changed = true;
                std::swap(_vec[j], _vec[j - 1]);
            }
        }

        if (!is_changed)
            break;
    }
}

using ptr = std::vector<int>::iterator;

ptr _partition(ptr _head, ptr _tail)
{
    int pivot = *_head;

    while (_head != _tail)
    {
        while (_head != _tail && *_tail >= pivot)
            --_tail;

        *_head = *_tail;

        while (_head != _tail && *_head <= pivot)
            ++_head;

        *_tail = *_head;
    }

    *_head = pivot;
    return _head;
}

void _quick_sort(ptr _head, ptr _tail)
{
    if (_head < _tail)
    {
        auto pivot = _partition(_head, _tail);

        _quick_sort(_head, pivot - 1);
        _quick_sort(pivot + 1, _tail);
    }
}

void m_sort::quick_sort(std::vector<int> &_vec) { _quick_sort(_vec.begin(), _vec.end() - 1); }

// range: [_head,_tail), like [begin,end)
void _qs_3(ptr _head, ptr _tail)
{
    if (std::distance(_head, _tail) <= 1)
        return;

    if (std::distance(_head, _tail) <= 10)
    {
        // insert sort
        for (auto it = _head; it != _tail; ++it)
        {
            // binary search the insert position.
            auto temp = *it;
            auto pos  = std::upper_bound(_head, it, temp);
            // left rotation.
            std::rotate(pos, it, it + 1);
        }
        return;
    }

    // 3 of median
    auto mid   = _head + (std::distance(_head, _tail) >> 1);
    int  tmp[] = {*_head, *mid, *(_tail - 1)};
    std::sort(std::begin(tmp), std::end(tmp));
    int  pivot = tmp[1];

    // Group value equaled `pivot` together
    // Three-way quick sort
    auto i = _head, left = _head, right = _tail - 1;
    while (i <= right)
    {
        if (*i < pivot)
        {
            std::swap(*i, *left);
            ++i;
            ++left;
        }
        else if (*i > pivot)
        {
            std::swap(*i, *right);
            --right;
        }
        else
        {
            ++i;
        }
    }

    _qs_3(_head, left);

    _qs_3(right + 1, _tail);
}

void m_sort::qs_3(std::vector<int> &_vec)
{
    if (!_vec.empty())
        _qs_3(_vec.begin(), _vec.end());
}
