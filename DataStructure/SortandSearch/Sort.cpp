#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <random>
#include <ratio>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

std::vector<int> rand_num;
std::vector<int> nearly_num;
std::vector<int> reverse_num;
std::vector<int> few_unique_num;

void init_num() {

    rand_num.resize(30);
    nearly_num.resize(30);
    reverse_num.resize(30);
    few_unique_num.resize(30);

    // rand_num
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 100);

    for (auto it1 = rand_num.begin(); it1 != rand_num.end(); ++it1) {
        *it1 = dis(gen);
    }

    // nearly_num
    int i = 1;
    for (auto &ele : nearly_num) {
        ele = i++;

        if (ele % 3 == 0) {
            ele = i - 2;
        }
    }

    // reverse_num
    for (int i = 0; i < 30; i++) {
        reverse_num[i] = i;
    }

    // few unique num

    for (int j = 0; j < 30; j++) {
        few_unique_num[j] = 3;

        if (j >= 4 && j <= 8) few_unique_num[j] = 5;

        if (j >= 9 && j <= 19) few_unique_num[j] = 8;

        if (j >= 20) few_unique_num[j] = 12;
    }
}

std::vector<int> selection_sort(std::vector<int> &src) {

    std::vector<int> vec;
    vec.assign(src.begin(), src.end());

    int cnt = vec.size();
    int ith;

    for (int i = 0; i < cnt - 1; i++) {
        ith = i;

        for (int j = i + 1; j < cnt; j++) {

            if (vec[j] < vec[ith]) ith = j;
        }

        if (ith != i) std::swap(vec[ith], vec[i]);
    }

    return vec;
}

std::vector<int> bubble_sort(std::vector<int> &src) {

    std::vector<int> vec;
    vec.assign(src.begin(), src.end());

    int len = vec.size();

    for (int i = 0; i < len - 1; i++) {
        bool ifswap = false;

        for (int j = i + 1; j < len - 1 - i; j++) {

            if (vec[i] > vec[j]) {
                std::swap(vec[i], vec[j]);
                ifswap = true;
            }
        }

        if (!ifswap) break;
    }

    return vec;
}

std::vector<int> insertion_sort(std::vector<int> &src, bool optimized = false) {

    std::vector<int> vec;
    vec.assign(src.begin(), src.end());

    int len = vec.size();

    for (int i = 1; i < len; i++) {

        if (vec[i - 1] > vec[i]) {
            int j   = i - 1;
            int tmp = vec[i];

            while (j >= 0 && tmp < vec[j]) { // all elements move backward
                vec[j + 1] = vec[j];
                j--;
            }

            vec[j + 1] = tmp;
        }
    }

    if (optimized) { // Binary Search
        if (len < 2) return vec;
        auto it_begin = vec.begin();
        auto it_end   = vec.end();

        for (auto it = it_begin; it != it_end; ++it) {
            std::rotate(std::upper_bound(it_begin, it, *it), it, std::next(it));
        }
    }

    return vec;
}

/**
 * @brief Quick Sort, using loop and  recursion implement
 */

template <typename T>
int partition(std::vector<T> &src, int low, int high) {

    int pivot = src[low];

    while (low < high) {

        while (low < high && src[low] <= pivot) low++;
        src[high] = src[low];

        while (low < high && src[high] >= pivot) high--;
        src[low] = src[high];
    }

    src[low] = pivot;

    return low;
}

template <typename T>
void quick_sort(std::vector<T> &src, int low, int high) {

    if (low < high) {
        int mid_index = partition(src, low, high);

        quick_sort(src, low, mid_index - 1);
        quick_sort(src, mid_index + 1, high);
    }
}

template <typename T>
std::vector<T> quick_sort_recursion(std::vector<T> &src) {

    std::vector<T> vec;
    vec.assign(src.begin(), src.end());

    quick_sort(vec, 0, vec.size() - 1);
    return vec;
}

