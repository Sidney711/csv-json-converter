//
// Created by sidney on 1.12.23.
//

#include <iostream>
#include "UserInput.h"

using namespace std;

UserInput::UserInput(string fromFilePath, string toFilePath, string convertWay) {
    this->fromFilePath = fromFilePath;
    this->toFilePath = toFilePath;
    this->convertWay = convertWay;
}

UserInput UserInput::CreateUserInput(int argc, char *argv[]) {
    if (argc != 4) {
        throw invalid_argument("Please enter all parameters!");
    }

    string fromFilePath = argv[1];
    string toFilePath = argv[2];
    string convertWay = argv[3];

    if (fromFilePath.empty() || toFilePath.empty() || convertWay.empty()) {
        throw invalid_argument("Please enter all parameters!");
    }

    if (convertWay == "csv-to-json") {
        if (fromFilePath.substr(fromFilePath.find_last_of(".") + 1) != "csv" || toFilePath.substr(toFilePath.find_last_of(".") + 1) != "json") {
            throw invalid_argument("Please enter valid file types!");
        }
    } else if (convertWay == "json-to-csv") {
        if (fromFilePath.substr(fromFilePath.find_last_of(".") + 1) != "json" || toFilePath.substr(toFilePath.find_last_of(".") + 1) != "csv") {
            throw invalid_argument("Please enter valid file types!");
        }
    } else {
        throw invalid_argument("Please enter valid convert way!");
    }

    return UserInput(fromFilePath, toFilePath, convertWay);
}

string UserInput::GetFromFilePath() {
    return this->fromFilePath;
}

string UserInput::GetToFilePath() {
    return this->toFilePath;
}

string UserInput::GetConvertWay() {
    return this->convertWay;
}
