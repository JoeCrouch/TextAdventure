#ifndef TextAdventure_actionService_h
#define TextAdventure_actionService_h

class Player;

#include "action.h"
#include <vector>
using std::vector;

class ActionService {
public:
    virtual ~ActionService() {};
    
    // TODO: rather than pass player in here pass into the services that require it.
    // Return true if game should be exited and false otherwise
    virtual bool execute(Player* player) = 0;
    
    static ActionService* getActionFromPlayer(vector<Action> availableActions);
};

#endif

