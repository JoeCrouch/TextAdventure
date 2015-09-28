
#include "actionService.h"
#include "moveService.h"
#include "printActionsService.h"
#include "quitService.h"
#include "invalidActionService.h"
#include "stringManager.h"
#include <map>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::map;

map<const Action, ActionService*> actionServiceMap();

ActionService* ActionService::getActionFromPlayer(vector<Action> availableActions) {
    cout << "What would you like to do?" << endl;
    string input = string("");
    getline(cin, input);
    
    for (int i = 0; i < availableActions.size(); i++) {
        Action action = availableActions[i];
        
        if (StringManager::equalIgnoreCase(input, action.getName())) {
            return actionServiceMap()[action];
        }
    }
    
    return new InvalidActionService(input);
}

map<const Action, ActionService*> actionServiceMap() {
    map<const Action, ActionService*> actionServiceMap;
    
    actionServiceMap[Action::QUIT] = new QuitService();
    actionServiceMap[Action::PRINT_ACTIONS] = new PrintActionsService();
    actionServiceMap[Action::MOVE] = new MoveService();
    
    return actionServiceMap;
};
