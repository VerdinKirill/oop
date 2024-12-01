#include "commandReader.h"

Command CommandReader::read()
{	
	char ch;
	std::cin >> ch;
	if (ch == 'q')
	{
		return Command::quit;
	}
	if (ch == 'a')
	{
		return Command::attack;
	}
	if (ch == 's')
	{
		return Command::skill;
	}
	if (ch == 'l')
	{
		return Command::load;
	}
	else {
		throw new UnknownCommandException(ch);
	}
};