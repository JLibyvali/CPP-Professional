//
// Created by jlibyvali on 24-3-29.
//

#ifndef CHAPTER10_DOUBLESPREADSHEETCELL_H
#define CHAPTER10_DOUBLESPREADSHEETCELL_H

#include "SpreadsheetCell.h"
#include <optional>

class DoubleSpreadsheetCell : public  SpreadsheetCell{
public:
        virtual  void set(double value ) ;
        void set(std::string_view  value) override;
        std::string getString() const override;
private:
        static std::string doubleToString(double value);
        static double stringToDouble(std::string_view value);
        std::optional<double> m_value;


};

#endif //CHAPTER10_DOUBLESPREADSHEETCELL_H
