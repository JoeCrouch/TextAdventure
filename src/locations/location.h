
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
    vector<Item> getItems();
    
    void removeItem(Item item);
    void addItem(Item item);
    
    bool operator == (const Location& location);
    bool operator < (const Location& location) const;
    bool isAt(int x, int y);
    virtual string getEntranceMessage(Player player) = 0;
    
    Location(int x, int y, string name);
    Location(int x, int y, string name, vector<Item>);
    
private:
    Location() {};
    
    int xPosition_;
    int yPosition_;
    string name_;
    vector<Item> items_;
};

#endif
