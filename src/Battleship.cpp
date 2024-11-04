#include "Battleship.h"
#include <iostream>


Battleship::Battleship(BattleshipLength length, Direction direction)
{
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

int Battleship::GetLength()
{	
	return battleship.size();
}

