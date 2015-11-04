#ifndef TextAdventure_home_h
#define TextAdventure_home_h

#include "location.h"
#include <string>
using std::string;

class Home: public Location {
    
public:
    Home();
    
    virtual string getEntranceMessage(Player player);
    
private:
    static const string NAME;
};

#endif
