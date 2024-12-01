#include "BotException.h"

BotException::BotException(std::string message)
{
	this->message = "Bot cant use" + message;
}


// BotException::BotException(const BotException& other) : message(other.message) {};


const char* BotException::what() const noexcept{

	return message.c_str();
}
