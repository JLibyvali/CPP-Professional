//
// Created by jlibyvali on 24-3-29.
//

#ifndef CHAPTER10_STRINGSPREADSHEETCELL_H
#define CHAPTER10_STRINGSPREADSHEETCELL_H

#include "SpreadsheetCell.h"
#include <optional>

class StringSpreadsheetCell : public  SpreadsheetCell  {

public:
    void set(std::string_view ) override;
    std::string getString( ) const override;
private:
    std::optional<std::string> m_value;
};


#endif //CHAPTER10_STRINGSPREADSHEETCELL_H
