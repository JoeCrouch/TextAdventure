
#ifndef TextAdventure_player_h
#define TextAdventure_player_h

#include "action.h"
#include <string>
#include <vector>
#include "location.h"

using std::string;
using std::vector;

class Player {
public:
    Player(string name, Location* location);
    
    void printPlayerCharacteristics();
    string getName();
    Location* getLocation();
    void moveTo(Location* location);
    string getLocationName();
    vector<Action> getAvailableActions();
    
private:
    Player();
    
    string name_;
    Location* location_;
    vector<Action> availableActions_;
};

#endif
