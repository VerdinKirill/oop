#include "User.h"

User::User(int width, int height, int numShips4, int numShips3, int numShips2, int numShips1)
{
	this->field = Field(width, height);
	this->skillManager = SkillManager();
	this->shipManager = ShipManager(numShips4, numShips3, numShips2, numShips1);
	this->damage = 1;
}

User::User()
{
}
User::~User()
{
}

Action User::move(Player &player)
{
	auto commandHolder = CommandHolder();
	// Command cmd;

	commandHolder.read();
	auto cmd = commandHolder.getCommand();
	while (cmd == Command::skill)
	{
		try
		{
			this->useSkill(player);
		}
		catch (NoneAvailableSkillsException &e)
		{
			std::cout << e.what();
		}
		try
		{
			commandHolder.read();
		}
		catch (UnknownCommandException &e)
		{	
			std::cerr <<  e.what() << '\n';
			// std::cout << "Unknown Command" << '\n';
		}
		cmd = commandHolder.getCommand();
	}
	if (cmd == Command::load)
	{
		std::cout << "command load\n";
		return Action::Load;
	}

	if (cmd == Command::save)
	{
		std::cout << "save game\n";
		return Action::Save;
	}
	auto coordsHolder = CoordHolder();
	coordsHolder.read();
	auto coords = coordsHolder.getCoords();
	this->attack(player, coords.first - 1, coords.second - 1);
	return Action::Attack;
}

bool User::attack(Player &player, int x, int y)
{
	auto result = player.getField().AttackCell(x, y, damage);
	damage = 1;
	std::cout << "ya tut";
	if (result)
	{
		this->skillManager.addSkill();
	}
	return result;
}

bool User::useSkill(Player &player)
{
	auto infoHolder = SkillInfoHolder(&player.getShipManager(), &player.getField(), CoordHolder());
	auto skill = this->skillManager.getSkill(infoHolder);
	auto skillResult = skill->use();
	this->damage = skillResult.get_damage();
	if (this->damage != 1)
	{
		std::cout << "Следующая атака нанесёт 2-ой урон🚩\n";
	}
	if (skillResult.get_is_battleship_destroyed())
	{
		this->skillManager.addSkill();
		std::cout << "Так как вы уничтожили корабль, вы получили новую способность!\n";
	}
	if (skillResult.get_is_battleship_cell())
	{
		std::cout << "В данной ячейке был корабль!\n";
		return true;
	}
	return false;
}

void User::placeShips()
{
	auto holder = CoordHolder();
	auto holderDirection = DirectionHolder();
	std::cout << shipManager.GetNumberBattleships() << "num of battleships\n";
	for (int i = 0; i < shipManager.GetNumberBattleships(); i++)
	{
		std::pair<int, int> coords;
		Direction direction;
		try
		{
			holder.read();
			coords = holder.getCoords();
		}
		catch (ReaderException &e)
		{
			std::cout << e.what() << '\n';
			i--;
			continue;
		}
		try{
			holderDirection.read();
			direction = holderDirection.getDirection();
		}catch(UnknownCommandException& error)
		{
			std::cout << error.what() << '\n';
			i--;
			continue;
		}
		try
		{
			auto &ship = shipManager[i];
			this->field.SetBattleship(coords.first, coords.second, ship, direction);
			std::cout << this->field[coords.first][coords.second].GetFieldState() << "state of current cell\n";
			this->field.OpenField();
		}
		catch (ShipNearAnotherException &e)
		{
			std::cout << e.what();
			i--;
		}
	}
}

Field &User::getField()
{
	return this->field;
}

ShipManager &User::getShipManager()
{
	return this->shipManager;
}

SkillManager &User::getSkillManager()
{
	return this->skillManager;
}

int User::getDamage()
{
	return this->damage;
}

void User::setShipManager(ShipManager &sm)
{
	this->shipManager = sm;
}

void User::setField(Field &f)
{
	this->field = f;
}

void User::setSkillManager(SkillManager &sm)
{
	this->skillManager = sm;
}
//  User::useSkill(Player& player)
// {
// 	auto infoHolder = SkillInfoHolder(&this->game.getEnemyShipManager(), &this->game.getEnemyField(), CoordHolder());
// 	auto skill = game.getSkillManager().getSkill(infoHolder);
// 	auto skillResult = skill->use();
// 	this->damage = skillResult.get_damage();
// 	if (skillResult.get_is_battleship_destroyed())
// 	{
// 		this->game.getSkillManager().addSkill();
// 	}
// 	if (skillResult.get_is_battleship_cell())
// 	{
// 		//
// 	}
// }
