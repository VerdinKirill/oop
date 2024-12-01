#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "../Field.h"
#include "../ShipManager.h"

class Player
{

public:
	// virtual bool attack(Player& player, int x, int y) = 0;


	virtual void move(Player& player) = 0;

	virtual void placeShips() = 0;
	// virtual void useSkill() = 0;

	~Player() = default;

	virtual Field& getField() = 0;
	virtual ShipManager& getShipManager() = 0;

};

#endif