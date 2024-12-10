#include "GameState.h"

std::string GameState::getHash(std::string data)
{
	std::hash<std::string> hash_fn;
	size_t hash = hash_fn(data);
	std::stringstream ss;
	ss << std::hex << hash;
	return ss.str();
}

Bot &GameState::getBot()
{
	return this->bot;
}

User &GameState::getUser()
{
	return this->user;
}

int &GameState::getRounds()
{
	return this->countRounds;
}

int &GameState::getMoves()
{
	return this->countMoves;
}

std::ostream &operator<<(std::ostream &os, GameState &state)
{
	state.getUser().getField().OpenField();
	auto skillVisitor = SkillPrinter();
	auto userField = state.getUser().getField().to_string();
	auto botField = state.getBot().getField().to_string();
	os << "----------------------------------------------------------------------------------\n";
	os << "Раунд" << state.getRounds() << '\n';
	os << "Ваше поле\n";
	os << userField << '\n';
	os << "Поле противника:\n";
	os << botField << '\n';
	os << "Ваши способности\n";
	auto userSkillManager = state.getUser().getSkillManager();
	if (userSkillManager.size() == 0)
	{
		os << "Отсутсвуют\n";
	}
	for (int i = 0; i < userSkillManager.size(); i++)
	{
		auto str = userSkillManager[i]->accept(&skillVisitor);
		os << i + 1 << ". " << str << '\n';
	}
	os << "----------------------------------------------------------------------------------\n";
	return os;
}

FileWrapper &operator<<(FileWrapper &fileWrapper, GameState &state)
{
	nlohmann::json j;
	nlohmann::json data;
	Serialization seri(data);

	seri.to_json(state.getUser().getShipManager(), "playerShipManager");
	seri.to_json(state.getUser().getField(), "playerField");
	seri.to_json(state.getUser().getSkillManager(), "playerAbilityManager");
	seri.to_json(state.getBot().getShipManager(), "botShipManager");
	seri.to_json(state.getBot().getField(), "botField");
	data["currentDamage"] = state.getUser().getDamage();
	j["data"] = data;
	std::string jsonString = data.dump();
	j["hash"] =  state.getHash(jsonString);

	try
	{
		fileWrapper.write(j);
	}
	catch (UnableOpenFileException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return fileWrapper;
}

void connectShipManagerField(ShipManager &sm, Field &f)
{	
	for (int i = 0; i < sm.GetNumberBattleships(); i++)
	{	
		auto& battleship = sm[i];
		for (int j = 0; j < battleship.GetLength(); j++)
		{	
			auto& cell = battleship[j];
			auto coordinates = cell.getCoordinates();
			f[coordinates.first][coordinates.second].setBattleshipCell(cell);
		}
	}
}
FileWrapper &operator>>(FileWrapper &fileWrapper, GameState &state)
{
	nlohmann::json j;

	try
	{
		fileWrapper.read(j);
	}
	catch (UnableOpenFileException &e)
	{
		std::cerr << e.what() << std::endl;
		return fileWrapper;
	}
	auto data = j["data"];
	std::string hashValue = j["hash"];

	std::string jsonString = data.dump();
	if (hashValue != state.getHash(jsonString))
	{	
		throw ModifiedJsonException("");
	}

	Deserialization deseri(data);
	ShipManager shipManager;
	Field field;
	SkillManager skillManager;

	ShipManager enemyShipManager;
	Field enemyField;

	deseri.from_json(shipManager, "playerShipManager");
	deseri.from_json(field, "playerField");
	deseri.from_json(skillManager, "playerAbilityManager");
	connectShipManagerField(shipManager, field);

	deseri.from_json(enemyShipManager, "botShipManager");
	deseri.from_json(enemyField, "botField");
	connectShipManagerField(enemyShipManager, enemyField);

	state.getUser().getShipManager() = shipManager;
	state.getUser().getSkillManager() = skillManager;
	state.getUser().getField() = field;

	state.getBot().getShipManager() = enemyShipManager;
	state.getBot().getField() = enemyField;

	return fileWrapper;
}

void GameState::saveGame(const std::string fileName)
{
	FileWrapper wrapper(fileName);
	wrapper << *this;
}

GameState &GameState::loadGame(const std::string fileName)
{
	// std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::trunc);
	FileWrapper fileWrapper(fileName);
	fileWrapper >> *this;
	return *this;
}
