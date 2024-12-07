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
	os << "Раунд" << state.getRounds() << '\n';
	os << "Ваше поле\n";
	os << userField << '\n';
	os << "Поле противника:\n";
	os << botField << '\n';
	os << "Ваши способности\n";
	auto userSkillManager = state.getUser().getSkillManager();
	std::cout << "Количество способностей " << userSkillManager.size() << '\n';
	if (userSkillManager.size() == 0)
	{
		os << "Отсутсвуют\n";
	}
	for (int i = 0; i < userSkillManager.size(); i++)
	{
		auto str = userSkillManager[i]->accept(&skillVisitor);
		os << i + 1 << ". " << str << '\n';
	}
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
	std::cout << sm.GetNumberBattleships() << "battleships\n";
	for (int i = 0; i < sm.GetNumberBattleships(); i++)
	{	
		std::cout << i <<" i\n";
		auto& battleship = sm[i];
		std::cout << battleship.getId() << "id of battleship\n";
		for (int j = 0; j < battleship.GetLength(); j++)
		{	
			auto& cell = battleship[j];
			std::cout << cell.GetState() << "state\n";
			std::cout << j << " j\n";
			auto coordinates = cell.getCoordinates();
			f[coordinates.first][coordinates.second].setBattleshipCell(cell);
			std::cout << "pasted shipcell into ship" << coordinates.first << " " << coordinates.second << '\n';
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
		std::cout << hashValue << " " << state.getHash(jsonString) << "\n"; 
		throw ModifiedJsonException("");
	}

	Deserialization deseri(data);
	ShipManager shipManager;
	Field field;
	SkillManager skillManager;

	ShipManager enemyShipManager;
	Field enemyField;

	deseri.from_json(shipManager, "playerShipManager");
	std::cout << "ya tut load shipmanager\n";
	deseri.from_json(field, "playerField");
	std::cout << "ya tut load playerField\n";

	deseri.from_json(skillManager, "playerAbilityManager");
	std::cout << "ya tut load playerAvilityManager\n";
	std::cout << field.GetHeight() << field.GetWidth() << '\n';
	connectShipManagerField(shipManager, field);
	std::cout << field.GetHeight() << field.GetWidth() << '\n';
	deseri.from_json(enemyShipManager, "botShipManager");
	deseri.from_json(enemyField, "botField");
	connectShipManagerField(enemyShipManager, enemyField);

	// std::cout << field.GetWidth() << " " << field.GetHeight() << "width and height of loaded field\n";
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
	std::cout << "IM HEAR\n";
}

void GameState::setBot(Bot &bot)
{
	this->bot = bot;
}

void GameState::setMoves(int &moves)
{
	this->countMoves = moves;
}

void GameState::setRounds(int &rounds)
{
	this->countRounds = rounds;
}

void GameState::setUser(User &user)
{
	this->user = user;
}
