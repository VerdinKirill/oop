#include "ShipManager.h"
#include <iostream>

void ShipManager::CreateBattleships(BattleshipLength length,int num)
{
    for (size_t i = 0; i < num; i++)
    {
        auto battleship = Battleship(length);
        battleships[int(length)].push_back(battleship);
    }
}

int ShipManager::GetNumberBattleships()
{
    return this->length_4_ships + length_3_ships + length_2_ships + length_1_ships;
}

Battleship &ShipManager::operator[](int n)
{
    // if (n >= this->GetNumberBattleships())
    // {
    //     return ;
    // }
    // std::cout << n << ' ' << length_1_ships << " " << length_2_ships << " " << length_3_ships << " " << length_4_ships << "\n";
    int index = 0;
    if (n - length_1_ships < 0)
    {
        return battleships[1][n];
    }
    n -= length_1_ships;
    // std::cout << n << '\n';
    if (n - length_2_ships < 0)
    {
        return battleships[2][n];
    }
    n -= length_2_ships;
    // std::cout << n << '\n';
    if (n - length_3_ships < 0)
    {
        return battleships[3][n];
    }
    n -= length_3_ships;
    // std::cout << n << ' ' << length_3_ships << ' ' << n - length_3_ships << ' ' << (n - length_3_ships < 0) << '\n';
    return battleships[4][n];
}

ShipManager::ShipManager(int length_4_ships,int length_3_ships, int length_2_ships,int length_1_ships)
{
    battleships = std::vector(5, std::vector<Battleship>(0, Battleship()));
    this->length_4_ships = length_4_ships;
    this->length_3_ships = length_3_ships;
    this->length_2_ships = length_2_ships;
    this->length_1_ships = length_1_ships;
    CreateBattleships(BattleshipLength::Cell4, length_4_ships);
    CreateBattleships(BattleshipLength::Cell3, length_3_ships);
    CreateBattleships(BattleshipLength::Cell2, length_2_ships);
    CreateBattleships(BattleshipLength::Cell1, length_1_ships);
}

Battleship &ShipManager::GetBattleship(BattleshipLength length,int num)
{
    Battleship &battleship_output = battleships[int(length)][num];
    return battleship_output;
}
