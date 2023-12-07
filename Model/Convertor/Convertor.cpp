#include "Convertor.h"

using namespace std;

Convertor::Convertor(ConvertStrategy & convertStrategy) : convertStrategy(convertStrategy) {

}

void Convertor::convert(UserInput userInput) {
    this->convertStrategy.convert(userInput);
}
