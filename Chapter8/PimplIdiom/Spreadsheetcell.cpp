//
// Created by jlibyvali on 24-3-25.
//

#include "Spreadsheetcell.h"
#include <iostream>
#include <charconv>


using namespace std;

// ctor
SpreadsheetCell::SpreadsheetCell() {}
SpreadsheetCell::SpreadsheetCell(double m_v) : value( m_v) {}
SpreadsheetCell::SpreadsheetCell(std::string_view m_str) : value{stringToDouble(m_str) }{}
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &rhs) {
        value = rhs.value;
}
SpreadsheetCell::~SpreadsheetCell() {
    cout<<"Dtor is called!!"<<endl;
}

//Operator
SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &rhs) {
    if(this == &rhs){
        return *this;
    }else{
        value = rhs.value;
        return *this;
    }

}

// "this"  pointer
// every method call will pass one 'this' pointer, and it can use to disambiguation.
void SpreadsheetCell::setValue(double m_value) {
    value = m_value;
}

double SpreadsheetCell::getValue() const {
    return value;
}

void SpreadsheetCell::setString(string_view m_value) {
    value = stringToDouble(m_value);
}

string SpreadsheetCell::getString() const {
    return doubleToString(value);
}

string SpreadsheetCell::doubleToString(double m_value) const {
    return to_string(m_value);
}

double SpreadsheetCell::stringToDouble(string_view m_value) const {
    double num{0};
    from_chars(m_value.data(), m_value.data() + m_value.size(), num);
    return num;
}

