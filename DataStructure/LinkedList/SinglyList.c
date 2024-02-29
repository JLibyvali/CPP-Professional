//
// Created by jlibyvali on 24-2-28.

/*
 First:
 Initial one LinkedList by Creating one character and insert one 'Node' in head.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *next;
};

// Global variable is easier to use.
// The LinkedList unique character 'Head' should not be changed anytime, if changed, the LinkedList lost.
struct Node *Head; // Create one 'Node' Pointer to represent the LinkedList, Which were This list name uniquely.

void Insert(int data, int pos) {
    // temp1 is temporarily point to new 'Node'
    struct Node *temp1 = (struct Node *) malloc(
            sizeof(struct Node));   //   Ask one memory block in stack in creating new 'Node'.
    temp1->Data = data;
    temp1->next = NULL;

// It inserts element in the beginning.
    if (pos == 1) {
        temp1->Data = data; // Set 'Node' data.
        temp1->next = Head;  /*
     * It contains two situation , the List is empty or not.
     * When the List is empty, the 'Head == NULL', So we write this:
     * temp1->next = NULL;       // The temp1 point to last 'Node'.
     * Head = temp1;             // Pass the 'temp1 pointer' to Head, So 'Head' will point to the last node.
     *
     * When it's noe empty , the 'Head != NULL', we have to make temp1 point to origin node, and 'Head' point to temp1.
     * Then build new List.
     * temp1->next = NULL;
     * if(Head != NULL) temp1->next = Head;
     * head = temp1;
     *
     * */
        Head = temp1;
        return;

    } else {
// Insert in the i-th position.
        /*
         *  If we want insert 'data' in 'pos',
         *  First we should build the link tempN to Pos-th node.
         *  Second break the link 'Pos-th - 1' to 'Pos-th', then build link 'Pos-th - 1' to tempN.
         *
         * */
        struct Node *temp2 = Head; // Create temp2 to traverse all list.
        int i;
        for (i = 0; i < pos - 2; i++) {   // Cause from 'i=0', it needs 'pos-2' times loop.
            temp2 = temp2->next;
        }
        temp1->next = temp2->next; // Make our new 'Temp' point to 'Pos-th' Node.
        temp2->next = temp1;    // Make the 'Pos-th - 1' node  point to the new node.
        return;

    }

}

void Print() {

    struct Node *temp = Head;  // Use local variables not Head, because we had to change the temp.
    printf("List:");

    while (temp != NULL) {     // Traverse the LinkedList , Print every element.
        printf(" %d ", temp->Data);
        temp = temp->next;
    }
    printf("\n");

}


// Use recursion to print linked list in reversing order. Not reverse the linked  list, just print in reverse orderly.
void printReverse(struct  Node* p){

    if(p==NULL) return;     // 'p' will keep going util the end Node, then it will return :
                            // means exit the 'recursion func' and pop it form stack-frame.

    printReverse(p->next);
    /*  Logic: When the program start and call pintReverse(Head) , it will keep calling the function util 'printReversion(NULL)' .
     *
     * Then it had build lots of 'printRecursion' stack-frame in memory block. 'Return' will pop it in orderly.
     * printReverse(Head) -> printReverse('Head+1') -> printReverse('Head+2') -> printReverse('Head+3') -> ````` -> printReverse(NULL);
     *
     * When exit the function example 'printReverse(NULL)' , it will run the 'printf()' below;
     * */
    printf(" %d ",p->Data);

}

void Delete(int pos) {

    struct Node * temp1 = Head; // temp1 used to traverse.
    if (pos == 1) {
        Head = temp1->next; // If delete first node, made Head point to scond node.
        free(temp1);
        return;
    } else {
        int i;
        for (i = 0; i < pos - 2; ++i) {    // temp1 point to 'pos-1 th' node
            temp1 = temp1->next;
        }
        struct Node *temp2 = temp1->next;  // temp2 point to 'pos-th' node
        temp1->next = temp2->next;  // Made 'pos - 1th' node point to 'pos +1th' node.
        free(temp2);    // free 'pos-th' node.
        return;
    }

}


void reverseIterative(){

    /*
     * First , create 3 pointers to record 3 nodes. Traverse the list from HeadNode.
     * Use loop to traverse list and reverse elements.
     *
     * */
    struct  Node *current,*prev,*next;
    current = Head;
    prev = NULL;
// Use Iterative method to reverse LinkedList.
    while (current != NULL){
        next = current->next;   // next storage next node's address, so we can move temp.
        current->next = prev;   // Reverse the LinkedList,
        prev = current;         // move 'pre' pointer.
        current = next;         // move 'current' pointer.

    }
    Head = prev;

}
void reverseRecursion(struct  Node* current){
/* Logic:
 * It keeps calling 'reverseRecursion' util end node, and we made 'Head point the end Node' .
 * Example:
 * Then exit func:reverseRecursion('End-Node') , return to 'end-1' node,
 * creating  'backward' points to 'end node' and build link with 'current' node.
 * And keep set  'current->next = NULL' : It breaks the link between 'current node' with 'backward node'.
 * Eventually, finish reverse.
 *
 * */

    if(current->next == NULL) {
        Head = current; // Reversion first step: change head pointer;
        return;
    }

    reverseRecursion(current->next);
// code after return.
    struct  Node* backward = current->next; // create one point to 'end node'
    backward->next = current;   // build link between 'end node' and 'end-1 node', break the end node link to NULL;
    current->next = NULL;       // break link between 'end-1 node' and 'end node', finish the reverse.

}
int main() {

    Head = NULL;   // At beginning, empty list.
    printf("How many numbers?\n");
    int n, i, data, pos;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        printf("Enter num and the variable position\n");
        scanf("%d %d", &data, &pos);
        Insert(data, pos);
        Print();
    }
    printf("Delete which element?\n");
    scanf("%d",&pos);
    Delete(pos);
    Print();
    printf("Reverse the linked list\n");
    reverseIterative();
    Print();
    printf("Reverse the linked list by recursion\n");
    reverseRecursion(Head);
    Print();

    return 0;
}
