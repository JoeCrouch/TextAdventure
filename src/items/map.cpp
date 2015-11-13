
#include "map.h"
#include "player.h"
#include "location.h"
#include "game.h"
#include "stringManager.h"
#include <iostream>
#include <algorithm>
using std::max;
using std::cout;
using std::endl;

int getMaxXCoord();
int getMaxYCoord();
int getMaxLocationNameLength();

bool pointerCompare(Location* a, Location* b);

Map const * Map::INSTANCE = new Map();

Map::Map() : Item("Map") {
    
}

void Map::use(Player* player) const {
    int maxX = getMaxXCoord();
    int maxY = getMaxYCoord();
    int maxNameLength = getMaxLocationNameLength();
    
    Location* playersLocation = player->getLocation();
    
    vector<Location*> orderedLocations = Game::LOCATIONS;
    sort(orderedLocations.begin(), orderedLocations.end(), pointerCompare);
    
    vector<Location*>::iterator iterator = orderedLocations.begin();
    for (int y = maxY - 1; y >= 0; y--) {
        for (int x = 0; x < maxX; x++) {
            if ((*iterator)->isAt(x, y)) {
                if (*(*iterator) == *playersLocation) {
                    cout << " " + StringManager::centerLine(maxNameLength, (*iterator)->getName(), "*") + " ";
                } else {
                    cout << " " + StringManager::centerLine(maxNameLength, (*iterator)->getName(), "-") + " ";
                }
                iterator++;
            } else {
                cout << " " + StringManager::repeatedSymbol(maxNameLength, "-") + " ";
            }
        }
        cout << endl;
    }
}

int getMaxXCoord() {
    int maxLocationX = 0;
    for (int i = 0; i < Game::LOCATIONS.size(); i++) {
        Location* location = Game::LOCATIONS[i];
        maxLocationX = max(maxLocationX, location->getXPosition());
    }
    
    return maxLocationX + 1;
}

int getMaxYCoord() {
    int maxLocationY = 0;
    for (int i = 0; i < Game::LOCATIONS.size(); i++) {
        Location* location = Game::LOCATIONS[i];
        maxLocationY = max(maxLocationY, location->getYPosition());
    }
    
    return maxLocationY + 1;
}

int getMaxLocationNameLength() {
    int maxLocationNameLength = 0;
    for (int i = 0; i < Game::LOCATIONS.size(); i++) {
        Location* location = Game::LOCATIONS[i];
        maxLocationNameLength = max(maxLocationNameLength, (int) location->getName().size());
    }
    
    return maxLocationNameLength + 4;
}

bool pointerCompare(Location* a, Location* b) {
    return (*a < *b);
}
