//
// Created by jlibyvali on 24-3-24.
//

#include <charconv>
#include "cell.h"

using namespace std;

// implementation
void cell::setValue(double m_value) {
    value = m_value;
}

double cell::getValue() const {
    return value;
}

void cell::setString(string_view m_value) {
    value = stringToDouble(m_value);
}

string cell::getString() const {
    return doubleToString(value);
}

string cell::doubleToString(double m_value) const {
    return to_string(m_value);
}

double cell::stringToDouble(string_view m_value) const {
    double num{0};
    from_chars(m_value.data(), m_value.data() + m_value.size(), num);
    return num;
}

// "this"  pointer
// every method call will pass one 'this' pointer, and it can use to disambiguation.


