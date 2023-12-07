cmake_minimum_required(VERSION 3.26)
project(csv_json_converter)

set(CMAKE_CXX_STANDARD 17)

add_executable(csv_json_converter main.cpp
        Model/UserInput/UserInput.cpp
        Model/UserInput/UserInput.h
        Model/Convertor/Convertor.cpp
        Model/Convertor/Convertor.h
        Model/ErrorText/ErrorText.cpp
        Model/ErrorText/ErrorText.h
        Model/ConvertStrategy/ConvertStrategy.h
        Model/ConvertFromCsvToJson/ConvertFromCsvToJson.cpp
        Model/ConvertFromCsvToJson/ConvertFromCsvToJson.h
        Model/ConvertFromJsonToCsv/ConvertFromJsonToCsv.cpp
        Model/ConvertFromJsonToCsv/ConvertFromJsonToCsv.h)
