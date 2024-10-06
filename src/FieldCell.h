#pragma once
#include "BattleshipCell.h"
#include <memory>
#include <iostream>
#include <string>

enum class FieldCellState{Unknown, Empty, Ship};
class FieldCell{
	public:
	FieldCell();
	FieldCell(std::shared_ptr<BattleshipCell> ship_cell);
	void SetShipCell(std::shared_ptr<BattleshipCell> ship_cell);
	void SetFieldCellState(FieldCellState state);
	const FieldCellState GetFieldState();
	void OpenCellState();
	void AttackCell();
	friend std::ostream &operator<<(std::ostream& os, FieldCell& cell);
	std::string to_string();
	void SetNearWithShip();
	bool IsNearWithShip();
	
	private:
	FieldCellState state;
	std::shared_ptr<BattleshipCell> ship_cell;
	bool near_with_ship;
};