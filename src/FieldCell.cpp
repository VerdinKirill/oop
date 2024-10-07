#include "FieldCell.h"

FieldCell::FieldCell()
{
	this->ship_cell = nullptr;
	this->near_with_ship = false;
	this->state = FieldCellState::Unknown;
}

FieldCell::FieldCell(std::shared_ptr<BattleshipCell> ship_cell)
{
	SetShipCell(ship_cell);
}
void FieldCell::SetShipCell(std::shared_ptr<BattleshipCell> ship_cell)
{
	this->ship_cell = ship_cell;
}

void FieldCell::SetFieldCellState(FieldCellState state)
{
	this->state = state;
	// std::cout << unsigned(this->state) << "state of cell\n";
}

void FieldCell::OpenCellState()
{	
	if (this->ship_cell)
	{	
		this->SetFieldCellState(FieldCellState::Ship);
	}
	else this->SetFieldCellState(FieldCellState::Empty);
}

const FieldCellState FieldCell::GetFieldState()
{
	return this->state;
}

void FieldCell::AttackCell()
{
	if (this->ship_cell)
	{	
		this->ship_cell->AttackBattleshipCell();
	}
}

std::string FieldCell::to_string()
{	
	std::string value;
	if (state == FieldCellState::Unknown)
	{
		value = "🟦";
	}
	else if (state == FieldCellState::Empty)
		value = "🌀";
	else if (state == FieldCellState::Ship)
	{	
		auto state = ship_cell->GetState();
		if (state == BattleshipCellState::Destroyed)
		{
			value = "🟥";
		}
		else if (state == BattleshipCellState::Damaged)
			value = "🟨";
		else
			value = "🟩";
	}
	return value;
}

std::ostream &operator<<(std::ostream &os, FieldCell &cell)
{
	auto value = cell.to_string();
	os << value;
	return os;
}

void FieldCell::SetNearWithShip()
{
	this->near_with_ship = true;
}

bool FieldCell::IsNearWithShip()
{
	return this->near_with_ship;
}
