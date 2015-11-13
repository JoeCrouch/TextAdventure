
#include "viewService.h"
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

typedef void (*pfunc)(Player* player);

map<string, pfunc> buildViewFunctionsMap();
map<string, pfunc> viewFunctionsMap = buildViewFunctionsMap();
void viewActions(Player* player);

bool canBeViewed(string viewTarget);

ViewService::ViewService(string viewTarget, Player* player) :
        viewTarget_(viewTarget),
        player_(player) {
}

bool ViewService::execute() {
    string viewTarget = viewTarget_;
    
    if (viewTarget.length() == 0) {
        cout << endl << "What would you like to view?" << endl;
        getline(cin, viewTarget);
    }
    
    string viewTargetUpperCase = StringManager::toUpperCase(viewTarget);
    if (canBeViewed(viewTargetUpperCase)) {
        pfunc function = viewFunctionsMap[viewTargetUpperCase];
        function(player_);
    } else {
        cout << endl << "'" + viewTarget + "' is not viewable. Try one of:" << endl;
        for (map<string, pfunc>::iterator it = viewFunctionsMap.begin(); it != viewFunctionsMap.end(); ++it) {
            cout << it->first << endl;
        }
    }
    
    return false;
}

bool canBeViewed(string viewTarget) {
    map<string, pfunc>::const_iterator it = viewFunctionsMap.find(viewTarget);
    return it != viewFunctionsMap.end();
};


map<string, pfunc> buildViewFunctionsMap() {
    static map<string, pfunc> viewFunctionsMap;
    
    if (viewFunctionsMap.size() == 0) {
        viewFunctionsMap["ACTIONS"] = &viewActions;
    }
    return viewFunctionsMap;
};

void viewActions(Player* player) {
    vector<Action> availableActions = player->getAvailableActions();
    cout << endl << "Available actions are:" << endl;
    for (int i = 0; i < availableActions.size(); i++) {
        Action action = availableActions[i];
        cout << action.getName() << endl;
    }
}

