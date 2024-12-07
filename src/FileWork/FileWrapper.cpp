#include "FileWrapper.h"

FileWrapper::FileWrapper(const std::string& fileName) : file(fileName){}

FileWrapper::~FileWrapper()
{
	if (file.is_open())
	{
		file.close();
	}
}

void FileWrapper::read(nlohmann::json& j) {
    if (!file.is_open() || !file.good()) {
        throw  UnableOpenFileException();
    }
    file >> j;
}

void FileWrapper::write(nlohmann::json& j) {
    if (!file.is_open() || !file.good()) {
        throw UnableOpenFileException();
    }
    file << j.dump(4);
}