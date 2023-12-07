//
// Created by sidney on 7.12.23.
//

#ifndef CSV_JSON_CONVERTER_CONVERTFROMCSVTOJSON_H
#define CSV_JSON_CONVERTER_CONVERTFROMCSVTOJSON_H

#include "../ConvertStrategy/ConvertStrategy.h"
#include <string>
#include <vector>

using namespace std;

class ConvertFromCsvToJson : public ConvertStrategy {
private:
    ifstream inputFile;
    ofstream outputFile;

    vector<string> getHeadersOfCsv(string line);
    void printOneJsonBlockFromLine(string line, vector<string> headersOfCSV, bool firstRecord);
public:
    void convert(UserInput userInput) override;
};


#endif //CSV_JSON_CONVERTER_CONVERTFROMCSVTOJSON_H
