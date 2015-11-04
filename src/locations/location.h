
#ifndef TextAdventure_location_h
#define TextAdventure_location_h

class Player;

#include <string>
using std::string;

class Location {
    
public:
    string getName();
    int getXPosition();
    int getYPosition();
    bool operator == (const Location& location);
    bool operator < (const Location& location) const;
    bool isAt(int x, int y);
    virtual string getEntranceMessage(Player player) = 0;
    
    Location(int x, int y, string name);
    
private:
    Location() {};
    
    int xPosition_;
    int yPosition_;
    string name_;
};

#endif
