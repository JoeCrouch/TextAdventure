
#ifndef TextAdventure_moveService_h
#define TextAdventure_moveService_h

#include "actionService.h"
#include "player.h"
#include <string>
using std::string;

class MoveService: public ActionService {
public:
    MoveService(string direction, Player player);
    bool execute();
    
private:
    MoveService();
    
    string direction_;
    Player player_;
};

#endif
