#include "PvEGame.h"



void PvEGame::start()
{
	this->placeShips();
	this->process();
}

void PvEGame::placeShips()
{
	this->bot.placeShips();
	this->user.placeShips();
}

void PvEGame::process()
{
	while (!this->user.getShipManager().isDefeated())
	{
		auto state = this->getGameState();
		std::cout << state << '\n';
		if (countMoves % 2)
		{
			this->currentPlayer = &user;
			this->currentEnemy = &bot;
		}
		else
		{
			this->currentPlayer = &bot;
			this->currentEnemy = &user;
		}

		try
		{
			auto action = this->currentPlayer->move(*(this->currentEnemy));
			if (action == Action::Save)
			{
				this->save();
				continue;
			}
			if (action == Action::Load)
			{
				this->load();
				auto state = this->getGameState();
				std::cout << state;
				std::cout << "Игра была успешно загружена!";
				continue;
			}
		}
		catch (std::exception &error)
		{
			countMoves--;
			std::cout << error.what();
		}
		if (this->bot.getShipManager().isDefeated())
		{
			auto field = this->bot.getField();
			auto sm = this->bot.getShipManager();
			this->bot = Bot(field.GetWidth(), field.GetHeight(), sm.getNum4Length(), sm.getNum3Length(), sm.getNum2Length(), sm.getNum1Length());
			this->state.getBot() = this->bot;
			this->bot.placeShips();
			this->countRounds++;
		}
		countMoves++;
	}
	std::cout << "you lose:(\n";
}

GameState PvEGame::getGameState()
{
	return this->state;
}

void PvEGame::load()
{	
	try
	{
		gameSaver.load(state);
	}
	catch (nlohmann::json::exception &e)
	{
		std::cerr << "Error parsing JSON: " << e.what() << std::endl;
		return;
	}

	// }
}

void PvEGame::save()
{
	gameSaver.save(state);
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
