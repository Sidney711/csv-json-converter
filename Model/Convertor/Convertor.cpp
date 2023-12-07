#include <fstream>
#include <vector>
#include <algorithm>
#include "Convertor.h"
#include <iostream>
#include <string>
#include "../ErrorText/ErrorText.h"

using namespace std;

Convertor::Convertor(UserInput userInput) {
    this->userInput = userInput;

    try {
        inputFile.open(this->userInput.GetFromFilePath());
    } catch (exception e) {
        cout << (new ErrorText())->invalidOpenInputFile() << endl;
        exit(1);
    }

    try {
        outputFile.open(this->userInput.GetToFilePath());
    } catch (exception e) {
        cout << (new ErrorText())->invalidOpenOutputFile() << endl;
        exit(1);
    }
}

vector<string> Convertor::getHeadersOfCsv(string line) {
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

void Convertor::printOneJsonBlockFromLine(string line, vector<string> headersOfCSV, bool firstRecord) {
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

void Convertor::convertToJSON() {
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
}

void Convertor::processOneLineFromJson(string line, string& block, bool& record) {
    for (int i = 1; i < line.length(); i++) {
        if (line[i] == '[') {
            i++;
            while (line[i] != ']') {
                block += line[i];
                i++;
            }
            continue;
        }

        if (line[i] == ',') {
            block += line[i];
            record = false;
            continue;
        }

        if (line[i] == ':') {
            record = true;
            continue;
        }

        if (line[i] == '{') {
            continue;
        }

        if (line[i] == '}') {
            if(block[block.length() - 1] == ',') {
                block = block.substr(0, block.length() - 1);
            }
            outputFile << block << endl;
            block = "";
            i++;
            record = false;
            continue;
        }

        if (record){
            block += line[i];
        }
    }
}

void Convertor::convertToCSV() {
    string line;
    string block = "";
    bool record = false;

    while (getline(inputFile, line)) {
        processOneLineFromJson(line, block, record);
    }
}

Convertor::~Convertor() {
    inputFile.close();
    outputFile.close();
}