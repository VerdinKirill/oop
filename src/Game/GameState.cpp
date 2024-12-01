#include "GameState.h"

GameState::GameState(Bot& bot, User& user, int& countRounds, int& countMoves) : bot(bot), user(user), countRounds(countRounds), countMoves(countMoves){};

Bot& GameState::getBot()
{
	return this->bot;
}

User& GameState::getUser()
{
	return this->user;
}

int& GameState::getRounds()
{
	return this->countRounds;
}

int& GameState::getMoves()
{
	return this->countMoves;
}

std::ostream &operator<<(std::ostream& os, GameState& state)
{
	state.getUser().getField().OpenField();
	auto skillVisitor = SkillPrinter();
	auto userField = state.getUser().getField().to_string();
	auto botField = state.getBot().getField().to_string();
	os  << "Your field:\n";
	os << userField << '\n';
	os << "Enemy Field:\n";
	os << botField << '\n';
	os << "Your skills\n";
	auto userSkillManager = state.getUser().getSkillManager();
	for (int i = 0; i < userSkillManager.size(); i++)
	{
		auto str = userSkillManager[i]->accept(&skillVisitor);
		os << i+1 << ". " << str << '\n'; 
	}
	return os;
}

