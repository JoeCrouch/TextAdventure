
#ifndef TextAdventureXCode_location_h
#define TextAdventureXCode_location_h

#include <string>
using std::string;

class Location {
    
public:
    static const Location HOME;
    
    string getName();
    
private:
    Location() {};
    void operator=(Location const&) = delete;
    
    Location(int x, int y, string name);
    
    int xPosition;
    int yPosition;
    string name;
};

#endif
