
#include <iostream>
#include <string>
#include <stdlib.h>
#include "game.h"
#include "direction.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

Game::Game(Player player) : player(player) {
}

void Game::play() {
    cout << player.getName() + " wakes up at " + player.getLocationName() << endl;
    
    bool exitedGame = false;
    while (!exitedGame) {
        cout << "Which direction would you like to move (invalid direction will exit game) ?" << endl;
        string input = string("");
        getline(cin, input);
        
        const Direction* direction = Direction::getDirection(input);
        
        if (direction == NULL) {
            exitedGame = true;
        } else {
            movePlayer(*direction);
            cout << player.getName() + " moves " + direction->getName() + " to " + player.getLocationName() << endl;
        }
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
    
    int currentXPosition = currentLocation.getXPosition();
    int currentYPosition = currentLocation.getYPosition();
    
    int newXPosition = currentXPosition + dir.getXDirection();
    int newYPosition = currentYPosition+ dir.getYDirection();
    
    Location newLocation = currentLocation;
    for(int i = 0; i < LOCATIONS.size(); i ++) {
        Location location = LOCATIONS[i];
        int locationXPosition = location.getXPosition();
        int locationYPosition = location.getYPosition();
        
        if (locationXPosition == currentXPosition && locationYPosition == currentYPosition) {
            continue;
        }else if (locationXPosition == newXPosition && locationYPosition == newYPosition) {
            newLocation = location;
            break;
        }
    }
    
    player.moveTo(newLocation);
}
