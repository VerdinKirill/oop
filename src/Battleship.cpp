#include "Battleship.h"


Battleship::Battleship(int length, Direction direction)
{
	this->length = length;
	for (size_t i = 0; i<length; i++)
	{
		this->battleship.push_back(BattleshipCell());
	}
	this->direction = direction;
}

std::shared_ptr<BattleshipCell> Battleship::operator[](unsigned int index)
{
	return std::make_shared<BattleshipCell>(battleship[index]);
}


Direction Battleship::GetDirection()
{
	return this->direction;
}

void Battleship::SetDirection(Direction direction)
{
	this->direction = direction;
}

unsigned char Battleship::GetLength()
{
	return this->length;
}

