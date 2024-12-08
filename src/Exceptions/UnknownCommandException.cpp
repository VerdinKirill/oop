#include "UnknownCommandException.h"

UnknownCommandException::UnknownCommandException(char command)
{
	this->message = std::string("Unknown Command ") + command;
}

const char* UnknownCommandException:: what() const noexcept
{
	return message.c_str();
}