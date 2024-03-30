//
// Created by jlibyvali on 24-3-29.
//

#ifndef CHAPTER10_BASIC_H
#define CHAPTER10_BASIC_H

#include <iostream>


using namespace std;

class Basic{

public:
    virtual void method1();  // There declared 'virtual' and go on, in all derived class the method keep 'virtual' since the 'override'
    void noVirtualMethod(); // if not use 'virtual'
    void func1();


// Base class ctors

    /* class  object initial order.
     * 1. find the base class default ctor, unless declare specific ctor in class  initializer.
     * 2. create data members without  'static', in declared order.
     * 3. run this class ctor
     *
     * */

// base class dtors
    /*1. run this class dtor
     * 2. destroying data members in opposited order.
     *3.  call base class dtor
     * */



private:
    int m_basic {0};

};

void Basic::method1() {
    cout<<"This is basic class method"<<endl;
}


void Basic::noVirtualMethod() {

    cout<<" The method with NO VIRTUAL"<<endl;

}




#endif //CHAPTER10_BASIC_H
