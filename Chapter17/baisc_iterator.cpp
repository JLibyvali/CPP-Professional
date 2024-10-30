#include <iostream>
#include <iterator>

// Input Iterator
// Output Iterator
// Forward Iterator
// BidirectionalIterator
// Random Iterator
// Contiguous Iterator

// Logic chain
// Contiguous Iterator must be Random Iterator ----> Bidirectional Iterator ----> Forward Iterator ----> input Iterator

template <typename Iterator> void iterator_trait(Iterator _it)
{

    typename std::iterator_traits<Iterator>::value_type element;
    typename std::iterator_traits<Iterator>::pointer    pointer;

    element = *_it;
    pointer = &(*_it);

    std::cout << "Iter value: " << element << " Pointer type: " << pointer << std::endl;
}

int main()
{
    std::cout << "Iterator Type trait." << std::endl;
    char str[] = "Hello World.";

    iterator_trait(std::begin(str));

    return 0;
}
