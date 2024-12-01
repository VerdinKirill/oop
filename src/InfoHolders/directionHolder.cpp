#include "directionHolder.h"


void DirectionHolder::read()
{
	this->d = this->reader.read();
}

Direction DirectionHolder::getDirection()
{
	return this->d;
}

