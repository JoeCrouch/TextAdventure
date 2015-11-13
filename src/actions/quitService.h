
#ifndef TextAdventure_quitService_h
#define TextAdventure_quitService_h

class Player;

#include "actionService.h"

class QuitService: public ActionService {
public:
    bool execute();
};

#endif
