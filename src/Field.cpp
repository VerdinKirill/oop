#include "Field.h"

Field::Field(int width, int heigth)
{
	this->field = std::vector(heigth, std::vector<FieldCell>(width, FieldCell()));
}

	
Pos Field::GetTailPos(int x, int y, std::shared_ptr<Battleship> battleship)
{
	auto direction = battleship->GetDirection();
	auto length = battleship->GetLength();
	int x_tail = (direction == Direction::Right) ? x + length : (direction == Direction::Left) ? x - length: x;
	int y_tail = (direction == Direction::Up) ? y + length : (direction == Direction::Down) ? y - length: y;
	return {x_tail, y_tail};
}


const bool Field::CheckPos(int x, int y)
{
	int field_width = this->getWidth();
	int field_heigth = this->getHeight();
	if (x >= field_width && x < 0 && y >= field_heigth && y < 0)
		return false;
	return true;
}

const bool Field::CheckPosBattleship(std::shared_ptr<Battleship> battleship, int x, int y)
{
	Pos pos_tail = this->GetTailPos(x, y, battleship);
	if (this->CheckPos(x, y) && this->CheckPos(pos_tail.x, pos_tail.y));
		return true;
	return false;
}

int Field::getWidth()
{
	return this->field[0].size();
}
int Field::getHeight()
{
	return this->field.size();
}

void Field::SetBattleship(int x, int y, std::shared_ptr<Battleship> battleship, Direction direction)
{
	if (!this->CheckPosBattleship(battleship, x, y))
		return;
	Pos pos_tail = this->GetTailPos(x, y, battleship);
	int x_step = (x < pos_tail.x) ? 1 : (x_step == pos_tail.x) ? 0 : -1;
	int y_step = (y < pos_tail.y) ? 1 : (y_step == pos_tail.y) ? 0 : -1;
	for (int j = y; j!=pos_tail.y+y_step; j+= y_step)
	{
		for(int i = x;i!=pos_tail.x+x_step; i+=x_step)
		{
			this->field[j][i].SetShipCell((*battleship)[abs(y-j)]);
		}
	}
}

void Field::AttackCell(int x, int y)
{
	if (!this->CheckPos(x, y)) return;
	auto cell = this->field[y][x];
	if (cell.GetFieldState() == FieldCellState::Unknown)
		cell.OpenCellState();
	if (cell.GetFieldState() == FieldCellState::Ship)
		cell.AttackCell();
}
