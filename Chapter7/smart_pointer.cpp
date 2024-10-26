#include <algorithm>
#include <cstdio>
#include <iostream>
#include <memory>
#include <sstream>
#include <type_traits>
#include <utility>

struct node final
{
    int                   m_id;
    std::shared_ptr<node> m_next;

    // Ctor
    node() : node(1) {}

    node(int _id) : m_id(_id), m_next(nullptr) {}

    // RAII
    node(const node &src)      = delete;
    node &operator=(node &rhs) = delete;

    node(node &&src) noexcept : m_id(src.m_id), m_next(std::move(src.m_next))
    {
        // Clear original  object
        src.m_id = -1;
    }

    node &operator=(node &&rhs) noexcept
    {
        if (this == &rhs)
            return *this;

        m_id     = rhs.m_id;
        m_next   = std::move(rhs.m_next);
        // Why use std::move can use the `move sematic`
        // Case `std::move` only transfer params to a rvalue, so it can be moveD.
        // the right value will trigger shared_ptr move assignment or move ctor.
        // So implement the move sematic

        // Clear original  object
        rhs.m_id = -1;
        return *this;
    }
};

class List
{
public:

    List() : List(1) {}

    List(int _id)
    {
        auto tmp = std::make_shared<node>(_id);
        m_head   = tmp;
    }

    // RAII
    List(const List &src)      = delete;
    List &operator=(List &rhs) = delete;

    // move
    List(List &&src) noexcept;
    List &operator=(List &&rhs) noexcept;

    void  insert(std::shared_ptr<node> &_node)
    {
        if (m_head == nullptr)
            return;

        // Insert at head position
        _node->m_next = m_head;
        m_head        = _node;

        return;
    }

    // Return pointer
    void reverse()
    {
        if (m_head == nullptr)
            return;

        std::shared_ptr<node> prev = nullptr, cur = m_head, nx = m_head->m_next;

        while (nx != nullptr)
        {
            cur->m_next = prev;
            prev        = cur;
            cur         = nx;

            nx          = nx->m_next;
        }

        cur->m_next = prev;
        m_head      = cur;
    }

    void print() const
    {

        if (m_head == nullptr)
            return;

        auto              tmp = m_head;

        std::stringstream ss;

        while (tmp != nullptr)
        {
            ss << "Address: " << tmp.get() << "\tValue:  " << tmp->m_id << "\n";
            tmp = tmp->m_next;
        }

        std::cout << ss.str() << std::endl;
    }

private:

    std::shared_ptr<node> m_head;
};

int main()
{
    List list(3);

    for (int i = 0; i < 100; i++)
    {
        auto tmp = std::make_shared<node>(i);
        list.insert(tmp);
    }

    list.print();

    std::cout << "Reverse :" << std::endl;
    list.reverse();
    list.print();

    return 0;
}