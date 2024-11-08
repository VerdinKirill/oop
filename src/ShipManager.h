#pragma once
#include <vector>
#include "Battleship.h"
class ShipManager
{
public:
   Battleship &GetBattleship(BattleshipLength length, int num);
   Battleship &operator[](int n);
   ShipManager(int length_4_ships = 1, int length_3_ships = 2, int length_2_ships = 3, int length_1_ships = 4);
   int GetNumberBattleships();
   ~ShipManager();

private:
   void CreateBattleships(BattleshipLength length, int num);
   int length_4_ships;
   int length_3_ships;
   int length_2_ships;
   int length_1_ships;
   std::vector<std::vector<Battleship*>> battleships;
};