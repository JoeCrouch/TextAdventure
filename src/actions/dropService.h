
#ifndef TextAdventure_dropService_h
#define TextAdventure_dropService_h

#include "actionService.h"
#include <string>
using std::string;

class DropService: public ActionService {
public:
    DropService(string item, Player* player);
    bool execute();
    
private:
    DropService();
    
    string item_;
    Player* player_;
};

#endif
