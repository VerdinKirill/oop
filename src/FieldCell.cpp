#include "FieldCell.h"

FieldCell::FieldCell()
{
	this->ship_cell = nullptr;
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
	std::cout << unsigned(this->state) << "state of cell\n";
}

void FieldCell::OpenCellState()
{	
	std::cout << "abortishi";
	if (this->state != FieldCellState::Unknown)
	{	
		std::cout << "ashdkhaslkdh";
		return;
	}

	if (this->ship_cell)
	{	
		this->SetFieldCellState(FieldCellState::Ship);
		std::cout << "popa" << int(this->state) << '\n';
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

std::ostream &operator<<(std::ostream &os, const FieldCell &cell)
{
	std::string value;

	if (cell.state == FieldCellState::Unknown)
	{
		value = "〰️";
	}
	else if (cell.state == FieldCellState::Empty)
		value = "🟦";
	else if (cell.state == FieldCellState::Ship)
	{	
		auto state = cell.ship_cell->GetState();
		if (state == BattleshipCellState::Destroyed)
		{
			value = "🟥";
		}
		else if (state == BattleshipCellState::Damaged)
			value = "🟨";
		else
			value = "🟩";
	}
	os << value;
	return os;
}
