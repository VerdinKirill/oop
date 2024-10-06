#include <vector>
#include <iostream>
#include "Battleship.h"
#include "Field.h"
#include "ShipManager.h"
#include <memory>

int main()
{
    // auto battleship = Battleship(3, Direction::Up);
    auto ship_manager = ShipManager(1, 2, 3, 4);
    auto field = Field(14, 18);
    auto battleship = ship_manager.GetBattleship(BattleshipLength::Cell4, 0);
    field.SetBattleship(1, 1, battleship, Direction::Up);
    field.AttackCell(1, 1);
    std::cout << field[1][1] << '\n';
    Field new_field(field);
    // Field& new_field = field;
    // field.AttackCell(1, 2);
    // field.AttackCell(1, 2);
    std::cout << field;
    return 0;
}