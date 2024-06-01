#include "Stack.h"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <stdexcept>

int8_t stk::StackLinear::getlen() {

    if (top1 == -1)
        return -1;

    return (top1 + 1);
}

/**
 * @brief push node
 *
 * @param ele
 * @return int
 */
int stk::StackLinear::push(const SElem &ele) {
    if (++top1 < MAX_LEN) {
        SElem *tmp = new SElem(ele.id, ele.c);

        data[top1] = tmp;
        return 0;
    } else {
        throw std::runtime_error("Stack overflow\n");
    }
}

/**
 * @brief pop and return poped node
 *
 * @return stk::SElem&
 */
stk::SElem &stk::StackLinear::pop() {

    if (top1 == -1)
        throw std::runtime_error("Stack is empty\n");

    SElem *tmp = data[top1];
    top1--;

    return *tmp;
}

stk::SElem &stk::StackLinear::changeStk(const SElem &be, const SElem &after) {

    if (top1 == -1)
        throw std::runtime_error("Stack is empty\n");

    SElem *tmp;
    for (int i = 0; i <= top1; i++) {

        if (data[i]->id == be.id) {
            data[i]->id = after.id;
            data[i]->c  = after.c;

            tmp = data[i];
            return *tmp;
        }
    }

    throw std::runtime_error("None matched node\n");
}

int stk::StackLinear::clearStk() {

    if (top1 == -1)
        return -1;

    for (top1; top1 >= -1; --top1) {

        data[top1] = nullptr;
    }

    return 0;
}

void stk::StackLinear::printStk(void) {

    printf("Top ele:\n");

    for (int i = top1; i >= 0; i--) {

        printf("--------------------\n");
        printf("| Ele id: %d, c: %c |\n", (data[i])->id, data[i]->c);
        printf("--------------------\n");
        printf("\\|/\n");
    }
}

stk::StackLinearB &stk::bind(stk::StackLinear &stk1, stk::StackLinear &stk2) {

    int top1 = stk1.top1, top2 = stk2.top1;

    StackLinearB *stkB = new StackLinearB(top1, MAX_LEN + (MAX_LEN - top2));

    for (int i = 0; i <= top1; ++i) {
        stkB->dataB[i] = stk1.data[i];
    }
    
    for (int j = (2 * MAX_LEN - 1), k =0 ; j > MAX_LEN+(MAX_LEN - top2); --j,k++) {
        stkB->dataB[j] = stk2.data[k];
    }

    return *stkB;
}

int stk::StackLinearB::pushB(SElem &ele, int stkn) {

    if (stkn != 1 || stkn != 2) {
        throw std::runtime_error("Stack number wrong");
    } else {

        if (stkn == 1) {

            if (top1 + 1 == top2) {

                throw std::runtime_error("Stack overflow\n");

            } else {
                dataB[++top1] = &ele;
                return 0;
            }

        } else {

            if (top2 - 1 == top1) {
                throw std::runtime_error("Stack overflow\n");
            } else {
                dataB[--top2] = &ele;
                return 0;
            }
        }
    }
}

stk::SElem &stk::StackLinearB::popB(int stkn) {

    if (stkn != 1 || stkn != 2) {
        throw std::runtime_error("Stack number is wrong\n");
    } else {

        if (stkn == 1) {
            SElem *res = dataB[top1--];
            return *res;
        } else {

            SElem *res = dataB[top2++];
            return *res;
        }
    }
}

void stk::StackLinearB::printStkB(void) {

    printf("---------------------------------\n");
    for (int i = 0; i < 2 * MAX_LEN; i++) {
        if (dataB[i] == nullptr) {
            continue;
        } else {
            if (i > MAX_LEN - 1) {
                printf("|ST2 id: %d, c: %c\n", dataB[i]->id, dataB[i]->c);
                printf("---------------------------------\n");
                printf("    \\|/    \n");

            } else {

                printf("|ST1 id: %d, c: %c\n", dataB[i]->id, dataB[i]->c);
                printf("---------------------------------\n");
                printf("    \\|/    \n");
            }
        }
    }
}




