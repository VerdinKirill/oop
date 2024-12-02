#include "commandReader.h"

Command CommandReader::read()
{	std::cout << "Введи название команды:\n"
	"s - выход\n"
	"a - атака\n"
	"u-успользовать способность\n"
	"l-загрузить игру\n";
	char ch;
	std::cin >> ch;
	if (ch == 's')
	{
		return Command::save;
	}
	if (ch == 'a')
	{
		return Command::attack;
	}
	if (ch == 'u')
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