#include "BattleshipCell.h"
#include <iostream>
BattleshipCell::BattleshipCell()
{
	(this -> state) = BattleshipCellState::Unbroken;
	std::cout << int(this->state) << '\n';
}

BattleshipCellState BattleshipCell::GetState()
{
	return state;
}

void BattleshipCell::SetState(BattleshipCellState state)
{
	this->state = state;
}

void BattleshipCell::AttackBattleshipCell()
{	
	// std::cout << unsigned(state);
	if (state == BattleshipCellState::Destroyed)
	{
		std::cout << "Destroyed";
	}
	if (state == BattleshipCellState::Unbroken)
	{
		std::cout << "Damaged\n";
	}
	state = ((state == BattleshipCellState::Unbroken) ? BattleshipCellState::Damaged : BattleshipCellState:: Destroyed);
	// std::cout <<  int(state) << "you";
}