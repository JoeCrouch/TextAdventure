
#ifndef TextAdventure_printService_h
#define TextAdventure_printService_h

class Player;

#include "actionService.h"
#include <string>
using std::string;

class PrintService: public ActionService {
public:
    PrintService(string printTarget);
    bool execute(Player* player);
    
private:
    PrintService();
    
    string printTarget_;
};

#endif
