#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H
#include <vector>
#include "Battleship.h"


class ShipManager
{
public:
   Battleship &GetBattleship(BattleshipLength length, int num);
   Battleship &operator[](int n);
   ShipManager(int length_4_ships = 1, int length_3_ships = 2, int length_2_ships = 3, int length_1_ships = 4);
   int GetNumberBattleships();
   Battleship& getBattleshipById(int id);
   bool isDefeated();
   void CreateBattleships(BattleshipLength length, int num);
   int getNum4Length();
   int getNum3Length();
   int getNum2Length();
   int getNum1Length();


private:
   int length_4_ships;
   int length_3_ships;
   int length_2_ships;
   int length_1_ships;
   std::vector<std::vector<Battleship*>> battleships;
};

#endif