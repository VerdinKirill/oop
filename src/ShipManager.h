#pragma once
#include <vector>
#include "Battleship.h"
class ShipManager
{
public:
   Battleship &GetBattleship(BattleshipLength length, unsigned num);
   Battleship& operator[](unsigned n);
   ShipManager(unsigned length_4_ships = 1, unsigned length_3_ships = 2, unsigned length_2_ships = 3, unsigned length_1_ships = 4);
   unsigned GetNumberBattleships();

private:
   void CreateBattleships(BattleshipLength length, unsigned num);
   unsigned length_4_ships;
   unsigned length_3_ships;
   unsigned length_2_ships;
   unsigned length_1_ships;
   std::vector<std::vector<Battleship> >battleships;
};