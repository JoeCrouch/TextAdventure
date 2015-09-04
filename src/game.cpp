
#include "game.h"

Game::Game(Player player) : player(player) {
}

void Game::play() {
    player.printPlayerCharacteristics();
}
