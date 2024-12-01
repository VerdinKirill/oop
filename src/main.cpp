#include "Game/PvEGame.h"

#include <iostream>

int main()
{   Field f = Field(6, 6);
    Battleship s = Battleship(BattleshipLength::Cell3);
    f.SetBattleship(1, 1, s, Direction::Up);
    f.OpenField();
    std::cout << f.to_string();
    Game* gm = new PvEGame();
    gm->start();
    return 0;
}