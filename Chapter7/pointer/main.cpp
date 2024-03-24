//
// Created by jlibyvali on 24-3-17.
//

#include <iostream>
#include <string>

using namespace std;


// malloc and  new
//struct Marr{
//    int num;
//    string str;
//    Marr() : num(10),str("wdadw"){}
//
//};


// ######Mulity dimension array and allocate memory###########
//char **allocateMemoryInHeap(int _xD, int _yD) {
//
//    char **marr{new char *[_xD]};  // Allocate first dimension : Pointer to one 'char* []'
//
//    for (int i = 0; i < _xD; i++) {
//        marr[i] = new char[_yD];    // Allocate second dimension : char[]
//    }
//
//    for (int i = 0; i < _xD; i++) { // set value
//        for (int j = 0; j < _yD; j++) {
//            marr[i][j] = 'a' + j;
//        }
//    }
//
//    return marr;    // this allocation will cause memory fragment in heap,case 'new' two times
//
//}
//
//void
//releaseMemory(char **&_arr, int _xDimension) { // when the parameter were array, it always would give the size also.
//
//    for (size_t i = 0; i < _xDimension; i++) { // free second dimension memory
//        delete[]   _arr[i];
//        _arr[i] = nullptr;
//    }
//
//    delete[]    _arr;   // free first dimension memory
//    _arr = nullptr;
//
//}
//
//
//// 2. allocate in continuous memory block
//
//int index(int _xDimen, int _yDimen, int rowSize) { // 'rowSize'  means the first dimension size.
//    return (_yDimen * rowSize + _xDimen);   // return index in first dimension
//}
//
//int *allocateInMemoryBlock(int x, int y) {
//
//    int *marr{new int[x * y]};      //Only new once , using 1 dimension array to simulate multiply array by index
//
//    for (int i = 0; i < y; i++) {
//        for (int j = 0; j < x; j++) {
//            marr[index(i, j, x)] = (i + 1);
//        }
//    }
//
//    return marr;
//void releaseMemory(int *_arr, size_t n) {
//
//    delete [] _arr;
//    _arr = nullptr;
//}
//}


// Memory leak show

class simple {
public:
    simple() {m_data = new int();}
    ~simple() {delete m_data;}
    void setvalue(int value) {*m_data = value;}

private:
    int* m_data;
};

void eitherSimple(simple* & _sth){
  _sth = new simple();  // will cause memory leak, case parameter was reference, the original memory had ben lost.
}


int main() {

/*
// First, "stack" or "heap" , "malloc" and "new"

    int arr1[]{1, 2, 3, 4, 5};      // Allocate memory in continuous sequence
    int*  arr2 {new int[]{7,8,9,10,11}};


    for(int i=0; i <5;i++){
        cout<<"[arr1-Value: "<<arr1[i]<<"| "<<&arr1[i]<<"--]"<<endl;
        cout<<"[arr2-Value: "<<arr2[i]<<"| "<<&arr2[i]<<"--]"<<endl;
    }
    Marr *marr1 {new Marr()};
    Marr *marr2 {(Marr*) malloc(sizeof(Marr))};


    cout<<"#######################33"<<endl;
    cout<<"marr1:[ "<<marr1->str<<" ]"<<" |"<<&marr1<<endl;
    cout<<"marr2:[ "<<marr2->str<<" ]"<<" |"<<&marr2<<endl; // don't call the ctor
    cout<<"##################################3"<<endl;

//First, free memory
    delete[] arr2;
    delete marr1,marr2;
    arr2 = nullptr;
*/

//#################Multity dimension array
//
//    int arr[3][2]{{1, 2},
//                  {3, 4},
//                  {5, 6}}; // In stack
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 2; j++) {
//            cout << "Value: " << arr[i][j] << " |[" << &arr[i][j] << "]|" << endl;
//        }
//    }
//
//    cout << "###########Two-dimension array In Memory fragment" << endl;
//    auto marr = allocateMemoryInHeap(5, 5);
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << "Char: " << marr[i][j] << " |[" <<static_cast<void*>(&marr[i][j]) << "]|" << endl;
//            /*Why use "static_cast<void*>?
//             * Case " &marr[i][j] "  is " char* " type, when the print-value is "char* type" ,cout will try to interrupt it into string.
//             * */
//        }
//    }
//    releaseMemory(marr,5);
//    cout << "####################Two-dimension  array in Memory Block" << endl;
//
//    auto marr2 = allocateInMemoryBlock(3, 6);
//    // output
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 6; j++) {
//            cout << "Value: " << marr2[index(i, j, 3)] << " |[" << &marr2[index(i, j, 3)] << "]|" << endl;
//        }
//    }
//    releaseMemory(marr2,sizeof(marr2));


// ######### Memory leak

    simple* sthPtr { new simple{ } };
    eitherSimple(sthPtr);

    delete  sthPtr; // only delete  the new object that initialized in eitherSimple(),

    return 0;
}