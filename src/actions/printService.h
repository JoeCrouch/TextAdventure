
#ifndef TextAdventure_printService_h
#define TextAdventure_printService_h

#include "actionService.h"
#include "player.h"
#include <string>
using std::string;

class PrintService: public ActionService {
public:
    PrintService(string printTarget, Player player);
    bool execute();
    
private:
    PrintService();
    
    string printTarget_;
    Player player_;
};

#endif
