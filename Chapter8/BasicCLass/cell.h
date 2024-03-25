//
// Created by jlibyvali on 24-3-24.
//

#ifndef CLASS_CELL_H
#define CLASS_CELL_H


#include <iostream>
#include <string_view>
#include <string>

using namespace std;

class cell {
// Declaration
public:
    cell(){

    };    // default ctor,
    /* ctor:
     * 1. never call explicitly: cell sell.SreadsheetCell() #ERROR
     * 2. in stack : auto cell { cell(3)}, in heap: auto* cell { new cell(5) }
     * 3. can declare first and implementation later: auto* cell { nullptr}
     *                                                cell { new cell(654) }
     * */
// It's also one conversion ctor, use explicit to avoid conversion implicit
    explicit cell(double m_v) : value{m_v} {
        /*Initializer
         * Initializer will call object's ctor, so some type must initial in it:const,reference,none-ctor data,non-ctor base-class
         * in ctor's body assignment will not call other ctors default, just change the value;
         *
         * */
    }

// Copy ctor: enable create duplication from one object
    cell(const cell &rhs) {
        value = rhs.value;
    }

// delegating ctor: enable it can call other ctors in this class, it only allowed in initializer
    cell(string_view m_str) : cell{stringToDouble(m_str)} {

    }

// dtor:
    ~cell() {
        cout << "Destructor called" << endl;
    }

// Operator overwrite
    cell &operator=(const cell &rhs) {
        if (this == &rhs) {
            return *this;
        } else {
            value = rhs.value;
            return  *this;
        }
    }

    [[nodiscard]]  bool operator==(const cell& rhs) const = default;
    [[nodiscard]] std::partial_ordering  operator<=>(const cell& rhs) const = default ;

    void setValue(double m_value);

    double getValue() const;

    void setString(string_view m_value);

    string getString() const;

private:
    string doubleToString(double m_value) const;

    double stringToDouble(string_view m_value) const;

    double value{0};

};




#endif //CLASS_CELL_H
