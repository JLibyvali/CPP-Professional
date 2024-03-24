//
// Created by jlibyvali on 24-3-24.
//

#include "basic.h"

using namespace std;

class Spreadsheet{

public:
    Spreadsheet(size_t width, size_t height);
    void setCellAt(size_t x, size_t y,const SpreadsheetCell& cell);
    SpreadsheetCell& getCellAt(size_t x, size_t y);

private:
    bool inRange(size_t value, size_t upper) const;
    size_t m_width { 0 };
    size_t m_height{ 0 };
    SpreadsheetCell** m_cells { nullptr };
};





int main(){





    return 0;
}
