#ifndef BATTLESHIPCELL
#define BATTLESHIPCELL
#include "Battleship.h"

class Battleship;



enum BattleshipCellState : signed{Destroyed = 0, Damaged, Unbroken};
class BattleshipCell{
	public:
	BattleshipCell(Battleship* battleship);
	BattleshipCellState GetState();
	void SetState(BattleshipCellState state);
	bool AttackBattleshipCell(int damage = 1);
	bool isBattleshipDestroyed();
	int getBattleshipId();
	void setIsHead(bool i);
	bool getIsHead();


	private:
	bool isHead;
	Battleship* battleship;
	BattleshipCellState state;	
};

#endif