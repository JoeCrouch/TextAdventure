
#ifndef TextAdventure_printService_h
#define TextAdventure_printService_h

class Player;

#include "actionService.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class PrintService: public ActionService {
public:
    PrintService(string printTarget, vector<Action>);
    bool execute();
    
private:
    PrintService();
    
    string printTarget_;
    vector<Action> availableActions_;
};

#endif