template <typename T>
std::vector<T> quick_sort_loop(std::vector<T> &src) {

    std::vector<T> vec;
    vec.assign(src.begin(), src.end());
    int len = vec.size();
    if (len < 2) return vec;

    std::tuple<int, int> stk[len]; // simulate the stack
    int p = 0;

    stk[p++] = std::make_tuple(0, len - 1); // Empty stack

    while (p) {
        auto [low, high] = stk[--p];
        if (low >= high) continue;
        T pivot  = vec[high];
        int left = low, right = high - 1;

        while (left < right) {
            while (left < right && vec[left] < pivot) left++;
            while (left < right && vec[right] >= pivot) right--;

            std::swap(vec[left], vec[right]);
        }

        if (vec[left] >= vec[high])
            std::swap(vec[left], vec[high]);
        else
            left++;

        // push sub-part
        if (low < left - 1) stk[p++] = std::make_tuple(low, left - 1);

        if (left + 1 < high) stk[p++] = std::make_tuple(left + 1, high);
    }

    return vec;
}

template <typename T>
std::vector<T> quick_sort3(std::vector<T> &src) {

    std::vector<T> vec;
    vec.assign(src.begin(), src.end());

    int len = vec.size();
    if (len < 2) return vec;

    const T pivot = vec[std::rand() % len];

    // three part
    // [low,tmp), [tmp,high),[high,len);
    //   < pivot, = pivot,  > pivot
    int low = 0, tmp = 0, high = len;

    while (low < high) {

        if (vec[low] < pivot)
            std::swap(vec[low++], vec[tmp++]);
        else if (vec[low] > pivot)
            std::swap(vec[low], vec[--high]);
        else
            low++;
    }

    std::vector<T> first, second;
    first.assign(vec.begin(), vec.begin() + tmp);
    second.assign(vec.begin() + high, vec.end());

    quick_sort3(first);
    quick_sort3(second);

    return vec;
}

template <typename T>
T first_kth_num(std::vector<T> &src, int kth) {

    int len = src.size();
    if (len < 2) return -1;

    const T pivot = src[rand() % len];

    int cur = 0, tmp = 0, high = len;

    while (cur < high) {

        if (src[cur] < pivot)
            std::swap(src[cur++], src[tmp++]);
        else if (src[cur] > pivot)
            std::swap(src[cur++], src[--high]);
        else
            cur++;
    }

    std::vector<T> next;

    if (kth < tmp) {
        next.assign(src.begin(), src.begin() + tmp);
        return first_kth_num(next, kth);
    } else if (kth >= high) {
        next.assign(src.begin() + high, src.end());
        return first_kth_num(next, kth);
    } else {
        return pivot;
    }
}

template <typename T>
std::vector<T> merge_sort(std::vector<T> &src) {

    std::vector<T> vec{src.begin(), src.end()};

    // Divide and Conquer
    int len = vec.size();
    if (len < 2) return vec;

    int left = 0, right = vec.size() - 1;
    int mid = left + ((right - left) >> 1);

    std::vector<T> first, second;
    first.assign(vec.begin(), vec.begin() + mid);
    second.assign(vec.begin() + mid, vec.end());

    merge_sort(first);
    merge_sort(second);

    // merge
    std::vector<T> res;
    res.resize(1024); // Should big enough to store the merge  result
    std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(res));
    // src.assign(res.begin(), res.end());
    vec.swap(res);

    return vec;
}

/**
 * @brief Heap sort
 */
template <typename T>
void heapify(std::vector<T> &src, int head_index) {

    int len     = src.size();
    int parrent = head_index;
    int child   = parrent * 2 + 1; // left child

    while (child < len) {
        // compare  two child node
        if (child + 1 < len && src[child] < src[child + 1]) child++;

        // compare child and parrent
        if (src[parrent] > src[child]) {
            return;
        } else {
            // continue grandchild node
            std::swap(src[child], src[parrent]);
            parrent = child;
            child   = parrent * 2 + 1;
        }
    }
}

template <typename T>
std::vector<T> heap_sort(std::vector<T> &src) {

    std::vector<T> vec;
    vec.assign(src.begin(), src.end());

    int len = vec.size();

    // finish heapify
    for (int i = (len - 1 - 1) / 2; i >= 0; i--) heapify(vec, i);
    for (int i = len - 1; i >= 0; i--) {
        std::swap(vec[0], vec[i]); // Change the root-node of heap and the bottom-node
        heapify(vec, 0);           // Rebuild the heap
    }

    return vec;
}

