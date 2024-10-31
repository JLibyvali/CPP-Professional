#include <iostream>
#include <mutex>
#include <syncstream>
#include <thread>

class Counter_synio
{
public:

    explicit Counter_synio(int _id, int _num) : m_id(_id), m_num(_num) {}

    void operator()() const
    {
        // Synchronous stream for multi threads
        std::osyncstream synOut{std::cout};

        for (int i = 0; i < m_num; i++)
        {
            synOut << "Synchronous Stream output " << m_id << " :" << i << std::endl;
        }
    }

private:

    int m_id;
    int m_num;
};

int main()

{

    std::cout << "Test mutex lock" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::thread th{Counter_synio{i, 20}};
        th.join();
    }

    return 0;
}