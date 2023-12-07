//
// Created by sidney on 7.12.23.
//

#include <iostream>
#include "ConvertFromJsonToCsv.h"
#include "../ErrorText/ErrorText.h"

void ConvertFromJsonToCsv::processOneLineFromJson(string line, string& block, bool& record) {
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

void ConvertFromJsonToCsv::convert(UserInput userInput) {
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
    string block = "";
    bool record = false;

    while (getline(inputFile, line)) {
        processOneLineFromJson(line, block, record);
    }

    inputFile.close();
    outputFile.close();
}
