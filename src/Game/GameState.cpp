#include "GameState.h"

Bot &GameState::getBot()
{
	return *this->bot;
}

void GameState::setGameComponents(std::unique_ptr<Bot> newBot, std::unique_ptr<User> newUser)
{
	bot = std::move(newBot);
	user = std::move(newUser);
}

User &GameState::getUser()
{
	return *this->user;
}

int GameState::getRounds()
{
	return this->countRounds;
}

int GameState::getMoves()
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
	Serialization seri(j);

	seri.to_json(state.getUser().getShipManager(), "playerShipManager");
	seri.to_json(state.getUser().getField(), "playerField");
	seri.to_json(state.getUser().getSkillManager(), "playerAbilityManager");
	seri.to_json(state.getBot().getShipManager(), "botShipManager");
	seri.to_json(state.getBot().getField(), "botField");
	j["currentDamage"] = state.getUser().getDamage();

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
	for (int y = 0; y < f.GetHeight(); y++)
	{
		for (int x = 0; x < f.GetWidth(); x++)
		{
			if (f[y][x].getIdBattleship() != -1 && f[y][x].isHeadBattleship())
			{
				auto &ship = sm.getBattleshipById(f[y][x].getIdBattleship());
				f.SetBattleship(x, y, ship, ship.GetDirection());
			}
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

	Deserialization deseri(j);
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

	connectShipManagerField(shipManager, field);

	deseri.from_json(enemyShipManager, "botShipManager");
	deseri.from_json(enemyField, "botField");
	connectShipManagerField(enemyShipManager, enemyField);

	// std::cout << field.GetWidth() << " " << field.GetHeight() << "width and height of loaded field\n";

	state.getUser().setShipManager(shipManager);
	state.getUser().setField(field);
	state.getUser().setSkillManager(skillManager);

	state.getBot().setShipManager(enemyShipManager);
	state.getBot().setField(enemyField);

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
