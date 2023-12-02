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
    string escapeJSON(const string& str);
public:
    Convertor(UserInput userInput);
    void convertToJSON();
    void convertToCSV();
    vector<string> split(string line, char delimiter);
    string trimQuotesAndSpaces(const string& str);
};


#endif //CSV_JSON_CONVERTER_CONVERTOR_H
