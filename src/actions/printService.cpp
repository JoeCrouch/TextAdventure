
#include "printService.h"
#include "player.h"
#include "stringManager.h"
#include "game.h"
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::max;
using std::sort;

typedef void (*pfunc)(Player player);

map<string, pfunc> buildPrintFunctionsMap();
map<string, pfunc> printFunctionsMap = buildPrintFunctionsMap();
void printActions(Player player);
void printLocation(Player player);
void printMap(Player player);

bool canBePrinted(string printTarget);

int getMaxXCoord();
int getMaxYCoord();
int getMaxLocationNameLength();

bool pointerCompare(Location* a, Location* b);

PrintService::PrintService(string printTarget, Player player) :
        printTarget_(printTarget),
        player_(player) {
}

bool PrintService::execute() {
    string printTarget = printTarget_;
    
    if (printTarget.length() == 0) {
        cout << endl << "What would you like to print?" << endl;
        getline(cin, printTarget);
    }
    
    string printTargetUpperCase = StringManager::toUpperCase(printTarget);
    if (canBePrinted(printTargetUpperCase)) {
        pfunc function = printFunctionsMap[printTargetUpperCase];
        function(player_);
    } else {
        cout << endl << "'" + printTarget + "' is not printable. Try one of:" << endl;
        for (map<string, pfunc>::iterator it = printFunctionsMap.begin(); it != printFunctionsMap.end(); ++it) {
            cout << it->first << endl;
        }
    }
    
    return false;
}

bool canBePrinted(string printTarget) {
    map<string, pfunc>::const_iterator it = printFunctionsMap.find(printTarget);
    return it != printFunctionsMap.end();
};


map<string, pfunc> buildPrintFunctionsMap() {
    static map<string, pfunc> printFunctionsMap;
    
    if (printFunctionsMap.size() == 0) {
        printFunctionsMap["ACTIONS"] = &printActions;
        printFunctionsMap["LOCATION"] = &printLocation;
        printFunctionsMap["MAP"] = &printMap;
    }
    return printFunctionsMap;
};

void printActions(Player player) {
    vector<Action> availableActions = player.getAvailableActions();
    cout << endl << "Available actions are:" << endl;
    for (int i = 0; i < availableActions.size(); i++) {
        Action action = availableActions[i];
        cout << action.getName() << endl;
    }
}

void printLocation(Player player) {
    cout << endl << player.getName() + " is at " + player.getLocationName() << endl;
}

void printMap(Player player) {
    int maxX = getMaxXCoord();
    int maxY = getMaxYCoord();
    int maxNameLength = getMaxLocationNameLength();
    
    vector<Location*> orderedLocations = Game::LOCATIONS;
    sort(orderedLocations.begin(), orderedLocations.end(), pointerCompare);
 
    //TODO if player is at location then surround with *** or make clear is here then can remove print location
    vector<Location*>::iterator iterator = orderedLocations.begin();
    for (int y = maxY - 1; y >= 0; y--) {
        for (int x = 0; x < maxX; x++) {
            if ((*iterator)->isAt(x, y)) {
                cout << " " + StringManager::centerLine(maxNameLength, (*iterator)->getName(), "-") + " ";
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

