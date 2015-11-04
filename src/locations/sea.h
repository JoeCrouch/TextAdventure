#ifndef TextAdventure_sea_h
#define TextAdventure_sea_h

#include "location.h"
#include <string>
using std::string;

class Sea: public Location {
    
public:
    Sea();
    
    string getEntranceMessage(Player player);
    
private:
    static const string NAME;
};

#endif
