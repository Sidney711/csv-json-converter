//
// Created by sidney on 7.12.23.
//

#ifndef CSV_JSON_CONVERTER_ERRORTEXT_H
#define CSV_JSON_CONVERTER_ERRORTEXT_H

#include <string>

using namespace std;


class ErrorText {
private:
    ErrorText();
public:
    static string invalidOpenInputFile();
    static string invalidOpenOutputFile();
    static string invalidParams();
    static string invalidFileTypes();
    static string invalidConvertWay();
};


#endif //CSV_JSON_CONVERTER_ERRORTEXT_H
