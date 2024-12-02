#ifndef PVEGAME_H
#define PVEGAME_H


#include "Game.h"
#include "../Players/User.h"
#include "../Players/Bot.h"
#include "../Players/Player.h"
#include <string>
// #include "GameState.h"

class PvEGame : public Game {

	std::unique_ptr<User> user;
	std::unique_ptr<Bot> bot;
	Player* currentPlayer;
	Player* currentEnemy;
	GameState* state;
	int countMoves;
	int countRounds;

	public:
	PvEGame();
	// PvEGame(int width, int height, int numLength4, int numLength3, int numLength2, int numLength1);
	void start () override;
	void placeShips() override;
	void process() override;
	void load(std::string fileName)override;
	void save(std::string fileName) override;
	void setBot(Bot* bot);
	void setUser(User* user);



	// void placeShip (int index, int x, int y, Direction direction) override;
	// void placeEnemyShips(int length, std::vector<int> sizes) override;
	// void saveGame(std::string name) override;
	// void loadGame(std::string name) override;

	GameState getGameState() override;
};

#endif