#include "User.h"

User::User(int width, int height, int numShips4, int numShips3, int numShips2, int numShips1)
{
	this->field = new Field(width, height);
	this->skillManager = new SkillManager();
	this->shipManager = new ShipManager(numShips4, numShips3, numShips2, numShips1);
	this->damage = 1;
}

void User::move(Player &player)
{
	auto commandHolder = CommandHolder();
	// Command cmd;

	try
	{
		commandHolder.read();
	}
	catch (UnknownCommandException &e)
	{
		std::cout << "Unknown Command" << '\n';
		return;
	}
	auto cmd = commandHolder.getCommand();
	while (cmd != Command::attack)
	{
		if (cmd == Command::skill)
		{
			this->useSkill(player);
		}
		if (cmd == Command::load)
		{
			std::cout << "executed command load";
		}

		if (cmd == Command::quit)
		{
			std::cout << "quit game\n";
		}
		try
		{
			commandHolder.read();
		}
		catch (UnknownCommandException &e)
		{
			std::cout << "Unknown Command" << '\n';
		}
		auto cmd = commandHolder.getCommand();
	}
	auto coordsHolder = CoordHolder();
	coordsHolder.read();
	auto coords = coordsHolder.getCoords();
	this->attack(player, coords.first, coords.second);
}

bool User::attack(Player &player, int x, int y)
{
	auto result = player.getField().AttackCell(x, y, damage);
	if (result)
	{
		this->skillManager->addSkill();
	}
	if (player.getShipManager().isDefeated())
	{
		return true;
	}
	return false;
}

bool User::useSkill(Player &player)
{
	auto infoHolder = SkillInfoHolder(&player.getShipManager(), &player.getField(), CoordHolder());
	auto skill = this->skillManager->getSkill(infoHolder);
	auto skillResult = skill->use();
	this->damage = skillResult.get_damage();
	if (skillResult.get_is_battleship_destroyed())
	{
		this->skillManager->addSkill();
	}
	if (skillResult.get_is_battleship_cell())
	{
		return true;
	}
	return false;
}

void User::placeShips()
{
	auto holder = CoordHolder();
	auto holderDirection = DirectionHolder();

	for (int i = 0; i < this->getShipManager().GetNumberBattleships(); i++)
	{
		holder.read();
		auto coords = holder.getCoords();
		holderDirection.read();
		auto direction = holderDirection.getDirection();
		try
		{	
			auto ship = (*shipManager)[i];
			this->field->SetBattleship(coords.first, coords.second, ship, direction);
			field->OpenField();
			std::cout << this->field->to_string();
		}
		catch (ShipNearAnotherException &e)
		{	
			// field->OpenField();
			// std::cout << field->to_string();
			std::cout << e.what();
			i--;
		}
	}
}

Field& User::getField()
{
	return *this->field;
}

ShipManager& User::getShipManager()
{
	return *this->shipManager;
}

SkillManager& User::getSkillManager()
{
	return *this->skillManager;
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
