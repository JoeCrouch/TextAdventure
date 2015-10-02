
#ifndef TextAdventure_invalidActionService_h
#define TextAdventure_invalidActionService_h

class Player;

#include <string>
using std::string;

#include "actionService.h"

class InvalidActionService: public ActionService {
public:
    bool execute();
    InvalidActionService(string input);
    
private:
    string invalidActionString_;
};

#endif
