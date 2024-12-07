#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../skills/SkillPrinter.h"
#include "../Players/Bot.h"
#include "../Players/User.h"
#include "../FileWork/FileWrapper.h"
#include "../libraries/json.hpp"
#include "../FileWork/Serialization.h"
#include "../FileWork/Deserialization.h"
#include "../Exceptions/ModifiedJsonException.h"
class Bot;
class User;

class GameState
{
	Bot& bot;
	User& user;
	int &countRounds;
	int &countMoves;

public:
	GameState(User& user, Bot& bot, int& countRounds, int& countMoves) :user(user), bot(bot), countRounds(countRounds), countMoves(countMoves){};
	Bot &getBot();
	User &getUser();
	int& getRounds();
	int& getMoves();
	std::string getHash(std::string data);
	void setBot(Bot &bot);
	void setUser(User& user);
	void setMoves(int& moves);
	void setRounds(int& rounds);
	void setGameComponents(std::unique_ptr<Bot> newBot, std::unique_ptr<User> newUser);
	friend std::ostream &operator<<(std::ostream &os, GameState &game);
	friend FileWrapper &operator<<(FileWrapper &fileWrapper, GameState &state);
	GameState &loadGame(const std::string fileName);
	void saveGame(const std::string fileName);
};

#endif