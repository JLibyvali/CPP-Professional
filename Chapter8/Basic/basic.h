//
// Created by jlibyvali on 24-3-24.
//

#ifndef CLASS_BASIC_H
#define CLASS_BASIC_H


#include <iostream>
#include <string_view>
#include <string>

using namespace std;

class SpreadsheetCell {
// Declaration
public:
    SpreadsheetCell() = default;    // default ctor,
    /* ctor:
     * 1. never call explicitly: SpreadsheetCell sell.SreadsheetCell() #ERROR
     * 2. in stack : auto cell { SpreadsheetCell(3)}, in heap: auto* cell { new SpreadsheetCell(5) }
     * 3. can declare first and implementation later: auto* cell { nullptr}
     *                                                cell { new SpreadsheetCell(654) }
     * */
// It's also one conversion ctor, use explicit to avoid conversion implicit
    explicit SpreadsheetCell(double m_v) : value{m_v} {
        /*Initializer
         * Initializer will call object's ctor, so some type must initial in it:const,reference,none-ctor data,non-ctor base-class
         * in ctor's body assignment will not call other ctors default, just change the value;
         *
         * */
    }

// Copy ctor: enable create duplication from one object
    SpreadsheetCell(const SpreadsheetCell &rhs) {
        value = rhs.value;
    }

// delegating ctor: enable it can call other ctors in this class, it only allowed in initializer
    SpreadsheetCell(string_view m_str) : SpreadsheetCell{stringToDouble(m_str)} {

    }

// dtor:
    ~SpreadsheetCell() {
        cout << "Destructor called" << endl;

    }

// Operator overwrite
    SpreadsheetCell &operator=(const SpreadsheetCell &rhs) {
        if (this == &rhs) {
            return *this;
        } else {
            value = rhs.value;
            return  *this;
        }
    }


    void setValue(double m_value);

    double getValue() const;

    void setString(string_view m_value);

    string getString() const;

private:
    string doubleToString(double m_value) const;

    double stringToDouble(string_view m_value) const;

    double value{0};

};







#endif //CLASS_BASIC_H
