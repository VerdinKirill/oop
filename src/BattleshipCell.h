#pragma once

enum BattleshipCellState{Destroyed, Damaged, Unbroken};
class BattleshipCell{
	public:
	BattleshipCell();
	BattleshipCellState GetState();
	void SetState(BattleshipCellState state);
	void AttackBattleshipCell();

	private:
	BattleshipCellState state;	
};