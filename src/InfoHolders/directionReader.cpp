#include "directionReader.h"

Direction DirectionReader::read()
{
	Direction d;
	char ch;
	std::cout << "Введите направление, u, d, l, r: ";
	std::cin >> ch;
	if (ch == 'u')
	{
		d = Direction::Up;
		return d;
	}
	else if (ch == 'd')
	{
		d = Direction::Down;
		return d;
	}
	else if (ch == 'r')
	{
		d = Direction::Right;
		return d;
	}
	else if (ch == 'l')
	{
		d = Direction::Left;
		return d;
	}
	else
	{
		throw UnknownCommandException(d);
	}
}