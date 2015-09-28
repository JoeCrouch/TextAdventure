
#ifndef TextAdventure_printActionsService_h
#define TextAdventure_printActionsService_h

class Player;

#include "actionService.h"

class PrintActionsService: public ActionService {
public:
    bool execute(Player* player);
};

#endif
