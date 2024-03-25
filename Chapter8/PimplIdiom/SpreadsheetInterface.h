#include "Spreadsheet.h"

// Spreadsheet nested class definition
class Spreadsheet::Impl {
public:
// ctor
    Impl() = default;

    ~Impl();

    Impl(size_t width, size_t height);

    Impl(const Impl &src);

    Impl(Impl &&rhs) noexcept;

// Copy and Move Operator
    Impl &operator=(const Impl &src);

    Impl &operator=(Impl &&rhs) noexcept;

//anoter
    void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);

    SpreadsheetCell &getCellAt(size_t x, size_t y);

    void verifyCoordinate(size_t x, size_t y) const;

    // for copy operator
    void moveFrom(Impl &src) noexcept;

    void swap(Impl &othrer) noexcept;

// data members
    size_t m_width{0};
    size_t m_height{0};
    std::string m_name{};
    SpreadsheetCell **m_cells{nullptr};

};

// caculate operators
//SpreadsheetCell operator+(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs) {
//    return SpreadsheetCell{lhs.getValue() + rhs.getValue()};
//}
//
//SpreadsheetCell operator-(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs) {
//    return SpreadsheetCell{lhs.getValue() - rhs.getValue()};
//}
//
//SpreadsheetCell operator*(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs) {
//    return SpreadsheetCell{lhs.getValue() * rhs.getValue()};
//}
//
//SpreadsheetCell operator/(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs) {
//    if (rhs.getValue() == 0) {
//        throw std::invalid_argument("Divide is zero!!");
//    } else {
//        return SpreadsheetCell{lhs.getValue() / rhs.getValue()};
//    }
//}
//

