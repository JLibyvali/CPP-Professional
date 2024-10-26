#include <concepts>
#include <cstdio>
#include <format>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

class Resource
{
public:

    Resource() : Resource(1, 1) {}

    Resource(int rows, int cols) : m_weight(rows), m_height(cols)
    {
        m_buf = new char *[m_weight];
        for (int i = 0; i < m_weight; i++)
        {
            m_buf[i]  = new char[m_height];
            *m_buf[i] = 'A';
        }
    }

    ~Resource()
    {
        for (int i = 0; i < m_weight; i++)
        {
            delete[] m_buf[i];
            m_buf[i] = nullptr;
        }

        delete[] m_buf;
        m_buf = nullptr;
    }

    int    m_weight, m_height;

    char **m_buf;  // Only for showing, not safe
};

void print_RS(Resource &res)
{
    std::stringstream ss;

    ss << "Resource members: \n";
    for (int i = 0; i < res.m_weight; i++)
    {
        for (int j = 0; j < res.m_height; j++)
        {
            ss << std::format("Address: {}  \tValue:  {} \n", (void *)&res.m_buf[i][j], res.m_buf[i][j]);
        }
    }

    ss << "End........\n";

    std::cout << ss.str() << std::endl;
}

int main()
{
    Resource rs{10, 20};
    print_RS(rs);

    return 0;
}
