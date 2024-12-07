#ifndef FIELDCELL_H
#define FIELDCELL_H

#include "BattleshipCell.h"
#include <memory>
#include <iostream>
#include <string>


enum FieldCellState{Unknown, Empty, Ship2, Ship1, Ship0};
class FieldCell{
	public:
	FieldCell();
	FieldCell(BattleshipCell& ship_cell);
	void SetShipCell(BattleshipCell& ship_cell);
	bool isBattleshipCell();

	void SetFieldCellState(FieldCellState state);
	const FieldCellState GetFieldState();
	void OpenCellState();
	bool AttackCell(int damage = 1);
	friend std::ostream &operator<<(std::ostream& os, FieldCell& cell);
	std::string to_string();
	void SetNearWithShip();
	bool IsNearWithShip();
	int getIdBattleship();
	void setIdBattleship(int id);
	bool isHeadBattleship(bool i = false);
	void setIsHead(bool isHead);
	void setBattleshipCell(BattleshipCell& cell);
	void setCoordinates(std::pair<int, int> coordinates);
	
	private:
	bool isHead;
	int battleshipId;
	FieldCellState state;
	BattleshipCell* ship_cell;
	bool near_with_ship;
};

#endif