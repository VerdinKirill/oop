#include "Battleship.h"
#include <iostream>

Battleship::Battleship(BattleshipLength length, Direction direction)
{	
	// std::cout << "Adress of ship in ship" << &*this << '\n';
	this->battleship = std::vector<BattleshipCell>(length, BattleshipCell(this));
	this->length = length;
	this->direction = direction;
}

BattleshipCell &Battleship::operator[](unsigned int index)
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
	return length;
}

bool Battleship::isDestroyed()
{	
	// std::cout << "len " << this->GetLength() << '\n';
	for (int i = 0; i < this->GetLength(); i++)
	{
		if(battleship[i].GetState() != BattleshipCellState::Destroyed)
			return false;
	}
	return true;

}
