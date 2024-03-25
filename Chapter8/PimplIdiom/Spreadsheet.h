#ifndef CLASS_SPREADSHEET_H
#define CLASS_SPREADSHEET_H

#include "Spreadsheetcell.h"
#include <memory>


class Spreadsheet {

public:
//ctors
    Spreadsheet();

    ~Spreadsheet();

    Spreadsheet(size_t width, size_t height);

// copy and move , ctor operator
    Spreadsheet(const Spreadsheet &src);

    Spreadsheet &operator=(const Spreadsheet &src);

    Spreadsheet(Spreadsheet &&rhs) noexcept;

    Spreadsheet &operator=(Spreadsheet &&rhs) noexcept;

// another
    void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);

    SpreadsheetCell &getCellAt(size_t x, size_t y);

// global operator
    friend SpreadsheetCell operator+(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

    friend SpreadsheetCell operator-(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

    friend SpreadsheetCell operator*(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

    friend SpreadsheetCell operator/(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

// simplified operator
    friend SpreadsheetCell operator+=(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

    friend SpreadsheetCell operator-=(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

    friend SpreadsheetCell operator*=(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

    friend SpreadsheetCell operator/=(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

private:
    class Impl;

    std::unique_ptr<Impl> m_impl;

};

// declare global
SpreadsheetCell operator+(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

SpreadsheetCell operator-(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

SpreadsheetCell operator*(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);

SpreadsheetCell operator/(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);


#endif