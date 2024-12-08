#include "Battleship.h"
#include <iostream>

Battleship::Battleship(BattleshipLength length, Direction direction, int id)
{	
	this->id = id;
	this->battleship = std::vector<BattleshipCell>(length, BattleshipCell(this));
	this->battleship[0].setIsHead(true);
	this->length = length;
	this->direction = direction;
}

BattleshipCell &Battleship::operator[](int index)
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
	for (int i = 0; i < this->GetLength(); i++)
	{
		if(battleship[i].GetState() != BattleshipCellState::Destroyed)
			return false;
	}
	return true;

}

int Battleship::getId()
{
	return this->id;
}
