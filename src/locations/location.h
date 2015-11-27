
#ifndef TextAdventure_location_h
#define TextAdventure_location_h

class Player;

#include <string>
#include <vector>
#include "item.h"
#include "character.h"
using std::string;
using std::vector;

class Location {
    
public:
    string getName();
    int getXPosition();
    int getYPosition();
    vector<Item const *> getItems();
    vector<Character> getCharacters();
    
    void removeItem(Item const * item);
    void addItem(Item const * item);
    
    bool operator == (const Location& location);
    bool operator < (const Location& location) const;
    bool isAt(int x, int y);
    virtual string getEntranceMessage(Player player) = 0;
    
    Location(int x, int y, string name);
    Location(int x, int y, string name, vector<Item const *> items);
    Location(int x, int y, string name, vector<Character> characters);
    Location(int x, int y, string name, vector<Item const *> items, vector<Character> characters);
    
private:
    Location() {};
    
    int xPosition_;
    int yPosition_;
    string name_;
    vector<Item const *> items_;
    vector<Character> characters_;
};

#endif
