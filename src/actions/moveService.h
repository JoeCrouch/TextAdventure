
#ifndef TextAdventure_moveService_h
#define TextAdventure_moveService_h

class Player;

#include "actionService.h"
#include <string>
using std::string;

class MoveService: public ActionService {
public:
    MoveService(string direction);
    bool execute(Player* player);
    
private:
    MoveService();
    
    string direction_;
};

#endif
