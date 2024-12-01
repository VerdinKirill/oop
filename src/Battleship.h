#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <vector>
#include <memory>

#include "BattleshipCell.h"
class BattleshipCell;



enum  BattleshipLength{Cell1 = 1, Cell2 = 2, Cell3 = 3, Cell4 = 4};
enum Direction{Up, Right, Down, Left};

class Battleship
{
public:
	Battleship(BattleshipLength length =  BattleshipLength::Cell1, Direction direction = Direction::Up);
	void SetDirection(Direction direcrion);
	Direction GetDirection();
	BattleshipLength GetLength();
	BattleshipCell& operator[](unsigned int index);
	bool isDestroyed();
	

private:
	std::vector<BattleshipCell> battleship;
	Direction direction;
	BattleshipLength length;
};

#endif