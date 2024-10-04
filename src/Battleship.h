#pragma once
#include <vector>
#include <memory>

#include "BattleshipCell.h"

enum class Direction{Up, Right, Down, Left};

class Battleship
{
public:
	Battleship(int length = 1, Direction direction = Direction::Up);
	void SetDirection(Direction direcrion);
	Direction GetDirection();
	unsigned char GetLength();
	std::shared_ptr<BattleshipCell> operator[](unsigned int index);

private:
	std::vector<BattleshipCell> battleship;
	unsigned char length;
	Direction direction;
};