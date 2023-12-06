//
// Created by sidney on 2.12.23.
//

#ifndef CSV_JSON_CONVERTER_CONVERTOR_H
#define CSV_JSON_CONVERTER_CONVERTOR_H


#include "../UserInput/UserInput.h"
#include <vector>

class Convertor {
private:
    UserInput userInput;
public:
    Convertor(UserInput userInput);
    void convertToJSON();
    void convertToCSV();
};


#endif //CSV_JSON_CONVERTER_CONVERTOR_H
