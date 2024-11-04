#include "Bombardment.h"
#include <iostream>

Bombardment::Bombardment(ShipManager &ship_manager)
{
	this->ship_manager = &ship_manager;
}

bool Bombardment::use()
{	
	std::vector<BattleshipCell *> cells;
	unsigned num_ships = ship_manager->GetNumberBattleships();
	std::cout << "num_ships" << num_ships << '\n';
	// std::cout << "shiplen " << (*ship_manager)[0].GetLength() << '\n';
	for (size_t i = 0; i < num_ships; i++)
	{	
		Battleship *battleship = &(*ship_manager)[i];
		// std::cout << int(battleship->GetLength()) << '\n';
	 	std:: cout << "battleship len"  <<  battleship->GetLength() <<" adress: " << battleship << '\n';
		for (size_t j = 0; j < battleship->GetLength(); j++)
		{	
			BattleshipCell *n = &((*battleship)[j]);
			std::cout << battleship << '\t' << &(*battleship) << '\n';
			n->AttackBattleshipCell();
			std::cout<<"state:"<<n->GetState() << '\n';
			cells.push_back(n);
		}
	}
	std::cout << "я сделал вектор ячеек";
	int random_index;
	while (cells.size() != 0)
	{
		random_index = (std::rand() % cells.size());
		// std::cout << "random_index" << cells[random_index]->GetState() << '\n';
		// if (cells[random_index]->GetState() != BattleshipCellState::Destroyed)
		{
			cells[random_index]->AttackBattleshipCell();
			std::cout << "random_index" << cells[random_index]->GetState() << '\n';

			return true;
		}
		cells.erase(cells.begin() + random_index);
	}
	return false;
}