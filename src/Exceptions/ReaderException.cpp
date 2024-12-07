#include "ReaderException.h"

ReaderException::ReaderException(std::string message)
{
	this->message = message;
}

const char* ReaderException::what() const noexcept
{
	return message.c_str();
}
