//
// Created by jlibyvali on 24-3-29.
//

#ifndef CHAPTER10_SPREADSHEETCELL_H
#define CHAPTER10_SPREADSHEETCELL_H

#include <string>
#include <string_view>


class SpreadsheetCell {

public:
        virtual ~SpreadsheetCell() = default;
        virtual void set(std::string_view  value)  = 0;
        virtual std::string getString() const = 0 ;


};


#endif //CHAPTER10_SPREADSHEETCELL_H
