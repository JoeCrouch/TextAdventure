
#ifndef TextAdventure_useService_h
#define TextAdventure_useService_h

#include "actionService.h"
#include <string>
using std::string;

class UseService: public ActionService {
public:
    UseService(string item, Player* player);
    bool execute();
    
private:
    UseService();
    
    string item_;
    Player* player_;
};

#endif
