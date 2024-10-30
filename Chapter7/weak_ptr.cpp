#include <iostream>
#include <memory>

// Show shared_ptr circular reference
struct nodeA;
struct nodeB;

struct nodeA
{
    nodeA() {}

    ~nodeA() { std::cout << "NodeA destroyed" << std::endl; }

    std::shared_ptr<nodeB> m_b;
};

struct nodeB
{
    nodeB() {}

    ~nodeB() { std::cout << "NodeB  destroyed" << std::endl; }

    std::weak_ptr<nodeA> m_a;
};

int main()

{

    std::cout << "Test shared_ptr circular reference case memory leak." << std::endl;
    auto a = std::make_shared<nodeA>();
    auto b = std::make_shared<nodeB>();

    a->m_b = b;
    // Use weak_ptr to break circular  reference,
    b->m_a = std::weak_ptr(a);

    std::cout << "Pointer a count: " << a.use_count() << ", Pointer b count: " << b.use_count() << std::endl;

    return 0;
}