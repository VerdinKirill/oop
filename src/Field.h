#pragma once
#include "FieldCell.h"
#include "Battleship.h"
#include <cmath>
#include <sstream>
#include <iomanip>

struct Pos{
	int x;
	int y;
};

class Field{
	public:
	Field(int width, int heigth);
	Field(const Field& other_field);
	Field& operator=(const Field& other_field);
	void OpenField();
	void SetDoubleDamageFlag();
	void SetBattleship(int x, int y, Battleship& battleship, Direction direction);
	// void SetBattleship(char x, int y, std::shared_ptr<Battleship> battleship, Direction direction);
	void AttackCell(int x, int y);
	int GetWidth();
	int GetHeight();
	std::vector<FieldCell>& operator[](int index);
	std::string to_string();
	friend std::ostream &operator<<(std::ostream& os, Field& field);

	
	private:
	std::vector<std::vector<FieldCell> > field;
	int width;
	int height;
	bool double_damage_flag;
	const bool CheckPosBattleship(Battleship& battleship, int x, int y);
	const bool CheckPos(int x, int y);
	Pos GetTailPos(int x, int y, Battleship& battleship);
	void row_to_string(const std::vector<std::string>& row, const std::vector<size_t>& widths, std::stringstream& ss);
	void break_of_cells(const std::vector<size_t>& widths, std::stringstream& ss);
	void SetShipNear(int x, int y);
	std::vector<Pos> GetPosesOfShip(Battleship& Battleship, int x, int y);
};