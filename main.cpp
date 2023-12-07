#include <iostream>
#include <string>
#include "Model/UserInput/UserInput.h"
#include "Model/Convertor/Convertor.h"
#include "Model/ConvertFromCsvToJson/ConvertFromCsvToJson.h"
#include "Model/ConvertFromJsonToCsv/ConvertFromJsonToCsv.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        UserInput userInput = UserInput::CreateUserInput(argc, argv);

        if (userInput.GetConvertWay() == "csv-to-json") {
            ConvertFromCsvToJson convertFromCsvToJson;
            Convertor convertor = Convertor(convertFromCsvToJson);
            convertor.convert(userInput);
        } else {
            ConvertFromJsonToCsv convertFromJsonToCsv;
            Convertor convertor = Convertor(convertFromJsonToCsv);
            convertor.convert(userInput);
        }
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
