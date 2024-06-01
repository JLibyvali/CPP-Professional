#include "Queue.h"
#include <cstdio>
#include <stdexcept>

int que::Queue_circle::getLen() {

    return (this->rear - this->front + MAX_LEN) % MAX_LEN;
}

int que::Queue_circle::push(const qnode &ele) {

    if ((this->rear + 1) % MAX_LEN == this->front)
        return -1;

    this->data[this->rear] = ele;

    // rear pointer plus 1, If reach the end of data, set it at data begin
    this->rear = (this->rear + 1) % MAX_LEN;
    return 0;
}

que::qnode &que::Queue_circle::pop() {

    if (this->front == this->rear)
        throw std::runtime_error("Queue is empty\n");

    qnode *tmp = new qnode();

    tmp = &this->data[this->front];

    /**
     * @brief step this->front back, if reach the end of data, turn it to the begin.
     *
     */
    this->front = (this->front + 1) % MAX_LEN;

    return *tmp;
}

void que::Queue_circle::print() {

    if (this->front == this->rear)
        return;

    printf("Queue front: \n");

    if (this->front < this->rear) {

        for (int i = this->front; i <= this->rear; i++) {
            printf("----------\n");
            printf("Queue node{id: %d, c: %c } \n", this->data[i].id, this->data[i].c);
            printf("------------\n");
        }
    } else {

        for (int i = this->front; i < MAX_LEN; i++) {

            printf("----------\n");
            printf("Queue node{id: %d, c: %c, }", this->data[i].id, this->data[i].c);
            printf("------------\n");
        }

        for (int j = 0; j <= this->rear; j++) {

            printf("----------\n");
            printf("Queue node{id: %d, c: %c, }", this->data[j].id, this->data[j].c);
            printf("------------\n");
        }
    }

    printf("Queue end\n");
    return;
}