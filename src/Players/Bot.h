#ifndef BOT_H
#define BOT_H

#include "Player.h"
#include "../InfoHolders/commandHolder.h"
#include "../Game/Game.h"
#include "../Utils/Randomizer.h"



class Bot : public Player {
	private:
	Field field;
	ShipManager shipManager;
	std::vector <std::pair<int, int>> availableMoves;
	int damage;

	public:
	Bot (int width, int height, int numShips4, int numShips3, int numShips2, int numShips1);
	Bot(const Bot& other): field(other.field), shipManager(other.shipManager), damage(other.damage){};
	Bot& operator=(const Bot& other)
	{
		if (this != &other)
		{
			this->field = other.field;
			this->shipManager = other.shipManager;
			this->damage = other.damage;
		}
		return *this;
	}
	Bot();
	~Bot();
	Action move(Player& player) override;
	Field& getField() override;
	void placeShips() override;
	ShipManager& getShipManager() override;
	// bool attack(Player& player, int x, int y);


};

#endif
