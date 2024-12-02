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
	Battleship(BattleshipLength length, Direction direction, int id);
	void SetDirection(Direction direcrion);
	Direction GetDirection();
	BattleshipLength GetLength();
	BattleshipCell& operator[](unsigned int index);
	bool isDestroyed();
	int getId();
	

private:
	int id;
	std::vector<BattleshipCell> battleship;
	Direction direction;
	BattleshipLength length;
};

#endif