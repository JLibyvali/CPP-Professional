#pragma once

#include "debug.h"

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <format>
#include <functional>
#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>

namespace test
{

template <typename Value>
void vec_space(std::vector<Value> &_vec, std::string_view _str = "\0")
{

    std::cout << RED << "[" << _str << "] " << NONE << " \033[1;33m" << "Vector element nums: " << _vec.size()
              << "|| Capacity to hold element: " << _vec.capacity()
              << "|| Used Bytes: " << _vec.capacity() * sizeof(_vec[0]) << "\033[0m" << std::endl;
}

class Perf_test
{
public:

    explicit Perf_test(std::vector<std::int32_t> &_vec, size_t _scale);
    ~Perf_test() = default;

    // Test operations
    void test_delete();
    void test_insert();
    void test_find();

    // No other ctor
    Perf_test(const Perf_test &src)            = default;
    Perf_test &operator=(const Perf_test &lhs) = delete;
    Perf_test(Perf_test &&src)                 = delete;
    Perf_test &operator=(Perf_test &&lhs)      = delete;

private:

    // Used for something like `push_back`
    void xxxx_loop_test(
        std::vector<std::int32_t> _vec, std::function<void(std::int32_t)> _func, std::string_view _str = "\0"
    );

    void xxxx_test(
        std::vector<std::int32_t> _vec, std::function<void(void)> _func, bool _free, std::string_view _str = "\0"
    );

    size_t                    m_scale;
    std::vector<std::int32_t> m_vec;
};

Perf_test::Perf_test(std::vector<std::int32_t> &_vec, size_t _scale) : m_scale(_scale), m_vec(_vec) {}

void Perf_test::xxxx_loop_test(
    std::vector<std::int32_t> _vec, std::function<void(std::int32_t)> _func, std::string_view _str
)
{
    auto start{std::chrono::high_resolution_clock::now()};

    for (int i = 0; i < m_scale; i++)
        _func(i);

    auto end{std::chrono::high_resolution_clock::now()};
    std::cout << "Time Cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start) << std::endl;
    vec_space(m_vec, _str);

    // Free all memory
    std::vector<std::int32_t>().swap(m_vec);
}

void Perf_test::xxxx_test(
    std::vector<std::int32_t> _vec, std::function<void(void)> _func, bool _free, std::string_view _str
)
{
    auto start{std::chrono::high_resolution_clock::now()};

    _func();

    auto end{std::chrono::high_resolution_clock::now()};
    std::cout << "Time Cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start) << std::endl;
    vec_space(m_vec, _str);

    // Free all memory
    if (_free)
        std::vector<std::int32_t>().swap(m_vec);
}

void Perf_test::test_insert()
{
    std::cout << std::format(FMT("something like push_back() is O(1) If no memory allocate", YELLOW)) << std::endl;

    auto pushback_wrap    = [&](std::int32_t _val) { m_vec.push_back(_val); };
    auto emplaceback_wrap = [&](std::int32_t _val) { m_vec.emplace_back(_val); };
    auto popback_wrap     = [&](std::int32_t _val) { m_vec.pop_back(); };
    auto op_wrap          = [&](std::int32_t _val) { m_vec[_val] = _val; };
    auto inserttail_wrap  = [&](std::int32_t _val) { m_vec.insert(m_vec.end(), _val); };
    auto inserthead_wrap  = [&](std::int32_t _val) { m_vec.insert(m_vec.begin(), _val); };
    auto insert_wrap      = [&](std::int32_t _val) { m_vec.insert((m_vec.begin() + _val), _val); };

    vec_space(m_vec, "Start");

    std::cout << "Test assign():\n";
    auto start{std::chrono::high_resolution_clock::now()};
    m_vec.reserve(m_scale);
    m_vec.assign(m_scale, 1);
    auto end{std::chrono::high_resolution_clock::now()};
    std::cout << "Time cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start) << std::endl;
    std::vector<std::int32_t>().swap(m_vec);

    std::cout << "push_back():\n";
    xxxx_loop_test(m_vec, pushback_wrap, "No reserve");

    std::cout << "push_back():\n";
    m_vec.reserve(m_scale);
    xxxx_loop_test(m_vec, pushback_wrap, "Reserved");

    std::cout << "emplace_back():\n";
    xxxx_loop_test(m_vec, emplaceback_wrap);

    // pop_back
    std::cout << "pop_back():\n";
    m_vec.resize(m_scale, 1);
    xxxx_loop_test(m_vec, popback_wrap, "Used reserve()");

    std::cout << "operator[]:\n";
    m_vec.resize(m_scale);
    xxxx_loop_test(m_vec, op_wrap, "Used reserve()");

    std::cout << "insert at end:\n";
    xxxx_loop_test(m_vec, inserttail_wrap, "No reserve()");

    std::cout << "insert at someplace:\n";
    xxxx_loop_test(m_vec, insert_wrap);

    std::cout << "Change m_scale case so big insert at head:\n";
    auto tmp = m_scale;
    m_scale  = 0x3f3ff;
    xxxx_loop_test(m_vec, inserthead_wrap);
    m_scale = tmp;
}

void Perf_test::test_delete()
{
    std::cout << FMT("clear() and erase() is O(n)", BLACK) << std::endl;

    auto erasetail_wrap = [&](std::int32_t _val) { m_vec.erase(m_vec.end()); };
    auto erasehead_wrap = [&](std::int32_t _val) { m_vec.erase(m_vec.begin()); };
    auto erase_wrap     = [&](std::int32_t _val) { m_vec.erase(m_vec.begin() + _val); };

    std::cout << "erase at tail:\n";
    m_vec.reserve(m_scale);
    m_vec.assign(m_scale, 0xff);
    xxxx_loop_test(m_vec, erasetail_wrap);

    auto tmp = m_scale;
    m_scale  = 0x3f3ff;
    std::cout << "erase at someplace:\n";
    m_vec.reserve(m_scale);
    m_vec.assign(m_scale, 0xff);
    xxxx_loop_test(m_vec, erase_wrap);

    std::cout << "erase at head:\n";
    m_vec.reserve(m_scale);
    m_vec.assign(m_scale, 0xff);
    xxxx_loop_test(m_vec, erasehead_wrap);
}

void Perf_test::test_find()
{

    std::cout << FMT("Test some algorithm", YELLOW) << std::endl;

    auto find_wrap    = [&]() { std::find(m_vec.cbegin(), m_vec.cend(), m_scale - 0xffff); };
    auto reverse_wrap = [&]() { std::reverse(m_vec.begin(), m_vec.end()); };
    auto sort_wrap    = [&]() { std::sort(m_vec.begin(), m_vec.end()); };

    m_vec.resize(m_scale);
    for (int i = 0; i < m_scale; i++)
    {
        m_vec[i] = i;
    }

    std::cout << "find:\n";
    xxxx_test(m_vec, find_wrap, false);

    std::cout << "reverse:\n";
    xxxx_test(m_vec, reverse_wrap, false);

    std::cout << "sort:\n";
    xxxx_test(m_vec, sort_wrap, true);
}

}  // namespace test
