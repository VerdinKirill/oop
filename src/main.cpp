#include <vector>
#include <iostream>
#include "Battleship.h"
#include "Field.h"
#include "ShipManager.h"
#include "skills/BombardmentFactory.h"
#include "skills/DoubleDamageFactory.h"
#include "skills/ScanerFactory.h"
#include "skills/Skill.h"
#include "skills/SkillFactory.h"

int main()
{
    // auto battleship = Battleship(3, Direction::Up);
    auto ship_manager = ShipManager(1, 1, 0, 0);
    std::cout << "Ship manager adress IN MAIN:" << &ship_manager << '\n';
    auto field = Field(8, 8);
    // field.OpenField();
    std::cout << field;
    SkillFactory *factory;
    Skill *skill;

    auto &battleship = ship_manager.GetBattleship(BattleshipLength::Cell4, 0);
    auto &battleship2 = ship_manager.GetBattleship(BattleshipLength::Cell3, 0);
    std::cout << "battleship len 4 adress: " << &battleship << '\n';
    std::cout << "battleship len 3 adress: " << &battleship2 << '\n';
    field.SetBattleship(1, 1, battleship, Direction::Up);
    field.SetBattleship(4, 5, battleship2, Direction::Right);
    field.OpenField();
    auto y = ship_manager[0];

    factory = new BombardmentFactory;
    skill = factory->createSkill(std::nullopt, std::nullopt, &ship_manager);
    skill->use();
    std::cout << "Field after placing Bombrding: \n"
              << field;

    // try to set ship near another:
    // field.SetBattleship(1, 2, battleship2, Direction::Right);

    field.AttackCell(1, 1);
    // field.AttackCell(1, 2);
    // field.AttackCell(1, 1);
    std::cout << "Field after attack:\n"
              << field;

    // Field new_field(field);
    return 0;
}