
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
    cout << player.getName() + " wakes up at " + player.getLocationName() << endl;
    
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

void Game::movePlayer(Direction dir) {
    Location currentLocation = player.getLocation();
    
    int newXPosition = currentLocation.getXPosition() + dir.getXDirection();
    int newYPosition = currentLocation.getYPosition() + dir.getYDirection();
    
    Location newLocation = currentLocation;
    for(int i = 0; i < LOCATIONS.size(); i ++) {
        Location location = LOCATIONS[i];
        
        if (location.isAt(newXPosition, newYPosition)) {
            newLocation = location;
            break;
        }
    }
    
    if (newLocation == currentLocation) {
        cout << "Cannot move " + dir.getName()  + " try moving somewhere else!"<< endl;
    } else {
        player.moveTo(newLocation);
        cout << player.getName() + " moves " + dir.getName() + " to " + player.getLocationName() << endl;
    }
}
