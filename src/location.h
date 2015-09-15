
#ifndef TextAdventure_location_h
#define TextAdventure_location_h

#include <string>
using std::string;

class Location {
    
public:
    static const Location HOME;
    static const Location WOODS;
    static const Location SEA;
    static const Location MOUNTAIN;
    static const Location DESERT;
    
    string getName();
    int getXPosition();
    int getYPosition();
    bool operator == (const Location& location);
    bool isAt(int x, int y);
    
private:
    Location() {};
    
    Location(int x, int y, string name);
    
    int xPosition_;
    int yPosition_;
    string name_;
};

#endif
