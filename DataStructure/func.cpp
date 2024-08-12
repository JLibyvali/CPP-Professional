#include <cstddef>
#include <cstdio>
#include <exception>
#include <functional>
#include <ratio>
#include <type_traits>
#include <utility>
#ifdef LIST1
#include "DoublyList.h"
#endif

#ifdef LIST2
#include "SingalList.h"
#endif

#include <cmath>
#include <random>
#include <vector>
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

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

        printf("Get Node : %.6f \n", sl.get_node(randomNUM[0]).id);
        printf("Change node : from %.6f  to %.6f \n", sl.get_node(randomNUM[2]).id, sl.chang_node(randomNUM[2], 99999.9).id);

        printf("Delete node : %.6f\n", sl.del(randomNUM[1]).id);
        sl.print();

        printf("Clear List: \n ");
        sl.clear();
        sl.print();
    } catch (const exception &ex) {
        printf("Exception occurred: %s, exit\n", ex.what());
    }
}

void PracStack(void) {

    std::vector<stk::SElem> vec(100, {0, '0'});

    std::random_device rd;
    std::mt19937_64 gen64;

    std::uniform_int_distribution<int> dist(65, 90);

    for (auto &ele : vec) {

        int num = dist(gen64);
        ele.id  = num;
        ele.c   = num;
    }

    stk::StackLinear stack1;
    for (int i = 0; i < 5; i++) {
        stack1.push(vec[i]);
    }

    stack1.printStk();

    stk::SElem ans = stack1.pop();
    printf("Pop id: %d, c: %c \n", ans.id, ans.c);

    stk::SElem ans2 = stack1.changeStk(vec[2], vec[99]);
    printf("Chang id: %d, c: %c \n", ans2.id, ans2.c);
    stack1.printStk();

    stk::StackLinear stack2;
    for (int i = 10; i < 14; i++) {
        stack2.push(vec[i]);
    }

    stk::StackLinearB stackB = stk::bind(stack1, stack2);

    stackB.printStkB();
}

void Pracque(void) {

    std::random_device rd;
    std::mt19937 gen;

    std::uniform_int_distribution<int> dist(1, 120);

    std::vector<que::qnode> vec(20, {que::qnode()});

    for (int i = 0; i < 20; i++) {
        vec[i].id = dist(gen);
        vec[i].c  = 'T';
    }

    que::Queue_circle quecircl;
    for (int i = 0; i < 3; i++) {
        quecircl.push(vec[i]);
    }

    quecircl.print();

    for (int i = 0; i < 3; i++) {
        quecircl.push(vec[i]);
    }

    quecircl.print();
}



// void func(tre::tnode &next) {

//     if (next.lchild == nullptr && next.rchild == nullptr) {
//         next.lchild = new  tre::tnode(next.id+1);
//         next.rchild = new  tre::tnode(next.lchild->id+1);
//         return;
//     }

//     func(*next.lchild);

//     func(*next.rchild);

//     return;

// }
// void PracTree() {

//     random_device dev;
//     mt19937_64 gen;

//     uniform_int_distribution<int> dist(111, 999);

//     vector<int> vec(20, 0);

//     for (auto &ele : vec) {
//         ele = dist(gen);
//     }

//     tre::Tree tree;

//     bool fla = true;
//     for (int i = 0; i < 3; i++) {
//         func(tree.Root());
//     }

//     tree.PreOrderTra(tree.Root());
// }

#endif
