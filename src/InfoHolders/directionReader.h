#ifndef DIRECTIONREADER_H
#define DIRECTIONREADER_H

#include <iostream>
#include "../Battleship.h"
#include "../Exceptions/UnknownCommandException.h"



class DirectionReader {
	public:
	Direction read();
};

#endif