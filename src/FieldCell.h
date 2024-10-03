#include "BattleshipCell.h"
#include <memory>

enum class FieldCellState{Unknown, Empty, Ship};
class FieldCell{
	public:
	FieldCell();
	FieldCell(std::shared_ptr<BattleshipCell> ship_cell);
	void SetShipCell(std::shared_ptr<BattleshipCell> ship_cell);
	void SetFieldCellState(FieldCellState state);
	FieldCellState GetFieldState();
	void OpenCellState();
	void AttackCell();
	
	private:
	FieldCellState state;
	std::shared_ptr<BattleshipCell> ship_cell;
	bool near_with_ship;
};