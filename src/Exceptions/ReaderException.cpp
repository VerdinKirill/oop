#include "ReaderException.h"

const char* ReaderException::what() const noexcept
{
	return message.c_str();
}
