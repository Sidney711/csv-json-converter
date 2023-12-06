#include <fstream>
#include <vector>
#include <algorithm>
#include "Convertor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>

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

void Convertor::convertToCSV() {
    ifstream inputFile;
    inputFile.open(this->userInput.GetFromFilePath());

    ofstream outputFile;
    outputFile.open(this->userInput.GetToFilePath());

    string line;

    vector<string> blocksOfJSON;
    string block = "";

    bool record = false;

    while (getline(inputFile, line)) {
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

    inputFile.close();
    outputFile.close();
}