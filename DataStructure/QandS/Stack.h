#ifndef __STACK_H
#define __STACK_H

#include <cstdint>
#include <cstdio>
#include <exception>

namespace stk {

const int MAX_LEN = 100;

struct SElem {
    int id;
    char c;

    SElem(int _id = 0, char _c = 'A') {
        id = _id;
        c  = _c;
    }
};

// Linear  Stack
class StackLinear {

  public:
    StackLinear();
    std::exception push(const SElem &ele);
    SElem &pop();
    uint8_t getlen();
    SElem &changeStk(const SElem &before, const SElem &after);
    std::exception printStk();
    std::exception clearStk();

    std::exception bind(StackLinear &stk1, StackLinear stk2);

  private:
    SElem *data[MAX_LEN]{nullptr};
    int top = -1;
};

// List Stack
struct snode {
    SElem data;
    snode *next;
    snode *prev;

    snode() {
        data = SElem();
        next = prev = nullptr;
    }
    snode(int _id, char _c) {
        data = SElem(_id, _c);
        next = prev = nullptr;
    }
};

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