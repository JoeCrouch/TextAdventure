#ifndef TextAdventure_desert_h
#define TextAdventure_desert_h

#include "location.h"
#include <string>
using std::string;

class Desert: public Location {
    
public:
    Desert();
    
    string getEntranceMessage(Player player);
    
private:
    static const string NAME;
};

#endif
