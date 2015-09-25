
#ifndef TextAdventure_invalidActionService_h
#define TextAdventure_invalidActionService_h

class Player;

#include <string>
using std::string;

#include "actionService.h"

class InvalidActionService: public ActionService {
public:
    bool execute(Player* player);
    InvalidActionService(string input);
    
private:
    string invalidActionString_;
};

#endif
