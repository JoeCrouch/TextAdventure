
#include "moveService.h"
#include "game.h"
#include "player.h"
#include "direction.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool MoveService::execute(Player* player) {
    cout << "Which direction would you like to move?" << endl;
    string input = string("");
    getline(cin, input);
    
    //TODO: deal better with invalid input;
    const Direction* dir = Direction::getDirection(input);
    
    Location currentLocation = player->getLocation();
    
    int newXPosition = currentLocation.getXPosition() + dir->getXDirection();
    int newYPosition = currentLocation.getYPosition() + dir->getYDirection();
    
    Location newLocation = currentLocation;
    for(int i = 0; i < Game::LOCATIONS.size(); i ++) {
        Location location = Game::LOCATIONS[i];
        
        if (location.isAt(newXPosition, newYPosition)) {
            newLocation = location;
            break;
        }
    }
    
    if (newLocation == currentLocation) {
        cout << "Cannot move " + dir->getName()  + " try moving somewhere else!"<< endl;
    } else {
        player->moveTo(newLocation);
        cout << player->getName() + " moves " + dir->getName() + " to " + player->getLocationName() << endl;
    }
    
    return false;
}