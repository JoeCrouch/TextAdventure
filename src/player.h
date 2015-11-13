
#ifndef TextAdventure_player_h
#define TextAdventure_player_h

#include "action.h"
#include <string>
#include <vector>
#include "location.h"
#include "item.h"

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
    vector<Item const *> getItems();
    void pickUpItem(Item const * item);
    void dropItem(Item const * item);
    
private:
    Player();
    
    //TODO: Health, Age, Tiredness, Hunger, Need to Poo etc. could impact game e.g. age has impact on number of moves before death or health etc.
    
    string name_;
    Location* location_;
    vector<Item const *> items_;
};

#endif
