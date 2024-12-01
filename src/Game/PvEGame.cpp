#include "PvEGame.h"

PvEGame::PvEGame() {
	this->countMoves = 0;
	this->countRounds = 1;

}

void PvEGame::start()
{
	auto coordHolder = CoordHolder();
	std::cout << "Введите размер поля через пробел\n";
	coordHolder.read();
	auto coords = coordHolder.getCoords();
	std::vector<int> lengths;
	int length;
	for (int i = 1; i < 5; i++)
	{
		std::cout << "Введите количество кораблей длины " << i << " \n";
		std::cin >> length;
		lengths.push_back(length);
	}
	this->bot = new Bot(coords.first, coords.second, lengths[3], lengths[2], lengths[1], lengths[0]);
	this->user = new User(coords.first, coords.second, lengths[3], lengths[2], lengths[1], lengths[0]);
	this->state = new GameState(*(this->bot), *this->user, this->countRounds, this->countMoves);
	this->placeShips();
	this->process();
}

void PvEGame::placeShips()
{
	this->bot->placeShips();
	this->user->placeShips();
}

void PvEGame::process()
{	
	while (!this->user->getShipManager().isDefeated())
	{
		countMoves++;
		if (countMoves%2)
		{
			this->currentPlayer = this->user;
			this->currentEnemy = this->bot;
		}
		else
		{
			this->currentPlayer = this->bot;
			this->currentEnemy = this->user;
		}
		this->currentPlayer->move(*(this->currentEnemy));
		if (this->bot->getShipManager().isDefeated())
		this->bot = new Bot(*bot);
		std::cout << *state;
	}
	std::cout << "you lose:(\n" ;
}

GameState& PvEGame:: getGameState()
{
	return *(this->state);
}

// void PvEGame::move(int x, int y, bool isUseAbility)
// {
// 	if (isUseAbility)
// 	{
// 		state->useSkill();
// 	}
// 	auto coords = CoordHolder();
// 	coords.read();
// 	auto coord = coords.getCoords();
// 	state->attack(coord.first, coord.second);
// 	this->countMoves += 1;
// 	state = this->stateFactory->getState();
// }

// Field& PvEGame::getPlayerField (){
// 	return playerField;
// }
// Field& PvEGame::getEnemyField(){
// 	return enemyField;
// }

// ShipManager& PvEGame:: getPlayerShipManager()
// {
// 	return playerShipManager;
// }

// ShipManager& PvEGame::getEnemyShipManager()
// {
// 	return enemyShipManager;
// }

// GameState& PvEGame::getGameState(){
// 	return *state;
// }


// SkillManager& PvEGame::getSkillManager()
// {
// 	return skillManager;
// }
