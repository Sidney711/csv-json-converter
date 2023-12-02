#include <iostream>
#include <string>
#include "Model/UserInput/UserInput.h"
#include "Model/Convertor/Convertor.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        UserInput userInput = UserInput::CreateUserInput(argc, argv);
        Convertor convertor = Convertor(userInput);

        if (userInput.GetConvertWay() == "csv-to-json") {
            convertor.convertToJSON();
        } else {
            convertor.convertToCSV();
        }
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
        return -1;
    }

    return 0;
}
