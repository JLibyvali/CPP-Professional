//
// Created by jlibyvali on 24-3-29.
//

#ifndef CHAPTER10_DERIVED_H
#define CHAPTER10_DERIVED_H

#include "Basic.h"


class Derived: public Basic{
public:

    void method1() override {   // 'override' is optional, better use it , to avoid declared another 'virtual' method again.
        cout<<"this is derived class  method"<<endl;
    }
    void noVirtualMethod() // if not use 'virtual'
    {
        cout<<" in DERIVED class with NO OVERRIDE"<<endl;
    }

    void methodAnthor(){
        cout<<"This method didn't declared in Basic classs"<<endl;
    }

};




#endif //CHAPTER10_DERIVED_H
