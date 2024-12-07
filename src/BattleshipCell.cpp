#include "BattleshipCell.h"
#include <iostream>
BattleshipCell::BattleshipCell(Battleship* battleship)
{
	this->battleship = battleship;
	(this->state) = BattleshipCellState::Unbroken;
	this->isHead = false;
	// std::cout << int(this->state) << '\n';
}

BattleshipCellState BattleshipCell::GetState()
{
	return state;
}

void BattleshipCell::SetState(BattleshipCellState state)
{
	this->state = state;
}

bool BattleshipCell::getIsHead()
{
	return this->isHead;
}

void BattleshipCell::setIsHead(bool i)
{
	this->isHead = i;
}

void BattleshipCell::setCoordinates(std::pair<int, int> coordinates)
{
	this->coordinates = coordinates;
}

std::pair<int, int> BattleshipCell::getCoordinates()
{
	return this->coordinates;
}



bool BattleshipCell::AttackBattleshipCell(int damage)
{	
	auto start_state = state;
	state = (state-damage > 0) ? BattleshipCellState(state-damage) : BattleshipCellState::Destroyed;
	return (start_state!= BattleshipCellState::Destroyed) ? isBattleshipDestroyed() : false;
	// std::cout <<  int(state) << "you";
}

bool BattleshipCell::isBattleshipDestroyed()
{	
	// std::cout <<"adress of battleship in battleshipcell: "<< battleship << '\n';
	return battleship->isDestroyed();
}

int BattleshipCell::getBattleshipId()
{
	return this->battleship->getId();
}