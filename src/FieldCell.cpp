#include "FieldCell.h"

FieldCell::FieldCell()
{
	this->ship_cell = nullptr;
	this->state = FieldCellState::Unknown;
}

FieldCell::FieldCell(std::shared_ptr<BattleshipCell> ship_cell)
{
	SetShipCell(ship_cell);
	this->state = FieldCellState::Unknown;
}
void FieldCell::SetShipCell(std::shared_ptr<BattleshipCell> ship_cell)
{
	this->ship_cell = ship_cell;
}

void FieldCell::SetFieldCellState(FieldCellState state)
{
	this->state = state;
}

void FieldCell::OpenCellState()
{
	if (this->state != FieldCellState::Unknown)
		return;
	if (this->ship_cell)
		this->SetFieldCellState(FieldCellState::Ship);
	else
		this->SetFieldCellState(FieldCellState::Empty);
}

FieldCellState FieldCell::GetFieldState()
{
	return this->state;
}

void FieldCell::AttackCell()
{
	this->OpenCellState();
	this->ship_cell->AttackBattleshipCell();
}