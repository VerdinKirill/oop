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
	std::string filename = "/Users/kirillverdin/programming/oop/File.json";
	std::cout << "Ваш текущий урон: "<<this->user.getDamage() << '\n';
	while (!this->user.getShipManager().isDefeated())
	{
		std::cout << countMoves << " move\n";
		auto state = this->getGameState();
		std::cout << state;
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
				this->save(filename);
				continue;
			}
			if (action == Action::Load)
			{
				this->load(filename);
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
			this->state.setBot(this->bot);
			// this->bot = std::make_unique<Bot>(field.GetWidth(), field.GetHeight(), sm.getNum4Length(), sm.getNum3Length(), sm.getNum2Length(), sm.getNum1Length());
			this->bot.placeShips();
			std::cout << "yo\n";
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

void PvEGame::load(std::string filename)
{	
	auto state = this->getGameState();
	try
	{
		state.loadGame(filename);
	}
	catch (nlohmann::json::exception &e)
	{
		std::cerr << "Error parsing JSON: " << e.what() << std::endl;
		return;
	}
	// this->bot = std::make_unique<Bot>(state.getBot());
	// this->user = std::make_unique<User>(state.getUser());
	// std::cout << "ya user\n";

	// this->countMoves = state.getMoves();
	// this->countRounds = state.getRounds();
	// std::cout << "uoflskdakdpakd;ojfdajkf\n";
	// if (countMoves % 2)
	// {
	// 	this->currentPlayer = user.get();
	// 	this->currentEnemy = bot.get();
	// }
	// else
	// {
	// 	this->currentPlayer = bot.get();
	// 	this->currentEnemy = user.get();
	// }
}

void PvEGame::save(std::string filename)
{
	auto state = this->getGameState();
	state.saveGame(filename);
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
