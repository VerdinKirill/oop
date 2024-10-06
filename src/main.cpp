#include <vector>
#include <iostream>
#include "Battleship.h"
#include "Field.h"
#include "ShipManager.h"


int main()
{
    // auto battleship = Battleship(3, Direction::Up);
    auto ship_manager = ShipManager(1, 2, 3, 4);
    auto field = Field(8, 8);
    auto battleship = ship_manager.GetBattleship(BattleshipLength::Cell4, 0);
    field.SetBattleship(1, 1, battleship, Direction::Up);
    field.AttackCell(1, 1);
    field.AttackCell(2, 1);
    auto battleship2 = ship_manager.GetBattleship(BattleshipLength::Cell3, 1);
    field.SetBattleship(1, 2, battleship2, Direction::Right);
    std::cout << field[1][1] << '\n';
    Field new_field(field);
    std::cout << field;
    return 0;
}