#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../skills/SkillPrinter.h"
#include "../Players/Bot.h"
#include "../Players/User.h"
#include "../FileWork/FileWrapper.h"
#include "../libraries/json.hpp"
#include "../FileWork/Serialization.h"
#include "../FileWork/Deserialization.h"

class Bot;
class User;

class GameState
{
	std::unique_ptr<Bot> bot;
	std::unique_ptr<User> user;
	int &countRounds;
	int &countMoves;

public:
	GameState(std::unique_ptr<Bot> bot, std::unique_ptr<User> user, int &countRounds, int &countMoves)
		: bot(std::move(bot)), user(std::move(user)), countRounds(countRounds), countMoves(countMoves) {}
	Bot &getBot();
	User &getUser();
	int getRounds();
	int getMoves();
	void setBot(Bot &bot);
	void setGameComponents(std::unique_ptr<Bot> newBot, std::unique_ptr<User> newUser);
	friend std::ostream &operator<<(std::ostream &os, GameState &game);
	friend FileWrapper &operator<<(FileWrapper &fileWrapper, GameState &state);
	GameState &loadGame(const std::string fileName);
	void saveGame(const std::string fileName);
};

#endif