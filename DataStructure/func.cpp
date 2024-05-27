#include <cstdio>
#include <exception>
#ifdef LIST1
#include "DoublyList.h"
#endif

#ifdef LIST2
#include "SingalList.h"
#endif

#include <cmath>
#include <random>
#include <vector>



using namespace std;

#ifdef LIST1
void DoublyListPrac(void) {

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
    uniform_int_distribution<int> distriList(1, 1333);

    for (auto &ele : randNUM) {
        ele = distriList(gen64);
    }

    DoubleList dlist;
    for (int i = 0; i < 3; i++) {
        dlist.insert(randNUM[i], 0);
    }
    for (int i = 3; i < 7; i++) {
        dlist.insert(randNUM[i], 1);
    }

    dlist.print();
    dlist.reverse();
    dlist.print();

    node res = dlist.del_ele(randNUM[4]);
    printf("Dele node: %d \n", res.id);
    dlist.print();

    printf("Getnode: %d \n", dlist.get_node(randNUM[0]).id);

    dlist.change_node(randNUM[0], 999999);
    dlist.print();

    dlist.clearList();
    printf("=================================\n");
    dlist.print();
}

#endif

#ifdef LIST2
void SingalListPrac(void) {

    vector<double> randomNUM(1000, 0.0);
    random_device rd;
    mt19937_64 gen64(rd());

    // using normal distribution
    double mean   = 10;
    double stddev = 2.45;
    normal_distribution<double> ndistr(mean, stddev);

    for (auto &ele : randomNUM)
        ele = ndistr(gen64);

    SList sl;
    try {
        for (int i = 0; i < 3; i++) {
            sl.insert(0, randomNUM[i]);
            sl.insert(1, randomNUM[i + 1]);
        }
        sl.print();

        printf("Reverse: \n");
        sl.reverse();
        sl.print();


        printf("Get Node : %.6f \n",sl.get_node(randomNUM[0]).id);
        printf("Change node : from %.6f  to %.6f \n",sl.get_node(randomNUM[2]).id,sl.chang_node(randomNUM[2], 99999.9).id);

        printf("Delete node : %.6f\n",sl.del(randomNUM[1]).id);
        sl.print();

        printf("Clear List: \n ");
        sl.clear();
        sl.print();
    }catch(const exception& ex){
        printf("Exception occurred: %s, exit\n",ex.what());
    }
}

#endif




