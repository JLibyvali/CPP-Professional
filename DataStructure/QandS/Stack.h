#ifndef __STACK_H
#define __STACK_H

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <exception>

namespace stk {

const int MAX_LEN = 100;

// Forward declaration
class StackLinear;
class StackLinearB;

StackLinearB &bind(StackLinear &stk1, StackLinear &stk2);

// Linear  Stack
struct SElem {
    int id;
    char c;

    SElem(int _id = 0, char _c = 'A') {
        id = _id;
        c  = _c;
    }
};

class StackLinear {
  public:
    // create one stack
    friend StackLinearB &bind(StackLinear &stk1, StackLinear &stk2);
    
    StackLinear() {
        top1    = -1;
        data[0] = nullptr;
    }

    int push(const SElem &ele);
    SElem &pop();

    int8_t getlen();
    SElem &changeStk(const SElem &before, const SElem &after);
    void printStk();
    int clearStk();

    SElem *data[MAX_LEN]{nullptr};
    int top1 = -1;
};

class StackLinearB : public StackLinear {
  public:
    StackLinearB() {}

    StackLinearB(int _top1 , int _top2) {
        top1 = _top1;
        top2 = _top2;

        for(int i=0;i<2*MAX_LEN;i++){
            dataB[i] = nullptr;
        }
    }

    int pushB(SElem &ele, int stkn);
    SElem &popB(int stk);
    void printStkB(void);

    int top1                  = -1;
    int top2                  = 2 * MAX_LEN;
    SElem *dataB[2 * MAX_LEN];
};


// List Stack
struct snode {
    SElem data;
    snode *next;

    snode() {
        data = SElem();
        next = nullptr;
    }
    snode(int _id, char _c) {
        data = SElem(_id, _c);
        next = nullptr;
    }
};

/**
 * @brief It's just the Single list, push and pop at head.
 * 
 */
class StackList {
  public:
    StackList();
    StackList(int _id, char _c);

    uint8_t getlen();
    std::exception push(const snode &stk);
    snode &pop();
    std::exception printStk();
    std::exception clearStk();
    snode &changeStk(const snode &before, const snode &after);

  private:
    inline static snode *HEAD = nullptr;
    inline static snode *END  = nullptr;
};

}
#endif