//
// Created by jlibyvali on 24-3-25.
//

#include "Spreadsheet.h"
#include "SpreadsheetInterface.h"
#include <iostream>
#include <vector>

using namespace  std;

// Test move action
Spreadsheet creatObj(){
    return Spreadsheet {3,2};
}

int main() {

// Test move action
    vector<Spreadsheet> vec;

    for(size_t i =0;i<2;i++){
        cout<<"Interation"<<i<<endl;
        vec.push_back(Spreadsheet(100,100)) ;  // it continuously called copy ctor in loop, so can develop performance by using 'swap()', swap() will not operating in memory.
        /* Progress
         * 1. 'table()'  call normal ctor to create object, but 'vector' need to change itself size to bigger enough,so follow closely call 'table move ctor'
         *  to put  the object in 'vector'
         * 2. and go on, 'table()' create another object,so 'vector' need change size again and call 'table move ctor' twice.
         * */
    }
    cout<<"####out of for###"<<endl;

    Spreadsheet s1 {2,3};   // call table normal ctor.
    s1 = creatObj();    // call table ctor, IMPORTANT: '=' will call "table move ctor not copy ctor" case func "creatOb()"  will destroy temporary object after returning it.

    Spreadsheet s2 {5,6};
    s2 = s1;    // call copy 'table copy ctor' case s1 was not temporary object

    return 0;
}
