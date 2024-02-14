//
// Created by jlibyvali on 24-1-30.
//

#include <vector>
#include <initializer_list>

namespace InitialList{
    class MagicFoo;
}

 class InitialList::MagicFoo{
public:
    // Traditional C++ use the 'Copy-value' way to initial class object, but after C++11 we can use 'InitialList' to be more common.
    /* Tradition way inital:
     * class InitialList::MagicFoo{
     *   int a,b;
     *   MagicFoo(int value_a,int value_b) : a(value_a), b(value_b) {}
     * }
    * */
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();it != list.end(); ++it) {
            vec.push_back(*it);
        }
        
    }
    // InitialList can also use in function

};