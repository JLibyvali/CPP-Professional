#include <iostream>
#include <vector>
#include <iterator>


using namespace  std;

// ostream_iterator
template<typename InputIter,typename OutputIter>
void Mycopy(InputIter begin, InputIter end, OutputIter dst){

    for(auto it { begin } ; it != end;it++,dst++){
        *dst = *it;
    }

}
// istream_iterator
template<typename InputIter>
auto sum(InputIter begin, InputIter end){   // read all data in stream, and return it in a iterator.

    auto  sum { 0 };
    for(auto it { begin }; it != end ; it++){
        sum += *it;
    }
    return  sum;
}

int main() {


    cout<<"########################Stream Iterator########################"<<endl;
    vector vec1 {1,2,3,5,5,5,68,4};
    auto vec2  = vector<int>(vec1.size());
    Mycopy(vec1.begin(),vec1.end(),ostream_iterator<int>{cout, " "});   // use 'Mycopy' to copy one ranged value to one vector
    cout << endl;

    istream_iterator<int> numBegin { cin }; // istream_iterator will make an end-iterator auto.
    istream_iterator<int> numEnd ;
    auto result {sum (numBegin,numEnd)};
    cout<<"Sum: "<<result<<endl;

}
