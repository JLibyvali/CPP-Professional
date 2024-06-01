#ifndef __QUEUE_H
#define __QUEUE_H

#include <string>
namespace que {

const static int MAX_LEN = 100;
struct qnode {

    int id;
    char c;

    qnode(int _id = 0, char _c = 'Z' ){
        id    = _id;
        c     = _c;
    }
};

/**
 * @brief circle queue full: (rear+1)%QueueTotalSize == front, it means that 'rear' will not overlapping  with 'front'. Still exist one blank.
          circle queue empty condition: rear == front
 When 'rear' > 'front', queue length = rear - front
 When 'rear' < 'front', queue length = (rear - 0) + (QueueTotalSize - front).
 So the length = (rear - front + QueueTotalSize) % QueueTotalSize.
 * 
 */
class Queue_circle {
  public:
    Queue_circle() {
        front = rear  = 0;
        data[MAX_LEN] = {qnode()};
    }

    int getLen();
    int push(const qnode &ele);
    qnode &pop();
    void print();

  private:
    int front;
    int rear;
    qnode data[MAX_LEN];
};

class Queue_list {
};

}

#endif