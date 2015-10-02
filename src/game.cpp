
#include <iostream>
#include <string>
#include <stdlib.h>
#include "game.h"
#include "direction.h"
#include "stringManager.h"
#include "actionService.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

ActionService* getAction(string actionString, Player player);

Game::Game(Player player) : player(player) {
}

void Game::play() {
    cout << endl << player.getName() + " wakes up at " + player.getLocationName() << endl;
    
    bool exitedGame = false;
    while (!exitedGame) {
        
        ActionService* actionService = ActionService::getActionFromPlayer(player.getAvailableActions());
        exitedGame = actionService->execute(&player);
    }
    
}

const vector<Location> Game::LOCATIONS {
    Location::HOME,
    Location::WOODS,
    Location::SEA,
    Location::MOUNTAIN,
    Location::DESERT
};
