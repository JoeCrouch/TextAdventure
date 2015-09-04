
#ifndef TextAdventureXCode_player_h
#define TextAdventureXCode_player_h

#include <string>
#include "location.h"
using std::string;

class Player {
public:
    Player(string name, Location location);
    
    void printPlayerCharacteristics();
    string getName();
    string getLocationName();
    
private:
    Player();
    
    string name;
    Location location;
};

#endif
