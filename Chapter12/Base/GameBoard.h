//
// Created by jlibyvali on 24-3-30.
//

#ifndef CHAPTER12_GAMEBOARD_H
#define CHAPTER12_GAMEBOARD_H

#include "GamePiece.h"
#include <vector>
#include <exception>
#include <utility>
#include <iostream>


class GameBoard{

public:
    static  const size_t defaultHeight  { 10 };
    static  const size_t defaultWidth { 10 };
    explicit GameBoard(size_t width = defaultWidth, size_t height = defaultHeight );

    virtual ~GameBoard() = default;


    GameBoard(const GameBoard& src);
    GameBoard& operator=(const GameBoard& src);

    GameBoard(GameBoard&& rhs) = default;
    GameBoard& operator=(GameBoard&& rhs) = default;

    /*The question is:
     * at() only return unique_ptr<GamePiece>&, the ref type has been defined,
     * so it can only downcasting to get other derived class  with inherit.
     * So get in the template
     * */
    std::unique_ptr<GamePiece>& at(size_t x , size_t y);
    const std::unique_ptr<GamePiece>& at(size_t x ,size_t y) const ;

    size_t getHeight( ) const { return  m_height;}
    size_t getWidth( ) const { return  m_width;}

    void swap(GameBoard& other ) noexcept;
    void swap(GameBoard& first, GameBoard& second) noexcept;


private:

    void  verify( size_t x , size_t  y) const ;
    std::vector< std::vector< std::unique_ptr<GamePiece> > >  m_cells;
    size_t m_height { 0}, m_width { 0 };

};

GameBoard::GameBoard(size_t width, size_t height) : m_width(width ), m_height (height) {

    std::cout<<"GameBoard's NORMAL CTOR"<<std::endl;
    m_cells.resize(m_width);
    for(auto& ele : m_cells){
        ele.resize(m_height);
    }

}


GameBoard::GameBoard(const GameBoard &src) : GameBoard(src.m_width,src.m_height) {

    std::cout<<"GameBoard's COPY CTOR"<<std::endl;
   for(size_t i=0;i<m_width;i++){
       for(size_t j=0;j<m_height;j++){
           if(src.m_cells[i][j]){
               m_cells[i][j] = src.m_cells[i][j] ->clone(); // " copy and swap " idiom to implement copy ctor.
           }
       }
   }

}

GameBoard&  GameBoard::operator=(const GameBoard& src) {

    // " copy and swap" idiom
    std::cout<<"GameBoard's COPY ASSIGNMENT"<<std::endl;
    GameBoard tmp {  src };
    swap(tmp);
    return  *this;
}


void GameBoard::verify(size_t x, size_t y)  const {

    if(x > m_width || y > m_height){
        throw  std::out_of_range(" x or y must be less than it.");
    }

}


void GameBoard::swap(GameBoard &other) noexcept {
    std::cout<<"GameBoard's SWAP"<<std::endl;
    std::swap(m_width,other.m_width);
    std::swap(m_height,other.m_height);
    std::swap(m_cells,other.m_cells);

}

void GameBoard::swap(GameBoard & first, GameBoard& second ) noexcept {
    first.swap(second);
}


const std::unique_ptr<GamePiece>&  GameBoard::at(size_t x, size_t y) const {
    verify(x,y);
    return  m_cells[x][y];
}

std::unique_ptr<GamePiece>&  GameBoard::at(size_t x, size_t y) {
    return const_cast<std::unique_ptr<GamePiece> & >(std::as_const(*this).at(x,y));
}


#endif //CHAPTER12_GAMEBOARD_H
