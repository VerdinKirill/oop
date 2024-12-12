#include "GameSaver.h"

void GameSaver::save(const GameState& state)
{
	FileWrapper fileWrapper(this->fileName);
	fileWrapper << const_cast<GameState&>(state);
}

void GameSaver::load(GameState& state)
{
	FileWrapper fileWrapper(this->fileName);
	fileWrapper >> state;
}