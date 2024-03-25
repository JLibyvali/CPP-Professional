//
// Created by jlibyvali on 24-3-25.
//

#ifndef CLASS_SPREADSHEETCELL_H
#define CLASS_SPREADSHEETCELL_H

#include <string>
#include <string_view>


class SpreadsheetCell {
public:
// ctor
    SpreadsheetCell();
    /* ctor:
     * 1. never call explicitly: cell sell.SpreadsheetCell() #ERROR
     * 2. in stack : auto cell { cell(3)}, in heap: auto* cell { new cell(5) }
     * 3. can declare first and implementation later: auto* cell { nullptr}
     *                                                cell { new cell(654) }
     * */
    // It's also one conversion ctor, use explicit to avoid conversion implicit
    explicit SpreadsheetCell(double m_v);

    // delegating ctor: enable it can call other ctors in this class, it only allowed in initializer
    SpreadsheetCell(std::string_view m_str);

    // Copy ctor: enable create duplication from one object
    SpreadsheetCell(const SpreadsheetCell &rhs);

    // dtor:
    ~SpreadsheetCell();

// compared Operator
    [[nodiscard]]  bool operator==(const SpreadsheetCell &rhs) const = default;

    [[nodiscard]] std::partial_ordering operator<=>(const SpreadsheetCell &rhs) const = default;

// Operator overwrite
    SpreadsheetCell &operator=(const SpreadsheetCell &rhs);

// another method
    void setValue(double m_value);

    double getValue() const;

    void setString(std::string_view m_value);

    std::string getString() const;

private:
    std::string doubleToString(double m_value) const;

    double stringToDouble(std::string_view m_value) const;

    double value{0};
};


#endif //CLASS_SPREADSHEETCELL_H
