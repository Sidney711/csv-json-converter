//
// Created by sidney on 7.12.23.
//

#ifndef CSV_JSON_CONVERTER_CONVERTFROMJSONTOCSV_H
#define CSV_JSON_CONVERTER_CONVERTFROMJSONTOCSV_H

#include "../ConvertStrategy/ConvertStrategy.h"

class ConvertFromJsonToCsv : public ConvertStrategy {
private:
    ifstream inputFile;
    ofstream outputFile;

    void processOneLineFromJson(string line, string &block, bool &record);
public:
    void convert(UserInput userInput) override;
};


#endif //CSV_JSON_CONVERTER_CONVERTFROMJSONTOCSV_H
