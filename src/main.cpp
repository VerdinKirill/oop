#include <vector>
#include <iostream>
#include "Battleship.h"
#include "Field.h"
#include <memory>

int main()
{
    auto battleship = Battleship(3, Direction::Up);
    auto field = Field(10, 10);
    field.SetBattleship(1, 1, std::make_shared<Battleship>(battleship), Direction::Up);
    field.AttackCell(1, 1);
    std::cout << field[1][1] << '\n';
    for (int i = 0; i<field.GetHeight(); i++)
    {
        for (int j = 0; j < field.GetWidth(); j++)
        {
            std::cout << field[i][j]  << " ";
        }
        std::cout << "\n";
    }
    return 0;
}