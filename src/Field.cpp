#include "Field.h"

Field::Field(int width, int height)
{
	this->field = std::vector(height, std::vector<FieldCell>(width, FieldCell()));
	this->width = width;
	this->height = height;
	this->double_damage_flag = false;
}


Pos Field::GetTailPos(int x, int y, Battleship&  battleship)
{
	auto direction = battleship.GetDirection();
	auto length = battleship.GetLength();
	int x_tail = (direction == Direction::Right) ? x + int(length) - 1 : (direction == Direction::Left) ? x - int(length) + 1: x;
	int y_tail = (direction == Direction::Up) ? y + int(length) - 1 : (direction == Direction::Down) ? y - int(length) + 1: y;
	return {x_tail, y_tail};
}

const bool Field::CheckPos(int x, int y)
{
	int field_width = this->GetWidth();
	int field_heigth = this->GetHeight();
	if (x >= field_width && x < 0 && y >= field_heigth && y < 0)
		return false;
	return true;
}

const bool Field::CheckPosBattleship(Battleship& battleship, int x, int y)
{
	Pos pos_tail = this->GetTailPos(x, y, battleship);
	if (this->CheckPos(x, y) && this->CheckPos(pos_tail.x, pos_tail.y))
	{
		return true;
	}
	return false;
}

int Field::GetWidth()
{
	return width;
}
int Field::GetHeight()
{
	return height;
}

void Field::SetShipNear(int x, int y)
{
	this->field[y][x].SetNearWithShip();
	if (x>0)
	{
		this->field[y][x-1].SetNearWithShip();
		if (y>0)
			this->field[y-1][x-1].SetNearWithShip();
		if (y<height-1)
			this->field[y+1][x-1].SetNearWithShip();
	}
	if (x < width-1)
	{
		this->field[y][x+1].SetNearWithShip();
		if (y>0)
			this->field[y-1][x+1].SetNearWithShip();
		if (y<height-1)
			this->field[y+1][x+1].SetNearWithShip();

	}
	if (y>0)
		this->field[y-1][x].SetNearWithShip();
	if (y < height-1)
		this->field[y+1][x].SetNearWithShip();
}

std::vector<Pos> Field::GetPosesOfShip(Battleship& battleship, int x, int y)
{
	std::vector<Pos> positions;
	Pos pos_tail = this->GetTailPos(x, y, battleship);
	int x_step = (x < pos_tail.x) ? 1 : (x == pos_tail.x) ? 0: -1;
	int y_step = (y < pos_tail.y) ? 1 : (y == pos_tail.y) ? 0: -1;
	int j = y;
	int i = x;
	while(j != pos_tail.y+y_step || i != pos_tail.x + x_step)
	{
		positions.push_back({i, j});
		i += x_step;
		j += y_step;
	}
	return positions;
}

void Field::SetBattleship(int x, int y, Battleship& battleship, Direction direction)
{
	battleship.SetDirection(direction);
	if (!this->CheckPosBattleship(battleship, x, y))
		return;
	// std:: cout << int(battleship.GetLength());
	auto positions = GetPosesOfShip(battleship, x, y);
	int count = 0;
	for (auto pos : positions)
	{	
		// std::cout << '\n' << pos.x << " " << pos.y << '\n';
		if (this->field[pos.y][pos.x].IsNearWithShip())
		{
			std::cout << "You tried set the ship with length " << int(battleship.GetLength()) << " near with other on coordinates x: " << pos.x << " y: " << pos.y << "!\n";
			return;
		}
		this->field[pos.y][pos.x].SetShipCell(battleship[count++]);
	}
	for (auto pos: positions)
	{
		SetShipNear(pos.x, pos.y);
	}
}

SkillResultInfoHolder& Field::AttackCell(int x, int y, std::optional<SkillResultInfoHolder*> skill_result)
{	
	auto skill_result_new = new SkillResultInfoHolder();
	auto pos = Pos{x, y};
	skill_result_new->set_pos(pos);
	if (!this->CheckPos(x, y))
		return *skill_result_new;
	
	auto cell = &field[y][x];
	cell->OpenCellState();
	if (!cell->isBattleshipCell())
		return *skill_result_new;

	bool is_destroyed = false;
	int curent_damage = 1;

	if (skill_result.has_value())
		curent_damage = skill_result.value()->get_damage();

	for (int i = 0; i<curent_damage && is_destroyed == false; i++)
	{
		is_destroyed = cell->AttackCell();
	}
	skill_result_new->set_is_battleship_cell(true);
	skill_result_new->set_is_battleship_destroyed(is_destroyed);
	return *skill_result_new;
}

std::vector<FieldCell> &Field::operator[](int index)
{
	return field[index];
}

Field::Field(const Field &other_field) : field(*(&other_field.field)), width(other_field.width), height(other_field.height) {}

Field &Field::operator=(const Field &other_field)
{
	Field temp(other_field);
	auto new_field = &(other_field.field);
	field = *(new_field);
	return *this;
}

void Field::row_to_string(const std::vector<std::string>& row, const std::vector<size_t>& widths, std::stringstream& ss)
{
	ss << "|";
	for (size_t i = 0; i < row.size(); i++)
	{
		ss << ' ';
		ss.width(widths[i]);
		// std::cout << widths[i];
		ss << row[i] << " |";
	}
	ss << '\n';
}

void Field::break_of_cells(const std::vector<size_t>& widths, std::stringstream& ss)
{
	const size_t margin = 1;
	ss.put('+').fill('-');
	for (size_t w : widths)
	{
		ss.width(w + 2*margin);
		ss << '-' << '+';
	}
	ss.put('\n').fill(' ');
}

std::string Field::to_string()
{	
	// std::cout << "HI!";
	std::vector<std::string> field_headers = {""};
	std::stringstream ss;
	ss.setf(std::ios::left, std::ios::adjustfield); 
	auto widths = std::vector(width+1, std::size_t(0));
	for (size_t x = 0; x<width; x++)
	{
		// ss << std::setw(width_symbol) << char(96+x);
		field_headers.push_back(std::string(1, char(97+x)));
	}
	auto table_body = std::vector(height, std::vector(width+1, std::string("")));
	for (size_t y = 0; y<height; y++)
	{	
		table_body[y][0] = std::to_string(y+1);
		for (size_t x = 0; x<width; x++)
		{	
			table_body[y][x+1] = field[y][x].to_string();
			// ss.width(10);
		}
	}
	for (auto row: table_body){
		for (size_t i = 0; i < row.size(); i++)
		{
			widths[i] = std::max(widths[i], row[i].length()/2);
		}
	}
	widths[0]*=2;
	break_of_cells(widths, ss);
	row_to_string(field_headers, widths, ss);
	break_of_cells(widths, ss);
	for (auto row: table_body)
	{
		row_to_string(row, widths, ss);
		break_of_cells(widths, ss);
	}
	// break_of_cells(widths, ss);
	return ss.str();
}


std::ostream &operator<<(std::ostream& os, Field& field)
{	
	auto ss = field.to_string();
	os << ss;
	return os;
}

void Field::OpenField()
{
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			field[y][x].OpenCellState();
			// std::cout << int(field[y][x].GetFieldState());
		}
	}
}

void Field::SetDoubleDamageFlag()
{
	this->double_damage_flag = true;
}