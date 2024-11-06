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
    auto field = Field(8, 8);
    // field.OpenField();
    Battleship ship = Battleship(Cell3);
    ship[2].AttackBattleshipCell();
    std::cout << "ptr " << &ship << '\n'; 


    SkillFactory *factory;
    Skill *skill;

    auto &battleship = *&ship_manager.GetBattleship(BattleshipLength::Cell4, 0);
    auto &battleship2 = *&ship_manager.GetBattleship(BattleshipLength::Cell3, 0);
    std::cout << "len of 3length battleship "<< battleship2.GetLength() << '\n';
    std::cout << "battleship len 4 adress: " << &battleship << '\n';
    std::cout << "battleship len 3 adress: " << &battleship2 << '\n';
    field.SetBattleship(1, 1, battleship, Direction::Up);
    field.SetBattleship(4, 5, battleship2, Direction::Right);
    field.OpenField();
    std::cout << field;
    auto y = ship_manager[0];

    factory = new ScanerFactory;
    auto pos = Pos{3, 3};
    auto skill_info = new SkillInfoHolder(std::nullopt, &field, &pos);
    skill = factory->createSkill(skill_info);
    auto& skill_result = skill->use();
    std::cout<< "is battleship in area of position " << skill_result.get_pos().x << " " <<skill_result.get_pos().y <<" ? : " << ((skill_result.get_is_battleship_cell())? true: false) << '\n';
    // delete skill;

    pos = Pos{4, 4};
    skill_info->setPos(pos);
    skill = factory->createSkill(skill_info);
    skill_result = skill->use();
    std::cout<< "is battleship in area of position " << skill_result.get_pos().x << " " << skill_result.get_pos().y <<" ? : " << ((skill_result.get_is_battleship_cell())? true: false) << '\n';


    // delete factory;
    factory = new DoubleDamageFactory;
    skill = factory->createSkill(skill_info);
    skill_result= skill->use();
    skill_result = field.AttackCell(1, 1, &skill_result);
    std::cout << field;
    std::cout << "Is battleship: "<< skill_result.get_is_battleship_cell() << "\nIs battleship destroyed: " << skill_result.get_is_battleship_destroyed() << '\n';
    skill_result= skill->use();
    skill_result = field.AttackCell(1, 2, &skill_result);
    std::cout << "Is battleship: "<< skill_result.get_is_battleship_cell() << "\nIs battleship destroyed: " << skill_result.get_is_battleship_destroyed() << '\n';
    skill_result= skill->use();
    skill_result = field.AttackCell(1, 3, &skill_result);
    std::cout << "Is battleship: "<< skill_result.get_is_battleship_cell() << "\nIs battleship destroyed: " << skill_result.get_is_battleship_destroyed() << '\n';
    skill_result= skill->use();
    skill_result = field.AttackCell(1, 4, &skill_result);
    std::cout << "Is battleship: "<< skill_result.get_is_battleship_cell() << "\nIs battleship destroyed: " << skill_result.get_is_battleship_destroyed() << '\n';
    std::cout << field;






    // skill = factory->createSkill(std::nullopt, std::nullopt, &ship_manager);
    // skill->use();
    // std::cout << "Field after placing Bombrding: \n"
    //           << field;

    // try to set ship near another:
    // field.SetBattleship(1, 2, battleship2, Direction::Right);
    return 0;
}