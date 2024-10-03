#include "Battleship.h"


Battleship::Battleship(int length = 1, Direction direction = Direction::Up)
{
	this->length = length;
	this->battleship = std::vector<BattleshipCell>(length, BattleshipCell());
	this->direction = direction;
}

std::shared_ptr<BattleshipCell> Battleship::operator[](unsigned int index)
{
	std::shared_ptr<BattleshipCell> ptr(&battleship[index]);
	return ptr;
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

