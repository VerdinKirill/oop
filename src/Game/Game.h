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
	virtual GameState getGameState() = 0;
	virtual void placeShips() = 0;
	virtual void process() = 0;
	virtual void load() = 0;
	virtual void save() = 0;
	virtual void start() = 0;
};

#endif