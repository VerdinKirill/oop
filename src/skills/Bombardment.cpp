#include "Bombardment.h"
#include <iostream>

Bombardment::Bombardment(ShipManager &ship_manager)
{
	this->ship_manager = &ship_manager;
}

SkillResultInfoHolder& Bombardment::use()
{	
	auto skill_result = new SkillResultInfoHolder();
	std::vector<BattleshipCell *> cells;
	unsigned num_ships = ship_manager->GetNumberBattleships();
	// std::cout << "num_ships" << num_ships << '\n';
	// std::cout << "shiplen " << (*ship_manager)[0].GetLength() << '\n';
	for (size_t i = 0; i < num_ships; i++)
	{	
		Battleship *battleship = &(*ship_manager)[i];
		for (size_t j = 0; j < battleship->GetLength(); j++)
		{	
			BattleshipCell *n = &((*battleship)[j]);
			// n->AttackBattleshipCell();
			cells.push_back(n);
		}
	}
	int random_index;
	while (cells.size() != 0)
	{
		random_index = (std::rand() % cells.size());
		// std::cout << "random_index" << cells[random_index]->GetState() << '\n';
		if (cells[random_index]->GetState() != BattleshipCellState::Destroyed)
		{
			cells[random_index]->AttackBattleshipCell();

			skill_result->set_is_battleship_cell(true);
			skill_result->set_is_battleship_destroyed(cells[random_index]->isBattleshipDestroyed());
			break;
		}
		cells.erase(cells.begin() + random_index);
	}
	return *skill_result;
}
