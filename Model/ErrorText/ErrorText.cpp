//
// Created by sidney on 7.12.23.
//

#include "ErrorText.h"

string ErrorText::invalidOpenInputFile() {
    return "Problem with opening the input file.";
}

string ErrorText::invalidOpenOutputFile() {
    return "Problem with opening the output file";
}

string ErrorText::invalidParams() {
    return "Please enter all parameters!";
}

string ErrorText::invalidFileTypes() {
    return "Please enter valid file types!";
}

string ErrorText::invalidConvertWay() {
    return "Please enter valid convert way!";
}