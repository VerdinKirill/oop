#include "BattleshipCell.h"
#include <iostream>
BattleshipCell::BattleshipCell(Battleship* battleship)
{
	this->battleship = battleship;
	(this->state) = BattleshipCellState::Unbroken;
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

bool BattleshipCell::AttackBattleshipCell()
{	
	auto start_state = state;
	state = ((state == BattleshipCellState::Unbroken) ? BattleshipCellState::Damaged : BattleshipCellState::Destroyed);
	// std::cout << isBattleshipDestroyed() << '\n';
	return (start_state!= BattleshipCellState::Destroyed) ? isBattleshipDestroyed() : false;
	// std::cout <<  int(state) << "you";
}

bool BattleshipCell::isBattleshipDestroyed()
{	
	// std::cout <<"adress of battleship in battleshipcell: "<< battleship << '\n';
	return battleship->isDestroyed();
}