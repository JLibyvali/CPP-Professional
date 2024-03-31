#include <iostream>
#include "Grid.h"
#include "GameBoard.h"
#include "ChessPiece.h"

using namespace  std;

// Function template

static  const size_t NOT_FOUND  = static_cast<size_t>(99);
template<typename T>
size_t Find(const T& value, const T* arr,size_t size){

    for(size_t i =0; i<size ; i++){
        if(arr[i] == value){
            return  i;
        }
    }

    return  NOT_FOUND;
}
int main() {

    cout<<"###############USE INHERIT NOT TEMPLATE############################"<<endl;
    GameBoard chessboard {5, 7};
    auto pawn {std::make_unique<ChessPiece>()};

    chessboard.at(0,0) = std::move(pawn);   // ChessPiece derived from GamePieces,so it's could set unique_ptr<ChessPiece> to unique_ptr<GamePiece>&
    chessboard.at(0,1 ) = make_unique<ChessPiece>();
    chessboard.at(0,2) = nullptr;
    cout<<chessboard.at(0,0)<<" | "<<chessboard.at(0,1)<<" | "<<chessboard.at(0,2)<<endl;

    /*It gets a little trouble without template ,
     * The GameBoard class always storage pointer and "at" only retunr unique_ptr<GamePiece>&
     * */

    cout<<"####################USE TEMPLATE###########################"<<endl;

    Grid<int> intGird;
    Grid<double> doubleGrid {12,21};

    intGird.at(0,0) = 10;
    int x { intGird.at(0,0).value_or(0)};

    Grid<int> intGrid2 { intGird }; // copy ctor
    Grid<int> intGrid3 ;
    intGrid3 = intGrid2;    // copy assignment



    cout<<"#######################FUNCTION TEMPLATE##########################"<<endl;

    int arr1[] = { 1,3,56,78,78};
    size_t len = std::size(arr1);

    double  arr2[] = { 1.43,24.5,12.566,224.6};
    size_t len2 = std::size(arr2);

    // Template will auto infer type.
    size_t ans = Find(3,arr1,len);
    size_t ans2 = Find<double>(3.234,arr2,len2);

    cout<<"Find: "<<ans<<" | "<<ans2<<endl;

}