template <typename T>
std::vector<T> shell_sort(std::vector<T> &src) {

    std::vector<T> vec;
    vec.assign(src.begin(), src.end());

    // h is gap sequence index
    int h = 1, len = vec.size();

    while (h < len / 3) {
        h = (h * 3 + 1);
    }

    while (h >= 1) {
        for (int i = h; i < len; i++) {

            for (int j = i; j >= h && vec[j] < vec[j - h]; j -= h) {
                std::swap(vec[j], vec[j - h]);
            }
        }

        h /= 3;
    }

    return vec;
}

int main() {

    //  initial num
    init_num();
    std::vector<int> nums[] = {rand_num, nearly_num, reverse_num, few_unique_num};
    std::string_view funcs[]{"Selection Sort", "Bubble Sort", "Quick Sort Recursion", "Quick Sort Loop", "Quick3", "Heap Sort", "Shell Sort"};

    // sort functions
    using sort_type           = std::function<std::vector<int>(std::vector<int> &)>;
    using insertion_sort_type = std::function<std::vector<int>(std::vector<int> &, bool)>;
    using first_kth_num_type  = std::function<int(std::vector<int> &, int)>;

    auto sort_funcs = std::make_tuple(
        sort_type(selection_sort),
        sort_type(bubble_sort),
        sort_type([](std::vector<int> &src) -> std::vector<int> {
            return quick_sort_recursion(src);
        }),
        sort_type([](std::vector<int> &src) -> std::vector<int> {
            return quick_sort_loop(src);
        }),
        sort_type([](std::vector<int> &src) -> std::vector<int> {
            return quick_sort3(src);
        }),
        // sort_type([](std::vector<int> &src) -> std::vector<int> {
        //     return merge_sort(src);
        // }),
        sort_type([](std::vector<int> &src) -> std::vector<int> {
            return heap_sort(src);
        }),
        sort_type([](std::vector<int> &src) -> std::vector<int> {
            return shell_sort(src);
        })
        // insertion_sort_type(insertion_sort),
        // first_kth_num_type([](std::vector<int> &src, int kth) -> int {
        //     return first_kth_num(src, kth);
        // })
    );

    // Print all test res
    auto print_res = [](const std::vector<std::tuple<std::chrono::duration<double>, std::vector<int>, std::string_view>> ans, const std::string_view &func_name) {
        std::ostringstream ss;
        ss << "Test for: " << func_name << " \n";
        for (const auto &ele : ans) {
            ss << std::setw(4) << std::get<2>(ele) << "-"
               << std::chrono::duration<double, std::micro>{std::get<0>(ele)}.count() << "us :";

            std::for_each(std::get<1>(ele).begin(), std::get<1>(ele).end(), [&ss](const int val) {
                ss << val << " ";
            });
            ss << "\n";
        }
        std::cout << ss.str() << std::endl;
    };

    // Test  perfomance
    using test_perfomance_rtype = std::vector<std::tuple<std::chrono::duration<double>, std::vector<int>, std::string_view>>;
    auto test_perfomance        = [&](sort_type &func) -> test_perfomance_rtype {
        test_perfomance_rtype ans;
        ans.resize(4);
        std::get<2>(ans[0]) = "Random nums";
        std::get<2>(ans[1]) = "Nearly nums";
        std::get<2>(ans[2]) = "Reserve nums";
        std::get<2>(ans[3]) = "Few unique nums";

        for (int i = 0; i < 4; i++) {

            auto start{std::chrono::high_resolution_clock::now()};
            auto tmp = func(nums[i]);
            auto end{std::chrono::high_resolution_clock::now()};

            auto diff{end - start};
            std::get<0>(ans[i]) = diff;
            std::get<1>(ans[i]) = tmp;
        }

        return ans;
    };

    std::cout << "################################BEGIN##########################################" << std::endl;

    // auto tmp = test_perfomance(std::get<5>(sort_funcs));

    std::vector<test_perfomance_rtype> tmp;
    tmp.clear();

    std::apply([&](auto &...Args) {
        ((tmp.push_back(test_perfomance(Args))), ...);

        int i = 0;
        for (const auto &ele : tmp) {
            print_res(ele, funcs[i++]);
        }
    },
               sort_funcs);

    return 0;
}