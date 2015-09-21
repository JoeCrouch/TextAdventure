
#ifndef TextAdventure_moveService_h
#define TextAdventure_moveService_h

class Player;

#include "actionService.h"

class MoveService: public ActionService {
public:
    bool execute(Player* player);
};

#endif
