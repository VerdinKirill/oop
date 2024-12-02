#include "Bot.h"

Bot::Bot(int width, int height, int numShips4, int numShips3, int numShips2, int numShips1)
{
	this->field = new Field(width, height);
	this->shipManager = new ShipManager(numShips4, numShips3, numShips2, numShips1);
	this->damage = 1;
}
Bot::~Bot()
{
	delete this->field;
	delete this->shipManager;
}


void Bot::placeShips()
{
	int x = 0;
	int y = 0;
	for (int i = this->shipManager->GetNumberBattleships()-1; i >= 0; i--)
	{
		try
		{
			this->field->SetBattleship(x, y, (this->shipManager)->operator[](i), Direction::Up);
		}
		catch (ShipNearAnotherException &e)
		{	
			std::cout << "You entered small field for battleships\n" << (this->shipManager)->operator[](i).GetLength() << '\n';
		}
		x+=2;
	}
}

Action Bot::move(Player &player)
{	
	auto rand = Randomizer(1,this->field->GetHeight());
	int y = rand.getRandomInt();
	rand = Randomizer(1, this->field->GetWidth());
	int x = rand.getRandomInt();
	auto field = player.getField();
	int n = rand.getRandomInt();
	field.AttackCell(x, y, this->damage);
	return Action::Attack;
}

Field& Bot::getField()
{
	return *this->field;
}

ShipManager& Bot::getShipManager()
{
	return *this->shipManager;
}

void Bot::setShipManager(ShipManager& sm)
{
	this->shipManager = &sm;
}

void Bot::setField(Field& f)
{
	this->field = &f;
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