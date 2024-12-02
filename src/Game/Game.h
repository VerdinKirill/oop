#ifndef GAME_H
#define GAME_H
// #pragma once

#include "../Field.h"
#include "../ShipManager.h"
#include "../skills/SkillManager.h"
#include "GameState.h"
#include "../Players/Bot.h"
#include "../Players/User.h"

#include <fstream>

class GameState;

class Game
{	
	public: 
	// Game(int width, int height, int numberOfShips, std::vector<int> shipSizes);
	virtual GameState getGameState() = 0;
	virtual void placeShips() = 0;
	virtual void process() = 0;
	virtual void load(std::string fileName) = 0;
	virtual void save(std::string fileName) = 0;
	// virtual void move(int x, int y, bool isUseAbility) = 0;
	// virtual void placeShip(int index, int x, int y, Direction direction) = 0;
	// virtual void placeEnemyShips(int length, std::vector<int> sizes) = 0;
	virtual void start() = 0;
	// virtual void saveGame(std::string name) = 0;
	// virtual void loadGame(std::string name) = 0;
	// virtual Field& getPlayerField() = 0;
	// virtual Field& getEnemyField() = 0;
	// virtual SkillManager& getSkillManager();
	// virtual ShipManager& getPlayerShipManager() = 0;
	// virtual ShipManager& getEnemyShipManager() = 0;
	// virtual GameState& getGameState() = 0;

	

};

#endif