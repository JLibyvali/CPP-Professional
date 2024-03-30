//
// Created by jlibyvali on 24-3-29.
//

#ifndef CHAPTER12_GAMEPIECE_H
#define CHAPTER12_GAMEPIECE_H

#include <memory>

class GamePiece {

public:
    virtual ~GamePiece() = default;
    virtual std::unique_ptr<GamePiece> clone() const = 0;
};


#endif //CHAPTER12_GAMEPIECE_H
