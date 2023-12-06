#include <fstream>
#include <vector>
#include <algorithm>
#include "Convertor.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Convertor::Convertor(UserInput userInput) {
    this->userInput = userInput;
}

void Convertor::convertToJSON() {
    ifstream inputFile;
    inputFile.open(this->userInput.GetFromFilePath());

    string line;

    getline(inputFile, line);

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

    ofstream outputFile;
    outputFile.open(this->userInput.GetToFilePath());

    outputFile << "[";

    bool firstRecord = true;

    while (getline(inputFile, line)) {
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
        } else {
            firstRecord = false; // Nastavíme na false po prvním záznamu
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

    outputFile << "]";

    inputFile.close();
    outputFile.close();
}

