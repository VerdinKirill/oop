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
    // field.OpenField();
    std::cout << field;

    auto battleship = ship_manager.GetBattleship(BattleshipLength::Cell4, 0);
    auto battleship2 = ship_manager.GetBattleship(BattleshipLength::Cell3, 1);
    field.SetBattleship(1, 1, battleship, Direction::Up);
    field.SetBattleship(4, 5, battleship2, Direction::Right);
    field.OpenField();
    std::cout << "Field after placing ships: \n" << field;

    //try to set ship near another:
    field.SetBattleship(1, 2, battleship2, Direction::Right);
    
    field.AttackCell(1, 1);
    field.AttackCell(1, 2);
    field.AttackCell(1, 1);
    std::cout << "Field after attack:\n" << field;


    Field new_field(field);
    return 0;
}