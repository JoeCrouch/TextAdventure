
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

vector<Action> availableActions;

typedef void (*pfunc)();

map<string, pfunc> buildPrintFunctionsMap();
map<string, pfunc> printFunctionsMap = buildPrintFunctionsMap();
void printActions();

bool canBePrinted(string printTarget);

PrintService::PrintService(string printTarget) : printTarget_(printTarget) {
}

bool PrintService::execute(Player* player) {
    string printTarget = printTarget_;
    
    if (printTarget.length() == 0) {
        cout << endl << "What would you like to print?" << endl;
        getline(cin, printTarget);
    }
    
    availableActions = player->getAvailableActions();
    
    string printTargetUpperCase = StringManager::toUpperCase(printTarget);
    if (canBePrinted(printTargetUpperCase)) {
        pfunc function = printFunctionsMap[printTargetUpperCase];
        function();
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
    }
    return printFunctionsMap;
};

void printActions() {
    cout << endl << "Available actions are:" << endl;
    for (int i = 0; i < availableActions.size(); i++) {
        Action action = availableActions[i];
        cout << action.getName() << endl;
    }
}


