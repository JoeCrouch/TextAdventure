
#include "moveService.h"
#include "game.h"
#include "direction.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

MoveService::MoveService(string direction, Player* player) :
        direction_(direction),
        player_(player){
}

bool MoveService::execute() {
    string dirString = direction_;
    
    if (direction_.length() == 0) {
        cout << endl << "Which direction would you like to move?" << endl;
        getline(cin, dirString);
    }
    const Direction dir = Direction::getDirection(dirString);
    
    Location currentLocation = player_->getLocation();
    
    int newXPosition = currentLocation.getXPosition() + dir.getXDirection();
    int newYPosition = currentLocation.getYPosition() + dir.getYDirection();
    
    Location newLocation = currentLocation;
    for(int i = 0; i < Game::LOCATIONS.size(); i ++) {
        Location location = Game::LOCATIONS[i];
        
        if (location.isAt(newXPosition, newYPosition)) {
            newLocation = location;
            break;
        }
    }
    
    
    if (dir == Direction::NOWHERE) {
        cout << endl << "'" + dirString + "' is not a valid direction try one of: " << endl;
        for (int i = 0; i < Direction::VALID_DIRECTIONS.size(); i++) {
            Direction direction = Direction::VALID_DIRECTIONS[i];
            cout << direction.getName() << endl;
        }
    } else if (newLocation == currentLocation) {
        cout << endl << "Cannot move " + dir.getName()  + " try moving somewhere else!"<< endl;
    } else {
        player_->moveTo(newLocation);
        cout << endl << player_->getName() + " moves " + dir.getName() + " to " + player_->getLocationName() << endl;
    }
    
    return false;
}