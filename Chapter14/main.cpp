#include <iostream>
#include <stdexcept>


using namespace  std;

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
    }




    return  0;

}
