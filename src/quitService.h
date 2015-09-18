
#ifndef TextAdventureXCode_quitService_h
#define TextAdventureXCode_quitService_h

class Player;

#include "actionService.h"

class QuitService: public ActionService {
public:
    bool execute(Player* player);
};

#endif
