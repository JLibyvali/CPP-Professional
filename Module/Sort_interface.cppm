module;
#include <vector>
export module Sort:interface;

namespace m_sort
{
export void bubble(std::vector<int> &_vec);
export void quick_sort(std::vector<int> &_vec);
export void qs_3(std::vector<int> &_vec);
}  // namespace m_sort
