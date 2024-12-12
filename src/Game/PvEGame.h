#ifndef PVEGAME_H
#define PVEGAME_H


#include "Game.h"
#include "../Players/User.h"
#include "../Players/Bot.h"
#include "../Players/Player.h"
#include <string>
#include "GameState.h"
#include "GameSaver.h"

class PvEGame : public Game {

	User& user;
	Bot& bot;
	GameState& state;
	Player* currentPlayer;
	Player* currentEnemy;
	int& countMoves;
	int& countRounds;
	GameSaver gameSaver;

	public:
	PvEGame(User& user, Bot& bot, GameState& state, std::string fileName): user(user), bot(bot), state(state), countMoves(state.getMoves()), countRounds(state.getRounds()), gameSaver(fileName){};
	// PvEGame(int width, int height, int numLength4, int numLength3, int numLength2, int numLength1);
	void start () override;
	void placeShips() override;
	void process() override;
	void load()override;
	void save() override;

	GameState getGameState() override;
};

#endif