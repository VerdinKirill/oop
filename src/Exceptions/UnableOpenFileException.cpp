#include "UnableOpenFileException.h"

UnableOpenFileException::UnableOpenFileException()
{
	message = "Unable to open file!\n";
}

const char* UnableOpenFileException::what() const noexcept
{
	return message.c_str();
}