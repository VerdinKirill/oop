#ifndef BATTLESHIPCELL
#define BATTLESHIPCELL
#include "Battleship.h"

class Battleship;



enum BattleshipCellState : signed{Destroyed, Damaged, Unbroken};
class BattleshipCell{
	public:
	BattleshipCell(Battleship* battleship);
	BattleshipCellState GetState();
	void SetState(BattleshipCellState state);
	bool AttackBattleshipCell(int damage = 1);
	bool isBattleshipDestroyed();

	private:
	Battleship* battleship;
	BattleshipCellState state;	
};

#endif