#pragma once
#include "Battleship.h"

class Battleship;

enum BattleshipCellState{Destroyed, Damaged, Unbroken};
class BattleshipCell{
	public:
	BattleshipCell(Battleship* battleship);
	BattleshipCellState GetState();
	void SetState(BattleshipCellState state);
	bool AttackBattleshipCell();
	bool isBattleshipDestroyed();

	private:
	Battleship* battleship;
	BattleshipCellState state;	
};