#ifndef GAMESTATE_H
#define GAMESTATE_H



#include "../skills/SkillPrinter.h"
#include "../Players/Bot.h"
#include "../Players/User.h"

class Bot;
class User;



class GameState {
	Bot& bot;
	User& user;
	int countRounds;
	int countMoves;

	public:
		GameState(Bot& bot, User& user, int& countRounds, int& countMoves);
		Bot& getBot();
		User& getUser();
		int& getRounds();
		int& getMoves();
		friend std::ostream &operator<<(std::ostream& os, GameState& game);


};

#endif