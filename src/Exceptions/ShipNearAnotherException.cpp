#include "ShipNearAnotherException.h"

ShipNearAnotherException::ShipNearAnotherException()
{
	message = "You tried set ship near another/out of bonds of field!";
}

const char* ShipNearAnotherException::what() const noexcept
{
	return message.c_str();
}