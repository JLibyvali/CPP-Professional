//
// Created by jlibyvali on 24-3-24.
//

#include <charconv>
#include "basic.h"

using namespace std;

// implementation
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

int main() {

// "this"  pointer
// every method call will pass one 'this' pointer, and it can use to disambiguation.





    return 0;
}
