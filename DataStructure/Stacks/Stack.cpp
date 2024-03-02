//
// Created by jlibyvali on 24-2-29.
//

/*
 * Stacks has lots of use
 *
 * such as function calling/recursion
 *         Redo/Undo operations
 *         balanced parentheses
 *         Infix to Postfix/Prefix conversion
 *
 * */

#include <iostream>
#include <array>


// Implement use array
const size_t STACKSIZE=10;
class Stack{

private:
    int top;
    std::array<int,STACKSIZE>  stack;
public:
    Stack(){    // Stack Intial
     top=-1;    // When the stack is null, the 'top' is under the first frame.
        for (int i = 0; i < STACKSIZE; ++i) {
            stack[i] = 0;
        }

    }


    bool isEmpty(){

        if (top==-1){ return 1;}else{ return 0;}

    }
    bool isFull(){
        if (top==(STACKSIZE-1)){ return 1;}else{ return 0;}
    }

    void push(int data){

        if (isFull()){ std::cout<<"stack overflow"<<std::endl;}else{

            top++;
            stack[top] = data;

        }

    }
    int pop(){

        if (isEmpty()){ std::cout<<" stack underflow "<<std::endl; }else{
            int popValue = stack[top];
            stack[top]=0;
            top--;  // When pop one item, top move down;
            return popValue;
        }

    }
    int count(){
        return (top+1);
    }
    int peek(int _pos){

        if (isEmpty()){ std::cout<<"Stack is Empty"<<std::endl; }else{

            if (_pos>-1 | _pos <STACKSIZE){
                return stack[_pos];
            }else{
                std::cout<<"Position overflow"<<std::endl;
            }
        }
    }
    void change(int _data,int _pos){
        if (stack[_pos]!=0){
            stack[_pos]=_data;
        }else{
            std::cout<<"Invalid position"<<std::endl;
        }
    }
    void display(){

        std::cout<<"Stack List: ";
        for (const auto& ele:stack) {
            std::cout<<" "<<ele<<" ";
        }
       std::cout<<std::endl;

    }

};


int main(){

   auto s1 = Stack();
   int options;
   do{
       std::cout<<" What option you need,0 will exit\n";
       std::cout<<"1. push";
       std::cout<<"\n2. pop";
       std::cout<<"\n3. isEmpty";
       std::cout<<"\n4. isFUll";
       std::cout<<"\n5. count";
       std::cout<<"\n6. peek";
       std::cout<<"\n7. dispaly";
       std::cout<<"\n8. change";
       std::cout<<"\n9. clear system"<<std::endl;

       std::cin>>options;

       switch (options) {
           case 1:
                  int data;
                std::cout<<"Enter the data to push: ";
                std::cin>>data;
                s1.push(data);
                break;
           case 2:
                std::cout<<"Poped value: "<<s1.pop()<<std::endl;
                break;
           case 3:
                if (s1.isEmpty()){
                    std::cout<<"Stack is Empty"<<std::endl;
                }else{
                    std::cout<<"Stack is not Empty"<<std::endl;
                }
                break;
           case 4:
                if (s1.isFull()){
                    std::cout<<"Stack is Full"<<std::endl;
                }else{
                    std::cout<<"Stack is not Full"<<std::endl;
                }
                break;
           case 5:
                std::cout<<"Stack count: "<<s1.count()<<std::endl;
                break;
           case 6:
                int pos;
                std::cout<<"Enter the position: ";
                std::cin>>pos;
                std::cout<<"Peek value: "<<s1.peek(pos)<<std::endl;
                break;
           case 7:
                s1.display();
                break;
           case 8:
                int _data,_pos;
                std::cout<<"Enter the data and position: ";
                std::cin>>_data>>_pos;
                s1.change(_data,_pos);
                break;
            case 9:
                system("clear");
                break;
           default:
                std::cout<<"Invalid option"<<std::endl;
                break;

       }
   } while (options!=0);

    return 0;
}