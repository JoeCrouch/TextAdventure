#ifndef TextAdventure_mountain_h
#define TextAdventure_mountain_h

#include "location.h"
#include <string>
using std::string;

class Mountain: public Location {
    
public:
    Mountain();
    
    string getEntranceMessage(Player player);
    
private:
    static const string NAME;
};

#endif
