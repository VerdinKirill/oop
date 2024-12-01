#include "commandHolder.h"

void CommandHolder::read()
{
	this->cmd = this->reader.read();
}

Command CommandHolder::getCommand()
{
	return cmd;
}