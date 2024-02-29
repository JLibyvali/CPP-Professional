//
// Created by jlibyvali on 24-2-29.
//

#include <stdio.h>
#include <stdlib.h>


struct Node {

    int data;
    struct Node* next;
    struct Node* prev;

};
struct Node* HEAD;

void insert(int _data,int _pos){

    /* 'malloc' or 'new'
     * 'void malloc()' will return one pointer to the memory block, so after type-conversion.
     * will ask one memory block in 'Heap' , it will be live when the function dead.
     * But just: struct Node* newNode; is creating one local variable.
     * the local variable will be destroying when the function dead.
     * */
    struct Node* newNode = (struct Node* ) malloc(sizeof (struct Node));

    newNode->data = _data;  // Node Init
    newNode->next = NULL;
    newNode->prev = NULL;

    if (HEAD == NULL){
        HEAD = newNode;
        return;

    }

    struct  Node* temp = newNode;
    if (_pos ==1 ){
        // If insert at head,
        HEAD->prev = temp;    // build link that 'origin' first node point to new node.
        temp->next = HEAD;    // case it's doubly list, build link that new node point to 'origin' first node.

        HEAD = temp;    // case inserting at head, move head pointer.

    }else{




    }


}
void print(){

   struct Node* temp = HEAD;
   printf("List: ");
    while (temp!=NULL){
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void printReverse(){

   struct Node* temp = HEAD;

    if (temp==NULL) return;
    while (temp->next != NULL)  temp = temp->next;

    printf("Reverse: ");
    while (temp != NULL){

        printf(" %d ",temp->data);
        temp = temp->prev;

    }
    printf("\n");
    return;

}




int main(){


    HEAD = NULL;
    printf("linked list: ");
    insert(2,1);
    insert(3,1);
    insert(4,1);
    insert(6,1);
    insert(9,1);
    insert(8,1);
    print();

    printf("Reverse print: \n");
    printReverse();



    return 0;
}