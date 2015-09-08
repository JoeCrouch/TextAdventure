
#ifndef TextAdventure_player_h
#define TextAdventure_player_h

#include <string>
#include "location.h"
using std::string;

class Player {
public:
    Player(string name, Location location);
    
    void printPlayerCharacteristics();
    string getName();
    Location getLocation();
    void moveTo(Location location);
    string getLocationName();
    
private:
    Player();
    
    string name_;
    Location location_;
};

#endif
