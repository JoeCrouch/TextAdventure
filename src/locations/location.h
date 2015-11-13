
#ifndef TextAdventure_location_h
#define TextAdventure_location_h

class Player;

#include <string>
#include <vector>
#include "item.h"
using std::string;
using std::vector;

class Location {
    
public:
    string getName();
    int getXPosition();
    int getYPosition();
    vector<Item const *> getItems();
    
    void removeItem(Item const * item);
    void addItem(Item const * item);
    
    bool operator == (const Location& location);
    bool operator < (const Location& location) const;
    bool isAt(int x, int y);
    virtual string getEntranceMessage(Player player) = 0;
    
    Location(int x, int y, string name);
    Location(int x, int y, string name, vector<Item const *>);
    
private:
    Location() {};
    
    int xPosition_;
    int yPosition_;
    string name_;
    vector<Item const *> items_;
};

#endif
