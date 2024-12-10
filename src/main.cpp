#include "Game/PvEGame.h"

#include <iostream>

int main()
{
    std::cout << R"(
                      __/___            
            _____/______|           
    _______/_____\_______\_____     
    \              < < <       |    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
██████   █████  ████████ ████████ ██      ███████ ███████ ██   ██ ██ ██████      ██     ██  █████  ██████  
██   ██ ██   ██    ██       ██    ██      ██      ██      ██   ██ ██ ██   ██     ██     ██ ██   ██ ██   ██ 
██████  ███████    ██       ██    ██      █████   ███████ ███████ ██ ██████      ██  █  ██ ███████ ██████  
██   ██ ██   ██    ██       ██    ██      ██           ██ ██   ██ ██ ██          ██ ███ ██ ██   ██ ██   ██ 
██████  ██   ██    ██       ██    ███████ ███████ ███████ ██   ██ ██ ██           ███ ███  ██   ██ ██   ██ )"
              << "\n\n";

    auto coordHolder = CoordHolder();
    std::cout << "Введите размер поля через пробел\n";
    coordHolder.read();
    auto coords = coordHolder.getCoords();
    std::vector<int> lengths;
    int length;
    for (int i = 1; i < 5; i++)
    {
        std::cout << "Введите количество кораблей длины " << i << " \n";
        std::cin >> length;
        lengths.push_back(length);
    }
    auto bot = Bot(coords.first, coords.second, lengths[3], lengths[2], lengths[1], lengths[0]);
    auto user = User(coords.first, coords.second, lengths[3], lengths[2], lengths[1], lengths[0]);

    int countr = 1;
    int countm = 1;
    auto state = GameState(user, bot, countr, countm);
	std::string filename = "/Users/kirillverdin/programming/oop/File.json";
    Game *gm = new PvEGame(user, bot, state, filename);
    gm->start();
    return 0;
}