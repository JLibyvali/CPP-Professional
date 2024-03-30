//
// Created by jlibyvali on 24-3-30.
//

#ifndef CHAPTER12_CHESSPIECE_H
#define CHAPTER12_CHESSPIECE_H
#include "GamePiece.h"

class ChessPiece: public GamePiece{
public:
    std::unique_ptr<GamePiece> clone() const override{

        // call the copy ctor.
        return  std::make_unique<ChessPiece>(*this);
    }
};

#endif //CHAPTER12_CHESSPIECE_H
