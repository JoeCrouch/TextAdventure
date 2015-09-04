
#include <iostream>
#include "game.h"
#include "direction.h"
using std::cout;
using std::endl;

Game::Game(Player player) : player(player) {
}

void Game::play() {
    cout << player.getName() + " wakes up at " + player.getLocationName() << endl;
    
    movePlayer(Direction::NORTH);
    cout << player.getName() + " moves North to " + player.getLocationName() << endl;
    
    movePlayer(Direction::NORTH);
    cout << player.getName() + " moves North to " + player.getLocationName() << endl;
    
    movePlayer(Direction::SOUTH);
    cout << player.getName() + " moves South to " + player.getLocationName() << endl;
    
    movePlayer(Direction::SOUTH);
    cout << player.getName() + " moves South to " + player.getLocationName() << endl;
    
    movePlayer(Direction::EAST);
    cout << player.getName() + " moves East to " + player.getLocationName() << endl;
    
    movePlayer(Direction::NORTH);
    cout << player.getName() + " moves North to " + player.getLocationName() << endl;
    
    movePlayer(Direction::EAST);
    cout << player.getName() + " moves East to " + player.getLocationName() << endl;
    
    movePlayer(Direction::WEST);
    cout << player.getName() + " moves West to " + player.getLocationName() << endl;
    
    movePlayer(Direction::WEST);
    cout << player.getName() + " moves West to " + player.getLocationName() << endl;
    
    movePlayer(Direction::EAST);
    cout << player.getName() + " moves east to " + player.getLocationName() << endl;
    
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
