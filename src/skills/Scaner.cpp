#include "Scaner.h"

Scaner::Scaner(Field &field, std::pair<int, int> pos)
{
	this->field = &field;
	this->pos = pos;
}

SkillResultInfoHolder &Scaner::use()
{	
	Field current_field = *field;
	auto skill_result = new SkillResultInfoHolder();
	skill_result->set_pos(this->pos);
	int x = pos.first;
	int y = pos.second;
	int height = current_field.GetHeight();
	int width = current_field.GetWidth();
	if (current_field[y][x].isBattleshipCell() || (height > y + 1 && current_field[y + 1][x].isBattleshipCell()) || (width > x + 1 && current_field[y][x + 1].isBattleshipCell()) || (width > x + 1 && height > y + 1 && current_field[y + 1][x + 1].isBattleshipCell()))
	{
		skill_result->set_is_battleship_cell(true);
	}
	return *skill_result;
}
