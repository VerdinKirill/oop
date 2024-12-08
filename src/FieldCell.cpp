#include "FieldCell.h"

FieldCell::FieldCell()
{
	this->ship_cell = nullptr;
	this->near_with_ship = false;
	this->state = FieldCellState::Unknown;
}

FieldCell::FieldCell(BattleshipCell &ship_cell)
{
	SetShipCell(ship_cell);
}
void FieldCell::SetShipCell(BattleshipCell &ship_cell)
{
	this->ship_cell = &ship_cell;
}

void FieldCell::SetFieldCellState(FieldCellState state)
{
	this->state = state;
}

void FieldCell::OpenCellState()
{
	if (this->ship_cell)
	{
		if (ship_cell->GetState() == BattleshipCellState::Unbroken)
			this->SetFieldCellState(FieldCellState::Ship2);
		if (ship_cell->GetState() == BattleshipCellState::Damaged)
			this->SetFieldCellState(FieldCellState::Ship1);
		if (ship_cell->GetState() == BattleshipCellState::Destroyed)
			this->SetFieldCellState(FieldCellState::Ship0);
	}
	else
		this->SetFieldCellState(FieldCellState::Empty);
}

const FieldCellState FieldCell::GetFieldState()
{
	return this->state;
}

bool FieldCell::AttackCell(int damage)
{
	if (this->ship_cell)
	{
		auto result = this->ship_cell->AttackBattleshipCell(damage);
		this->OpenCellState();
		return result;
	}
	return false;
}

int FieldCell::getIdBattleship()
{
	if (this->isBattleshipCell())
	{
		return this->ship_cell->getBattleshipId();
	}
	return -1;
}

void FieldCell::setIdBattleship(int id)
{
	this->battleshipId = id;
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
	else if (state == FieldCellState::Ship2)
	{
		value = "🟩";
	}
	else if (state == FieldCellState::Ship1)
	{
		value = "🟨";
	}
	else
	{
		value = "🟥";
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

bool FieldCell::isBattleshipCell()
{
	if (ship_cell == nullptr)
		return false;
	return true;
}

bool FieldCell::isHeadBattleship(bool i)
{
	if (!i)
	{
		if (this->isBattleshipCell())
		{
			return this->ship_cell->getIsHead();
		}
		else
		{
			return false;
		}
	}
	else
	{
		return this->isHead;
	}
}

void FieldCell::setIsHead(bool isHead)
{
	this->isHead = isHead;
}

void FieldCell::setBattleshipCell(BattleshipCell& cell)
{
	this->ship_cell = &cell;
}

