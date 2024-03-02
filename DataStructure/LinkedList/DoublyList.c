//
// Created by jlibyvali on 24-2-29.
//

#include <stdio.h>
#include <stdlib.h>


struct Node {

    int data;
    struct Node *next;
    struct Node *prev;

};
struct Node *HEAD;

void insert(int _data, int _pos) {  // insert in any position

    /* 'malloc' or 'new'
     * 'void malloc()' will return one pointer to the memory block, so after type-conversion.
     * will ask one memory block in 'Heap' , it will be live when the function dead.
     * But just: struct Node* newNode; is creating one local variable.
     * the local variable will be destroying when the function dead.
     * */
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->data = _data;  // Node Init
    newNode->next = NULL;
    newNode->prev = NULL;

    int length = 0;
    if (HEAD == NULL) {
        HEAD = newNode;
        return;

    } else {  // Get list length
        struct Node *index = HEAD;
        while (index != NULL) {
            index = index->next;
            length++;
        }

    }

    struct Node *temp = newNode;
    struct Node *current = HEAD;
    if (_pos == 1) {
        // If insert at head,
        HEAD->prev = temp;    // build link that 'origin' first node point to new node.
        temp->next = HEAD;    // case it's doubly list, build link that new node point to 'origin' first node.

        HEAD = temp;    // case inserting at head, move head pointer.

        return;
    } else if (_pos == (length + 1)) {

        while (current->next != NULL) current = current->next;  // move current to _pos node
//        build link
        current->next = temp;
        temp->prev = current;
        return;

    } else if (_pos > 1 && _pos < length + 1) {
        int i;
        for (i = 0; i < _pos - 2; i++) current = current->next;     // move current to '_pos-1' node

        // build first link to '_pos node'
        temp->next = current->next;
        current->next->prev = temp;

        // build second link to '_pos - 1' node.
        current->next = temp;
        temp->prev = current;
        return;

    } else {

        printf("ERROR\n");
        return;

    }


}

void reverse() {

    if (HEAD == NULL) return;

    struct Node *current = HEAD;
    struct Node *next_, *prev_;
    while (current != NULL) {

        if (current->next == NULL) HEAD = current;    //Move the head pointer to end node when it arrives at those.

        next_ = current->prev;  // Exchange the doubly node's 'prev' and 'next'. For better look
        prev_ = current->next;

        current->next = next_;  // Exchange '*prev' and 'next*'
        current->prev = prev_;

        current = current->prev;

    }

}

void print() {

    struct Node *temp = HEAD;

    printf("List: ");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void printReverse() {

    struct Node *temp = HEAD;

    if (temp == NULL) return;
    while (temp->next != NULL) temp = temp->next;

    printf("Reverse: ");
    while (temp != NULL) {

        printf(" %d ", temp->data);
        temp = temp->prev;

    }
    printf("\n");
    return;

}


int main() {


    HEAD = NULL;
    int n, i, data, pos;
    printf("How mang nodes you want create\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {

        printf("Input data and position\n");
        scanf("%d %d", &data, &pos);
        insert(data, pos);
        printf("List: ");
        print();

    }

    printf("\nReverse print: \n");
    printReverse();
    printf("Truely reverse :\n");
    reverse();
    print();

    return 0;
}