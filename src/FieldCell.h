#pragma once
#include "BattleshipCell.h"
#include <memory>
#include <iostream>
#include <string>

enum FieldCellState{Unknown, Empty, Ship};
class FieldCell{
	public:
	FieldCell();
	FieldCell(BattleshipCell& ship_cell);
	void SetShipCell(BattleshipCell& ship_cell);
	bool isBattleshipCell();

	void SetFieldCellState(FieldCellState state);
	const FieldCellState GetFieldState();
	void OpenCellState();
	bool AttackCell();
	friend std::ostream &operator<<(std::ostream& os, FieldCell& cell);
	std::string to_string();
	void SetNearWithShip();
	bool IsNearWithShip();
	
	private:
	FieldCellState state;
	BattleshipCell* ship_cell;
	bool near_with_ship;
};