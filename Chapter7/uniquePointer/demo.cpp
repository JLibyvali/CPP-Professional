//
// Created by jlibyvali on 24-3-24.
//

#include <iostream>
#include <memory>

using namespace std;


// unique_str , shared_str

class Foo {
public:
    Foo() = default;

    Foo(int m_x){
        x = m_x;
    }
    Foo(unique_ptr<int> m_data) : data{move(m_data)} {  // use "move" to change the unique_ptr's proprietary.

    }
    Foo(unique_ptr<int> m_data, unique_ptr<float> m_num) {
        data = move(m_data);
        num = move(m_num);   // it had used move();

    }

    unique_ptr<int> data;
    unique_ptr<float> num;
    int x;
};


// use custom "deleter[]"
int *my(int value) {
    return new int{value};
}

void freemy(int *m) {
    delete m;
}

// weak_ptr
void useResource(weak_ptr<Foo>& m_weakP){

    auto reso {m_weakP.lock()};

    if(reso){
        cout<<" Resource still alive"<<endl;
    }else {
        cout<<"Resource has been freed"<<endl;
    }


}

int main() {

// unique_str and share_str
// usually use make_unique< TYPE>() to create one unique_prt
// default make_unique<>() will use value initialize
// Once defined, usages like normal pointer
    auto f1 = new Foo(make_unique<int>(8), make_unique<float>(9.224));
    cout << "Value: [" << *f1->data << " " << f1->data << " ]" << " AND [" << *f1->num << " " << f1->num << " ]"
         << " AND obj address: " << &f1 << endl;

    cout << "############################Deleter####################################" << endl;

/* unique_prt support use custom deleter like below:
 *
 * This feature can be useful that "unique_ptr" also can manager other type resources like file, sockets, etc.
 * */
    unique_ptr<int, decltype(&freemy)> MySmart{my(42), freemy};
    shared_ptr<int> mySmart2{my(51), freemy};

    cout << "MySmart: " << MySmart << " and value: " << *MySmart << endl;
    cout << "MySmart2: " << mySmart2 << " and value: " << *mySmart2 << endl;
// shared_ptr<>() alias
// it can let "foo" and "aliasing" share one common pointer?
    auto foo {make_shared<Foo>(42)};
    auto aliasing { shared_ptr<int> { foo, &foo->x}};

    cout<<"##################### weak_ptr#######################"<<endl;

// weak_ptr is related with shared_ptr, it's for judging the resource shared_ptr managed freed or not.
// weak_ptr will not have the proprietary of resource and when weak_ptr freed it doesn't  destroy the resource
/*
 * For get the weak_ptr value:
 * 1. use the weak_ptr object's method: lock()
 * 2. create shared_ptr object and use the "weak_ptr" as ctor's parameter.
 * */
    auto sharedFoo {make_shared<Foo>(10)};
    auto weakFoo {weak_ptr<Foo> {sharedFoo}};

    useResource(weakFoo);   // use the weak_ptr
    sharedFoo.reset();  // reset will free one shared_ptr, if it's the last one, reset() free the resource too. BUT weak_ptr is still alive.
    useResource(weakFoo);

    return 0;
}