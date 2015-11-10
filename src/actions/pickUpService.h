

#ifndef TextAdventure_pickUpService_h
#define TextAdventure_pickUpService_h

#include "actionService.h"
#include <string>
using std::string;

class PickUpService: public ActionService {
public:
    PickUpService(string item, Player* player);
    bool execute();
    
private:
    PickUpService();
    
    string item_;
    Player* player_;
};

#endif
