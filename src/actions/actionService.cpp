
#include "actionService.h"
#include "player.h"
#include "moveService.h"
#include "pickUpService.h"
#include "dropService.h"
#include "useService.h"
#include "viewService.h"
#include "quitService.h"
#include "invalidActionService.h"
#include "stringManager.h"
#include <map>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::map;

map<const Action, ActionService*> actionServiceMap(string actionTarget, Player* player);

ActionService* ActionService::getActionFromPlayer(Player* player) {
    cout << endl << "What would you like to do?" << endl;
    string input = string("");
    getline(cin, input);
    
    vector<Action> availableActions = player->getAvailableActions();
    for (int i = 0; i < availableActions.size(); i++) {
        Action action = availableActions[i];
        string actionName = action.getName();
        
        if (StringManager::startsWith(input, actionName)) {
            string restOfInput = input.size() > actionName.size() ? input.substr(actionName.size() + 1, input.size()) : "";
            return actionServiceMap(restOfInput, player)[action];
        }
    }
    
    return new InvalidActionService(input);
}

map<const Action, ActionService*> actionServiceMap(string actionTarget, Player* player) {
    map<const Action, ActionService*> actionServiceMap;
    
    actionServiceMap[Action::QUIT] = new QuitService();
    actionServiceMap[Action::VIEW] = new ViewService(actionTarget, player);
    actionServiceMap[Action::USE] = new UseService(actionTarget, player);
    actionServiceMap[Action::DROP] = new DropService(actionTarget, player);
    actionServiceMap[Action::PICK_UP] = new PickUpService(actionTarget, player);
    actionServiceMap[Action::MOVE] = new MoveService(actionTarget, player);
    
    return actionServiceMap;
};
