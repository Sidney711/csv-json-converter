//
// Created by sidney on 7.12.23.
//

#ifndef CSV_JSON_CONVERTER_CONVERTSTRATEGY_H
#define CSV_JSON_CONVERTER_CONVERTSTRATEGY_H

#include "../UserInput/UserInput.h"
#include <fstream>


class ConvertStrategy {
public:
    virtual void convert(UserInput userInput) = 0;
};


#endif //CSV_JSON_CONVERTER_CONVERTSTRATEGY_H
