
#include "actionService.h"
#include "player.h"
#include "moveService.h"
#include "printService.h"
#include "quitService.h"
#include "invalidActionService.h"
#include "stringManager.h"
#include <map>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::map;

map<const Action, ActionService*> actionServiceMap(string actionTarget, Player player);

ActionService* ActionService::getActionFromPlayer(Player player) {
    cout << endl << "What would you like to do?" << endl;
    string input = string("");
    getline(cin, input);
    
    long firstWordLength = input.find(' ') == string::npos ? input.size() : input.find(' ') ;
    
    string firstWord = input.substr(0, firstWordLength);
    string restOfInput = firstWordLength == input.length()
                                        ? ""
                                        : input.substr(firstWordLength + 1, input.length());
    
    vector<Action> availableActions = player.getAvailableActions();
    for (int i = 0; i < availableActions.size(); i++) {
        Action action = availableActions[i];
        
        if (StringManager::equalIgnoreCase(firstWord, action.getName())) {
            return actionServiceMap(restOfInput, player)[action];
        }
    }
    
    return new InvalidActionService(firstWord);
}

map<const Action, ActionService*> actionServiceMap(string actionTarget, Player player) {
    map<const Action, ActionService*> actionServiceMap;
    
    actionServiceMap[Action::QUIT] = new QuitService();
    actionServiceMap[Action::PRINT] = new PrintService(actionTarget, player.getAvailableActions());
    actionServiceMap[Action::MOVE] = new MoveService(actionTarget, player);
    
    return actionServiceMap;
};
