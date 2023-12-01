//
// Created by sidney on 1.12.23.
//

#ifndef CSV_JSON_CONVERTER_USERINPUT_H
#define CSV_JSON_CONVERTER_USERINPUT_H

#include <string>

using namespace std;

class UserInput {
private:
    string fromFilePath;
    string toFilePath;
    string convertWay;
    UserInput(string fromFilePath, string toFilePath, string convertWay);
public:
    static UserInput CreateUserInput(int argc, char *argv[]);
    string GetFromFilePath();
    string GetToFilePath();
    string GetConvertWay();
};


#endif //CSV_JSON_CONVERTER_USERINPUT_H
