#pragma once
#include "FieldCell.h"
#include "Battleship.h"
#include <cmath>
struct Pos{
	int x;
	int y;
};

class Field{
	public:
	Field(int width, int heigth);
	~Field();
	void SetBattleship(int x, int y, std::shared_ptr<Battleship> battleship, Direction direction);
	// void SetBattleship(char x, int y, std::shared_ptr<Battleship> battleship, Direction direction);
	void AttackCell(int x, int y);
	int GetWidth();
	int GetHeight();
	std::vector<FieldCell>& operator[](int index);
	
	private:
	const bool CheckPosBattleship(std::shared_ptr<Battleship> battleship, int x, int y);
	std::vector<std::vector<FieldCell>> field;
	const bool CheckPos(int x, int y);
	Pos GetTailPos(int x, int y, std::shared_ptr<Battleship> battleship);

};