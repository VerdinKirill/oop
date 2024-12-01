#include "UnknownCommandException.h"

UnknownCommandException::UnknownCommandException(char command)
{
	this->message = "Unknown Command" + command;
}

const char* UnknownCommandException:: what() const noexcept
{
	return message.c_str();
}