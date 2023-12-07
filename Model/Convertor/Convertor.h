//
// Created by sidney on 2.12.23.
//

#ifndef CSV_JSON_CONVERTER_CONVERTOR_H
#define CSV_JSON_CONVERTER_CONVERTOR_H


#include "../UserInput/UserInput.h"
#include <vector>
#include <fstream>

class Convertor {
private:
    UserInput userInput;
    ifstream inputFile;
    ofstream outputFile;
public:
    Convertor(UserInput userInput);
    ~Convertor();
    void convertToJSON();
    void convertToCSV();
    vector<string> getHeadersOfCsv(string line);
    void printOneJsonBlockFromLine(string line, vector<string> headersOfCSV, bool firstRecord);
    void processOneLineFromJson(string line, string& block, bool& record);
};


#endif //CSV_JSON_CONVERTER_CONVERTOR_H
