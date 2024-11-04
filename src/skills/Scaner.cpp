#include "Scaner.h"

Scaner::Scaner(Field &field, Pos &pos)
{
	this->field = &field;
	this->pos = pos;
}

bool Scaner::use()
{
	Field &current_field = *field;
	int x = pos.x;
	int y = pos.y;
	int height = field->GetHeight();
	int width = field->GetWidth();
	if (current_field[y][x].isBattleshipCell() || (height > y + 1 && current_field[y + 1][x].isBattleshipCell())
	|| (width > x + 1 && current_field[x + 1][y].isBattleshipCell()) ||(width > x + 1 && height > y + 1 && current_field[y][x].isBattleshipCell()))
	{
		return true;
	}
	return false;
}
