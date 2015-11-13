
#ifndef TextAdventure_viewService_h
#define TextAdventure_viewService_h

#include "actionService.h"
#include "player.h"
#include <string>
using std::string;

class ViewService: public ActionService {
public:
    ViewService(string viewTarget, Player* player);
    bool execute();
    
private:
    ViewService();
    
    string viewTarget_;
    Player* player_;
};

#endif
