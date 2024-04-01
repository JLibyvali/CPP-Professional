//
// Created by jlibyvali on 24-4-1.
//

#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


// for projection
class Person {
public:
    Person(string name) : m_name(name) {
    }

    const string &getName() const {
        return m_name;
    }
    // Case there didn't declare the operator<, so can't use sort.
private:
    string m_name;

};

int main() {
    /*In CPP 20, import the ranges.
     * for iterator in the past, some function always need one couple of 'iterators' to show the ranges;
     * but the <ranges> made one level abstraction upper the iterators.
     * */

    cout << "###########Ranges algorithm#####################" << endl;
    vector<int> vec{1, 2, 3, 54, 768, 98232, 35, 2466, 732};
    // sort(vec.begin(),vec.end());    // use the 'no-ranges' version
    ranges::sort(vec);   // use ranges version
    for (const auto &ele: vec) {
        cout << ele << " ";
    }
    cout << endl;

    cout << "###############Projection#######################" << endl;
    // projection: provided one way to use callback.

    vector<Person> vec2{Person{"Jammy"}, Person{"Jacky"}, Person{"Brenete"}, Person{"Jlibyavali"}, Person{"Penny"},
                        Person{"Hooker"}};

    ranges::sort(vec2, {},
                 [](const Person &ele) {
                     return ele.getName();
                 }
                );  // the lambda is the callback, finished any class sort

    for(const auto& ele : vec2){
       cout<<ele.getName()<<" ";
    }
    cout<<endl;

    cout<<"#######################Views###########################"<<endl;
    // many views can consist pie.

    vector<int> vec3 {1,2,3,4,5,6,7,9,13,52,13,31,72};
    cout<<"Origin vectors: "<<endl;
    for(const auto& ele : vec3){
        cout<<ele<<" ";
    }
    cout<<endl;

    auto ans1 { vec3
    | views::filter([](const auto& ele){
        return (ele % 2==0);
    }) };   // filter all odd value:
    cout<<"Ans1: "<<endl;
    for(const auto& ele : ans1){
        cout<<ele<<" ";
    }
    cout<<endl;

    cout<<"Consist the pipe: "<<endl;

    auto ans2 {ans1
    | views::take(3)    // only take 3 elements in front
    | views::reverse    // reverse the order
     };

    // use the views to filter and change values, only the views are writable.

    for(auto& ele : ans2){ele *= 100;}
    for(const auto& ele : vec3){
        cout<<ele<<" ";
    }
    cout<<endl;

    cout<<"#######################Ranges Factory#########################"<<endl;

    // crete one new view fast

    auto value {views::iota(98)
    | views::filter([](const auto& ele){
        return (ele % 2 !=0 );
    })
    | views::transform([](const auto& ele ){
        return ele * 2.0;
    })
    | views::take(10)};

    cout<<"Use the view factory result:"<<endl;
    for(const auto& ele : value){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}