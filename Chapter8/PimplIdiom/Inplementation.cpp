//
// Created by jlibyvali on 24-3-25.
//

#include "SpreadsheetInterface.h"
#include "iostream"
#include <utility>
using namespace  std;

//# Impl method definition: Original private:
// for move ctor and operator
void Spreadsheet::Impl::moveFrom(Impl &src) noexcept {
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
    m_width = std::exchange(src.m_width, 0);
    m_height = std::exchange(src.m_height, 0);
    m_cells = std::exchange(src.m_cells, nullptr);

}

void Spreadsheet::Impl::verifyCoordinate(size_t x, size_t y) const { // check if in the range
    if (x >= m_width || y >= m_height) {
        string tmp = "x or y out of range!!";
        throw out_of_range(tmp);
    }
}

void Spreadsheet::Impl::swap(Impl &othrer) noexcept {   // swap used in operator=(), avoid exception
    std::swap(m_width, othrer.m_width);
    std::swap(m_height, othrer.m_height);
    std::swap(m_cells, othrer.m_cells);
}



//#############################Implementation#######################################




// ####Ctor's set, first let Spreadsheet's m_impl point to Impl class
Spreadsheet::Spreadsheet() {
    m_impl = make_unique<Impl>();
}

Spreadsheet::~Spreadsheet() = default;    // it will auto find ~Impl()

Spreadsheet::Spreadsheet(size_t width, size_t height) {
    m_impl = make_unique<Impl>(width, height);  // point to Impl(size_t width, size_t height)
}

Spreadsheet::Spreadsheet(const Spreadsheet &src) {
    m_impl = make_unique<Impl>(*src.m_impl);
}

Spreadsheet::Spreadsheet(Spreadsheet &&rhs) noexcept: m_impl(std::move(rhs.m_impl)) {}

//# Impl method definition
Spreadsheet::Impl::~Impl() {    // Impl's dtor
    for (size_t i = 0; i < m_width; i++) {
        delete[] m_cells[i];    // It will call cell dtor
    }

    delete[] m_cells;
    m_cells = nullptr;
    m_width = m_height = 0;
}

Spreadsheet::Impl::Impl(size_t width, size_t height) : m_width(width), m_height(height) {
    cout << "Normal ctor" << endl;
    m_cells = new SpreadsheetCell *[m_width];
    for (size_t i = 0; i < width; i++) {
        m_cells[i] = new SpreadsheetCell[m_height]; //It will call cell ctor
    }
}

Spreadsheet::Impl::Impl(const Impl &src) : Impl(src.m_width, src.m_height) {
    cout << "Copy ctor" << endl;
    for (size_t i = 0; i < m_width; i++) {
        for (size_t j = 0; j < m_height; j++) {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

Spreadsheet::Impl::Impl(Impl &&rhs) noexcept {
    cout << "Move ctor" << endl;
    moveFrom(rhs);

    // it's ok above, but if add new data member, had to modify "moveFrom" and "swap()"
    /* So
     * std::swap(*this,rhs);
     * */
}


//################Spreadsheet operator implementation
Spreadsheet &Spreadsheet::operator=(const Spreadsheet &src) {
    *m_impl = *src.m_impl;
    return *this;
}

Spreadsheet &Spreadsheet::operator=(Spreadsheet &&rhs) noexcept {

    if (this != &rhs) {
        m_impl = std::move(rhs.m_impl);
    }
    return *this;
}

//# Impl operators
Spreadsheet::Impl &Spreadsheet::Impl::operator=(const Spreadsheet::Impl &src) {

    cout << "Copy assignment operator" << endl;
    // check self-assigment
    if (this == &src) {
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

    Impl tmp{src};
    swap(tmp);
    return *this;

}

Spreadsheet::Impl &Spreadsheet::Impl::operator=(Spreadsheet::Impl &&rhs) noexcept {

    cout << "Move assignment operator" << endl;
    // Check self-assignment
    if (this == &rhs) {
        return *this;
    }

    moveFrom(rhs);
    return *this;
    /* same , use std::swap（）
     * std::swap(*this,rhs);
     * return *rhs;
     * */

};





// another
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell &cell) {
    m_impl->setCellAt(x, y, cell);
}

SpreadsheetCell &Spreadsheet::getCellAt(size_t x, size_t y) {
    return m_impl->getCellAt(x, y);
}

//# Impl define

void Spreadsheet::Impl::setCellAt(size_t x, size_t y, const SpreadsheetCell &cell) {
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadsheetCell &Spreadsheet::Impl::getCellAt(size_t x, size_t y) {
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

