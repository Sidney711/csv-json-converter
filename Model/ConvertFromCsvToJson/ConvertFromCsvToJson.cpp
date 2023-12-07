//
// Created by sidney on 7.12.23.
//

#include "ConvertFromCsvToJson.h"
#include "../ErrorText/ErrorText.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> ConvertFromCsvToJson::getHeadersOfCsv(string line) {
    vector<string> headersOfCSV;
    string header;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ';' || line[i] == ',' || line[i] == '\t' || line[i+1] == '\0') {
            headersOfCSV.push_back(header);
            header = "";
        } else {
            if (line[i] == '"') {
                continue;
            }
            header += line[i];
        }
    }

    return headersOfCSV;
}

void ConvertFromCsvToJson::printOneJsonBlockFromLine(string line, vector<string> headersOfCSV, bool firstRecord) {
    vector<string> valuesOfCSV;
    string value;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ';' || line[i] == ',' || line[i] == '\t' || line[i+1] == '\0') {
            valuesOfCSV.push_back(value);
            value = "";
        } else {
            if (line[i] == '"') {
                continue;
            }
            value += line[i];
        }
    }

    if (!firstRecord) {
        outputFile << ",";
    }

    outputFile << "{";
    for (int i = 0; i < valuesOfCSV.size(); i++) {
        outputFile << "\"" << headersOfCSV[i] << "\":" << "\"" << valuesOfCSV[i] << "\"";

        if (i != valuesOfCSV.size() - 1) {
            outputFile << ",";
        }
    }
    outputFile << "}";
}

void ConvertFromCsvToJson::convert(UserInput userInput) {
    try {
        inputFile.open(userInput.GetFromFilePath());
    } catch (exception e) {
        cout << ErrorText::invalidOpenInputFile() << endl;
        exit(1);
    }

    try {
        outputFile.open(userInput.GetToFilePath());
    } catch (exception e) {
        cout << ErrorText::invalidOpenOutputFile() << endl;
        exit(1);
    }

    string line;
    getline(inputFile, line);

    vector<string> headersOfCSV = this->getHeadersOfCsv(line);

    outputFile << "[";

    bool firstRecord = true;
    while (getline(inputFile, line)) {
        if (firstRecord) {
            printOneJsonBlockFromLine(line, headersOfCSV, firstRecord);
            firstRecord = false;
            continue;
        }

        printOneJsonBlockFromLine(line, headersOfCSV, firstRecord);
    }

    outputFile << "]";

    inputFile.close();
    outputFile.close();
}
