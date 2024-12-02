#ifndef BOT_H
#define BOT_H

#include "Player.h"
#include "../InfoHolders/commandHolder.h"
#include "../Game/Game.h"
#include "../Utils/Randomizer.h"



class Bot : public Player {
	private:
	Field* field;
	ShipManager* shipManager;
	std::vector <std::pair<int, int>> availableMoves;
	int damage;

	public:
	Bot (int width, int height, int numShips4, int numShips3, int numShips2, int numShips1);
	Bot(Bot* bot);
	~Bot();
	Action move(Player& player) override;
	Field& getField() override;
	void placeShips() override;
	void setField(Field& f);
	void setShipManager(ShipManager& sm);
	ShipManager& getShipManager() override;
	// bool attack(Player& player, int x, int y);


};

#endif
