//
// Created by jlibyvali on 24-3-24.
//

#include "cell.h"
#include <stdexcept>
#include <utility>

using namespace std;

class table {

public:
    table(){}
   /* table(size_t width=10 , size_t height = 10,string name = "HelloWorld"){   // default arguments ctor
        m_width = width;
        m_height = height;
        m_name = name;
        only can match arguments from the far right.

    }*/
    table(size_t width, size_t height) : m_width(width), m_height(height) {

        cout<<"Normal ctor"<<endl;
        m_cells = new cell *[m_width];
        for (size_t i = 0; i < width; i++) {
            m_cells[i] = new cell[m_height]; //It will call cell ctor
        }

    }
    ~table(){

        for(size_t i=0;i<m_width;i++){
            delete[] m_cells[i];    // It will call cell dtor
        }
        delete[] m_cells;
        m_cells = nullptr;
        m_width = m_height = 0;

    }

    table(const table &rhs) : table(rhs.m_width, rhs.m_height)
    // When use the "copy ctor" ,used "allegation ctor" first that allocate appropriate memory for m_cells
    {
        for (size_t i = 0; i < m_width; i++) {
            for (size_t j = 0; j < m_height; j++) {
                m_cells[i][j] = rhs.m_cells[i][j];
            }
        }
    }

    void setCellAt(size_t x, size_t y, const cell &cell) {

        verifyCoordinate(x, y);
        m_cells[x][y] = cell;

    }

    cell &getCellAt(size_t x, size_t y) {
        verifyCoordinate(x, y);

        return m_cells[x][y];
    }

//  copy assignment Operator
    table &operator=(const table &rhs) {

        cout<<"Copy assignment operator"<<endl;
        // check self-assigment
        if (this == &rhs) {
            return *this;
        }
/*
        // Free old memory
        for(size_t i =0 ;i<m_width;i++){
            delete[] m_cells[i];
        }
        delete[] m_cells;
        m_cells = nullptr;

       // Allocate new memory

       m_width = rhs.m_width;
       m_height = rhs.m_height;

       m_cells = new cell* [m_width];
       for(size_t i =0;i<m_width;i++){
           m_cells[i] = new cell[m_height];
       }

       // Copy data
       for(size_t i=0;i<m_width;i++){
           for(size_t j=0;j<m_height;j++){
               m_cells[i][j] = rhs.m_cells[m_width][m_height];
           }
    }       Maybe it works but so simple and may throw exception
*/

        table tmp {rhs };
        swap(tmp);
        return *this;
    }

// Move
/* means move one memory block ownership
 *
 * */

    table(table&& src) noexcept{
        cout<<"Move ctor"<<endl;
        moveFrom(src) ;

        // it's ok above, but if add new data member, had to modify "moveFrom" and "swap()"
        /* So
         * std::swap(*this,rhs);
         * */
    }
// Move assignment operator
    table& operator=(table&& rhs) noexcept {

        cout<<"Move assignment operator"<<endl;
        // Check self-assignment
        if( this == &rhs){
            return *this;
        }
        moveFrom(rhs);
        return *this;

        /* same , use std::swap（）
         * std::swap(*this,rhs);
         * return *rhs;
         * */

    }

private:
    void verifyCoordinate(size_t x, size_t y) { // check if in the range
        if (x >= m_width || y >= m_height) {
            string tmp = "x or y out of range!!";
            throw out_of_range(tmp);
        }
    }

    void swap(table &othrer) noexcept {   // swap used in operator=(), avoid exception

        std::swap(m_width, othrer.m_width);
        std::swap(m_height, othrer.m_height);
        std::swap(m_cells, othrer.m_cells);

    }
// for move ctor
    void moveFrom(table& src) noexcept {
/*
        // shallow copy from data
        m_width = src.m_width;
        m_height = src.m_height;
        m_cells = src.m_cells;

        // reset source object,case ownership has been moved
        */
/* To avoid data members destroyed by 'src object' dtor , reset 0 for src members.
         *
         * *//*

        src.m_width = 0;
        src.m_height = 0;
        src.m_cells = nullptr;
*/
// use std::exchange()
// can use '=' assignment is that they are basic type, if there exist an object like "string", should use std::move;
        m_name = std::move(src.m_name);
        m_width = std::exchange(src.m_width,0);
        m_height= std::exchange(src.m_height,0);
        m_cells = std::exchange(src.m_cells, nullptr);

    }

    size_t m_width{0};
    size_t m_height{0};
    string m_name { };
    cell **m_cells{nullptr};
};
// global operator: can be used to exchange object's order.
cell operator+(const cell& lhs, const cell& rhs){

    return cell {lhs.getValue() + rhs.getValue() };
}
cell operator-(const cell& lhs, const cell& rhs){

    return cell {lhs.getValue() - rhs.getValue() };
}
cell operator*(const cell& lhs, const cell& rhs){

    return cell {lhs.getValue() * rhs.getValue() };
}
cell operator/(const cell& lhs, const cell& rhs){

    if(rhs.getValue() == 0){
        throw invalid_argument {"Divide by zero!! "};
    }else {
    return cell {lhs.getValue() / rhs.getValue() };
    }
}

