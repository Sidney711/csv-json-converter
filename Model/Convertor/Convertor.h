//
// Created by sidney on 2.12.23.
//

#ifndef CSV_JSON_CONVERTER_CONVERTOR_H
#define CSV_JSON_CONVERTER_CONVERTOR_H


#include "../UserInput/UserInput.h"
#include "../ConvertStrategy/ConvertStrategy.h"
#include <vector>
#include <fstream>

class Convertor {
private:
    ConvertStrategy & convertStrategy;
public:
    Convertor(ConvertStrategy & convertStrategy);
    void convert(UserInput userInput);
};


#endif //CSV_JSON_CONVERTER_CONVERTOR_H
