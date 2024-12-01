#include "Bot.h"

Bot::Bot(int width, int height, int numShips4, int numShips3, int numShips2, int numShips1)
{
	this->field = new Field(width, height);
	this->shipManager = new ShipManager(numShips4, numShips3, numShips2, numShips1);
	this->damage = 1;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			this->availableMoves.push_back({x, y});
		}
	}
}

Bot::Bot(Bot& bot)
{	
	delete this->field;
	auto oldField = this->field;
	this->field = new Field(bot.field->GetWidth(), bot.field->GetHeight());
	delete oldField;
	auto sm = bot.getShipManager();
	this->shipManager = new ShipManager(0, 0, 0, 0);
	for (int i = 0; i<sm.GetNumberBattleships(); i++)
	{
		this->shipManager->CreateBattleships(sm[i].GetLength(), 1);
	}
	delete &sm;
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

void Bot::move(Player &player)
{	
	auto rand = Randomizer(0, this->availableMoves.size());
	auto field = player.getField();
	int n = rand.getRandomInt();
	auto pos = this->availableMoves[n];
	field.AttackCell(pos.first, pos.second, this->damage);
	this->availableMoves.erase(this->availableMoves.cbegin() + n);
}

Field& Bot::getField()
{
	return *this->field;
}

ShipManager& Bot::getShipManager()
{
	return *this->shipManager;
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
