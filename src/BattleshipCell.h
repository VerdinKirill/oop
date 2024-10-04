#pragma once

enum class BattleshipCellState{Destroyed, Damaged, Unbroken};
class BattleshipCell{
	public:
	BattleshipCell();
	BattleshipCellState GetState();
	void SetState(BattleshipCellState state);
	void AttackBattleshipCell();

	private:
	BattleshipCellState state;	
};