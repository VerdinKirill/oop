#include "ModifiedJsonException.h"

ModifiedJsonException::ModifiedJsonException(std::string message)
{
	this->message = "Json file with data was modified!" + message;
}

const char* ModifiedJsonException::what() const noexcept
{
	return message.c_str();
}