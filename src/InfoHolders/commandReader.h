#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include <iostream>
#include "../Exceptions/UnknownCommandException.h"


enum Command{quit, attack, skill, load};

class CommandReader {
	public:
	Command read();
};

#endif