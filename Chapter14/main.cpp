#include <iostream>
#include <stdexcept>
#include <source_location>  // print source code position


using namespace  std;

// nested exception
class Myexception: public exception{
public:
   Myexception(string mess) : m_message(std::move(mess)){

   }
   virtual  const char* what() const noexcept override {
       return  m_message.c_str();
   }

private:
    string m_message;
};

void sth(const  source_location locat = std::source_location::current()){   // 'current()' means the position at 'sth' called
    try {

        throw runtime_error ("Throwing a runtime_error exception");

    }catch (const runtime_error& e) {

        cout<<__func__ <<" |called in "<<locat.function_name()<<" Caught runtime error and throw MyException again. In: "<<locat.file_name()<<" : "<<locat.line()<<endl;

        throw_with_nested(  // throw nested expetion, this function means there exist nested exception.
            Myexception {"MyException was called and throwing!"}
        );

    }
}

int main() {

    cout<<"###################EXCEPTION USAGE###########################"<<endl;

    int x ,y;
    cin >> x >> y;
    try {
        if(y ==0 ){
            throw invalid_argument { "Divide by zero"};
        }
        cout<<"Value: "<<(x/y)<<endl;
    } catch (const invalid_argument& e ){   // recommend use 'const&', so that avoid the slicing.
        cout<<"Caught exception: "<<e.what()<<endl;
        throw;  // can use 'throw' , throw current exception agian.
    }

    cout<<"#####################NESTED EXCEPTION#########################3"<<endl;
    try {

        sth();

    } catch (const  Myexception &e) {

       cout<<__func__ <<" caught MyException: "<<e.what()<<endl;    // 'what' method print exception information

       const auto* nested { dynamic_cast<const nested_exception*>(&e)}; // Use: dynamic_cast<const nested_exception*> to visit the second exception
       // if no nested exception, 'nested == nullptr'. if had it, go on;
       if(nested){
           try {
               nested -> rethrow_nested();  // if had nested exception, use rethrow_nested to catch exception again.

           }catch (const runtime_error& e){
               cout<<"Nested Exception: "<<e.what()<<endl;
           }
       }
    }


    return  0;

}
