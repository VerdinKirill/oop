#pragma once
#include <vector>
#include <memory>

#include "BattleshipCell.h"
enum class BattleshipLength{Cell1 = 1, Cell2, Cell3, Cell4};
enum class Direction{Up, Right, Down, Left};

class Battleship
{
public:
	Battleship(BattleshipLength length =  BattleshipLength::Cell1, Direction direction = Direction::Up);
	void SetDirection(Direction direcrion);
	Direction GetDirection();
	BattleshipLength GetLength();
	std::shared_ptr<BattleshipCell> operator[](unsigned int index);

private:
	std::vector<BattleshipCell> battleship;
	BattleshipLength length;
	Direction direction;
};