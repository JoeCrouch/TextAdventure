
#include "printService.h"
#include "player.h"
#include "stringManager.h"
#include <vector>
#include <map>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;

typedef void (*pfunc)(Player player);

map<string, pfunc> buildPrintFunctionsMap();
map<string, pfunc> printFunctionsMap = buildPrintFunctionsMap();
void printActions(Player player);
void printLocation(Player player);

bool canBePrinted(string printTarget);

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


// TODO: Should be able to print map, and player location.
map<string, pfunc> buildPrintFunctionsMap() {
    static map<string, pfunc> printFunctionsMap;
    
    if (printFunctionsMap.size() == 0) {
        printFunctionsMap["ACTIONS"] = &printActions;
        printFunctionsMap["LOCATION"] = &printLocation;
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


