#include "Game/PvEGame.h"

#include <iostream>

int main()
{   std::cout << R"(
                      __/___            
            _____/______|           
    _______/_____\_______\_____     
    \              < < <       |    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
██████   █████  ████████ ████████ ██      ███████ ███████ ██   ██ ██ ██████      ██     ██  █████  ██████  
██   ██ ██   ██    ██       ██    ██      ██      ██      ██   ██ ██ ██   ██     ██     ██ ██   ██ ██   ██ 
██████  ███████    ██       ██    ██      █████   ███████ ███████ ██ ██████      ██  █  ██ ███████ ██████  
██   ██ ██   ██    ██       ██    ██      ██           ██ ██   ██ ██ ██          ██ ███ ██ ██   ██ ██   ██ 
██████  ██   ██    ██       ██    ███████ ███████ ███████ ██   ██ ██ ██           ███ ███  ██   ██ ██   ██ )" << "\n\n";

    int countr = 0;
    int countm = 0;
    auto user = User();
    auto bot = Bot();
    auto state = GameState(user, bot, countr, countm);

    Game* gm = new PvEGame(state);
    gm->start();
    return 0;
}