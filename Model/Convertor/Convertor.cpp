#include <fstream>
#include <vector>
#include <algorithm>
#include "Convertor.h"

using namespace std;

Convertor::Convertor(UserInput userInput) {
    this->userInput = userInput;
}

void Convertor::convertToJSON() {
    ifstream csvFile(userInput.GetFromFilePath());
    string line;
    vector<string> headers;
    string jsonFileName = userInput.GetToFilePath();
    ofstream jsonFile(jsonFileName);

    if (csvFile.is_open()) {
        getline(csvFile, line);
        headers = split(trimQuotesAndSpaces(line), ',');
        jsonFile << "[";

        bool isFirstRow = true;
        while (getline(csvFile, line)) {
            vector<string> values = split(trimQuotesAndSpaces(line), ',');

            if (!isFirstRow) {
                jsonFile << ",";
            }
            jsonFile << "{";

            for (size_t i = 0; i < headers.size(); i++) {
                string header = trimQuotesAndSpaces(headers[i]);
                string value = escapeJSON(trimQuotesAndSpaces(values[i]));

                jsonFile << "\"" << header << "\": \"" << value << "\"";
                if (i < headers.size() - 1) {
                    jsonFile << ",";
                }
            }
            jsonFile << "}";
            isFirstRow = false;
        }
        jsonFile << "]";
        jsonFile.close();
        csvFile.close();
    }
}

string Convertor::trimQuotesAndSpaces(const string& str) {
    size_t start = str.find_first_not_of(" \"");
    size_t end = str.find_last_not_of(" \"");

    if (start == string::npos || end == string::npos) return "";

    return str.substr(start, end - start + 1);
}

string Convertor::escapeJSON(const string& str) {
    string escaped;
    for (char c : str) {
        switch (c) {
            case '\"': escaped += "\\\""; break;
            case '\\': escaped += "\\\\"; break;
            case '\b': escaped += "\\b"; break;
            case '\f': escaped += "\\f"; break;
            case '\n': escaped += "\\n"; break;
            case '\r': escaped += "\\r"; break;
            case '\t': escaped += "\\t"; break;
            default: escaped += c;
        }
    }
    return escaped;
}




void Convertor::convertToCSV() {
    ifstream jsonFile(userInput.GetFromFilePath());
    string line;
    vector<string> headers;
    vector<string> values;
    vector<string> csvValues;
    vector<string> csvHeaders;
    string csvLine;
    string csv;
    string csvFileName = userInput.GetToFilePath();
    ofstream csvFile(csvFileName);
    if (jsonFile.is_open()) {
        getline(jsonFile, line);
        headers = split(line, ',');
        csvHeaders = headers;
        for (int i = 0; i < csvHeaders.size(); i++) {
            csvHeaders[i] = "\"" + csvHeaders[i] + "\"";
        }
        while (getline(jsonFile, line)) {
            values = split(line, ',');
            csvValues = values;
            for (int i = 0; i < csvValues.size(); i++) {
                csvValues[i] = "\"" + csvValues[i] + "\"";
            }
            csvLine = "";
            for (int i = 0; i < csvHeaders.size(); i++) {
                csvLine.append(csvHeaders[i]);
                csvLine.append(":");
                csvLine.append(csvValues[i]);
                if (i != csvHeaders.size() - 1) {
                    csvLine.append(",");
                }
            }
            csv.append(csvLine);
            csv.append("\n");
        }
        csvFile << csv;
        csvFile.close();
        jsonFile.close();
    }
}

vector<string> Convertor::split(string line, char delimiter) {
    vector<string> result;
    string word;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == delimiter) {
            result.push_back(word);
            word = "";
        } else {
            word += line[i];
        }
    }
    result.push_back(word);
    return result;
}
