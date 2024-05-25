#include "DoublyList.h"
#include <cstdio>
#include <iterator>
#include <random>
#include <vector>

using namespace std;

void listPrac() {

    /**
     * @brief Random num generate
     * 1. select device and engine
       2. select distribution, and num type
       3. using the distribution and engine
     */
    vector<int> randNUM(1000, 0);
    random_device rd;
    mt19937_64 gen64(rd());

    // using linera distribution random 
    uniform_int_distribution<int> distriList(1,1333);

    for (auto &ele : randNUM){
        ele = distriList(gen64);
    }

    DoubleList dlist;
    for (int i = 0; i < 3; i++) {
       dlist.insert(randNUM[i],0); 
    }
    for (int i = 3; i < 7; i++) {
       dlist.insert(randNUM[i],1); 
    }

    dlist.print();
    dlist.reverse();
    dlist.print();

    node res  = dlist.del_ele(randNUM[4]);
    printf("Dele node: %d \n",res.id);
    dlist.print();

    printf("Getnode: %d \n",dlist.get_node(randNUM[0]).id);

    dlist.change_node(randNUM[0], 999999);
    dlist.print();

    dlist.clearList();
    printf("=================================\n");
    dlist.print();

}

int main() {
    listPrac();

    return  0;
}
