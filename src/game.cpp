
#include <iostream>
#include "game.h"
using std::cout;
using std::endl;

Game::Game(Player player) : player(player) {
}

void Game::play() {
    player.printPlayerCharacteristics();
    
    cout << player.getName() + " wakes up at " + player.getLocationName() << endl;
}
