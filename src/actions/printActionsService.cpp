
#include "printActionsService.h"
#include "player.h"
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

bool PrintActionsService::execute(Player* player) {
    vector<Action> availableActions = player->getAvailableActions();
    
    cout << "Available actions are:" << endl;
    for (int i = 0; i < availableActions.size(); i++) {
        Action action = availableActions[i];
        cout << action.getName() << endl;
    }
    return false;
}
