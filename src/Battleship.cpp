#include "Battleship.h"


Battleship::Battleship(BattleshipLength length, Direction direction)
{
	this->length = length;
	for (size_t i = 0; i<int(length); i++)
	{
		this->battleship.push_back(BattleshipCell());
	}
	this->direction = direction;
}

BattleshipCell& Battleship::operator[](unsigned int index)
{
	return battleship[index];
}


Direction Battleship::GetDirection()
{
	return this->direction;
}

void Battleship::SetDirection(Direction direction)
{
	this->direction = direction;
}

BattleshipLength Battleship::GetLength()
{
	return this->length;
}

