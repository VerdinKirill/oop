#pragma once

#include "../Exceptions/UnableOpenFileException.h"
#include "../libraries/json.hpp"

#include <iostream>
#include <fstream>

class FileWrapper {
private:
    std::fstream file;
    std::string fileName;
public:
    FileWrapper(const std::string& fileName);

    ~FileWrapper();
    void read(nlohmann::json& j);
    void write(nlohmann::json& j);
};