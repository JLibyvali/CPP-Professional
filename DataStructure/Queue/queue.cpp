//
// Created by jlibyvali on 24-3-1.
//

#include <iostream>
#include <array>

/* Implements of queue use array
 *
 *
 * */
const size_t QUEUESIZE=10;
class Queue{

private:
    int front;
    int rear;
    std::array<int,QUEUESIZE> queue;
public:
    Queue(){    // Queue Intial
        front=-1;
        rear=-1;
        for (int i = 0; i < QUEUESIZE; ++i) {
            queue[i] = 0;
        }

    }
    bool isEmpty(){
        if (front ==-1 && rear ==-1){ return true;}else{ return false;}
    }
    bool isFull(){
        if(rear == QUEUESIZE-1){ return true;} else{ return false;}
    }
    void enQueue(int _data){

        if(isFull()) {
            std::cout << "Queue overflow" << std::endl;
        }else if (isEmpty()){
            rear = front =0;
            queue[front]=_data;
        }else{

            rear++;
            queue[rear] = _data;

        }
    }
    int deQueue(){

        int x;
        if(isEmpty()){
            std::cout<<"Queue underflow"<<std::endl;
            return  0;
        }else if (front== rear){   // If it's the first item

            x = queue[front];
            front = rear =-1;
            queue[front] = 0;   // delete it
            return  x;

        } else{

            x = queue[front];
            queue[front] = 0;
            front ++;   // The queue's first item pop out, and the 'front' move up
            return  x;
        }

    }

    int count(){
        return (rear - front -1);
    }
    void display(){

        std::cout<<"Queue List";
        for (const auto& ele:queue) {

            std::cout<<ele;
        }
        std::cout<<std::endl;

    }
};


int main(){

    auto q1 = Queue();
    int option;
    do {
        std::cout<<"Intput Options\n";
        std::cout<<"1. Enqueue\n";
        std::cout<<"2. Dequeue\n";
        std::cout<<"3. Display\n";
        std::cout<<"4. Count\n";
        std::cout<<"5. Is Empty\n";
        std::cout<<"6. Is Full\n";
        std::cout<<"7. Clear Screen\n";

        std::cin>>option;

        switch (option) {
            case 1:
                int data;
                std::cout<<"Enter the data to push: ";
                std::cin>>data;
                q1.enQueue(data);
                break;
            case 2:
                std::cout<<"Poped value: "<<q1.deQueue()<<std::endl;
                break;
            case 3:
                q1.display();
                break;
            case 4:
                std::cout<<"Queue count: "<<q1.count()<<std::endl;
                break;
            case 5:
                if (q1.isEmpty()){
                    std::cout<<"Queue is Empty"<<std::endl;
                }else{
                    std::cout<<"Queue is not Empty"<<std::endl;
                }
                break;
            case 6:
                if (q1.isFull()){
                    std::cout<<"Queue is Full"<<std::endl;
                }else{
                    std::cout<<"Queue is not Full"<<std::endl;
                }
                break;
            case 7:
                system("clear");
                break;
            default:
                std::cout<<"Invalid option"<<std::endl;
                break;
        }
    } while (option!=0);

    return  0;

}