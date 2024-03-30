#include "StringSpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"
#include "derived.h"
#include <vector>
#include <memory>



class DoubleSpreadsheetCell;
class StringSpreadsheetCell;

void classInherit();
void Polymorphism();
int main() {

    cout<<"##################Inherit#######################"<<endl;
    classInherit();


    cout<<"################Polymorphism####################"<<endl;
    Polymorphism();



    return 0;
}

void Polymorphism(){

    std::vector<std::unique_ptr< SpreadsheetCell> > vec;

    vec.push_back(std::make_unique<StringSpreadsheetCell>() );
    vec.push_back(std::make_unique<StringSpreadsheetCell>() );
    vec.push_back(std::make_unique<DoubleSpreadsheetCell>() );

    vec[0]->set("The first element");   // It's using 'SpreadsheetCell' pointer now, so it can call Base class method.
    vec[1]->set("second funck");
    vec[2]->set("23.354445111");

    for(const auto& ele:vec){
        cout<<ele->getString()<<endl;
    }


}

void classInherit(){

    Derived derived1;
    /* the pointer and the reference could point to any class object, case the object know its class,
     * so the pointer or reference can find the right method.
     *
     * BUT, normal object couldn't handle the derived information, it needs type_castr<>.
     * */
    Basic &ref1{derived1};    // But it could only find the 'virtual' method.
    ref1.method1();

    Basic baseAssign{derived1};  // case derived class is also the basic class.
    baseAssign.method1();   // BUT it couldn't call derived class method.
    /*Important:
     *
     * When use the 'Basic" class pointer or reference to call derived class object, which can visit all information in derived class
     *
     * But if not the pointer or reference , which will call 'type_cast<>' and it will lose all information in derived class,ALSO call "slicing"
     * */


    /*IMPORTANT:
     * the 'hide'  method:
     * If in base class not used 'virtual' declaring method, and definite again in derived class.
     * Actually, derived class didn't override that method . but definite a new method.
     * */

    derived1.noVirtualMethod();

    Basic& baseRef { derived1  };   // case without 'virtual' , the reference is Basic.
    baseRef.noVirtualMethod();

    // any class that contained 'virtual' , compiler will generate the 'vtable' , this kind of class' every object will contained one pointer to the 'vtable'

// SHOULD declare all dtor as 'virtual', compiler default dtor is not 'virtual', SO decalred virtual.


// upcasting and downcasting

    // upcasting just use eference
    // downcasting   , it's not a good design
    // downcasting should use dynamic_cast<>(), and it only can for object has vtable.

}