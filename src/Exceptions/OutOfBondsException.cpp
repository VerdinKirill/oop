#include "OutOfBondsException.h"

OutOfBondsException::OutOfBondsException()
{
	message = "You tried to attack field by coordinates out of bonds!";
}

const char* OutOfBondsException::what() const noexcept
{
	return message.c_str();
}