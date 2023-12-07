//
// Created by sidney on 7.12.23.
//

#ifndef CSV_JSON_CONVERTER_ERRORTEXT_H
#define CSV_JSON_CONVERTER_ERRORTEXT_H

#include <string>

using namespace std;


class ErrorText {
public:
    string invalidOpenInputFile();
    string invalidOpenOutputFile();
    string invalidParams();
    string invalidFileTypes();
    string invalidConvertWay();
};


#endif //CSV_JSON_CONVERTER_ERRORTEXT_H
