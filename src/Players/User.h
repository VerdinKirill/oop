#ifndef USER_H
#define USER_H


#include "Player.h"
#include "../InfoHolders/commandHolder.h"
#include "../InfoHolders/directionHolder.h"
#include "../skills/SkillManager.h"
#include <iostream>



class User : public Player
{
private:
	Field* field;
	ShipManager* shipManager;
	SkillManager* skillManager;
	int damage;

public:
	User(int width, int height, int numShips4, int numShips3, int numShips2, int numShips1);
	void move(Player &player) override;
	void placeShips() override;

	bool attack(Player &player, int x, int y);

	bool useSkill(Player &player);
	Field& getField() override;
	ShipManager& getShipManager() override;
	SkillManager& getSkillManager();

};

#endif
