#ifndef TextAdventure_woods_h
#define TextAdventure_woods_h

#include "location.h"
#include <string>
using std::string;

class Woods: public Location {
    
public:
    Woods();
    
    string getEntranceMessage(Player player);
    
private:
    static const string NAME;
};

#endif
