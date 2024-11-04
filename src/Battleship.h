#pragma once
#include <vector>
#include <memory>

#include "BattleshipCell.h"
enum  BattleshipLength{Cell1 = 1, Cell2, Cell3, Cell4};
enum Direction{Up, Right, Down, Left};

class Battleship
{
public:
	Battleship(BattleshipLength length =  BattleshipLength::Cell1, Direction direction = Direction::Up);
	void SetDirection(Direction direcrion);
	Direction GetDirection();
	int GetLength();
	BattleshipCell& operator[](unsigned int index);
	

private:
	std::vector<BattleshipCell> battleship;
	Direction direction;
};