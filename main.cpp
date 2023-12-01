#include <iostream>
#include <string>
#include "Model/UserInput/UserInput.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        UserInput userInput = UserInput::CreateUserInput(argc, argv);

        cout << "From file path: " << userInput.GetFromFilePath() << endl;
        cout << "To file path: " << userInput.GetToFilePath() << endl;
        cout << "Convert way: " << userInput.GetConvertWay() << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
        return -1;
    }

    return 0;
}
