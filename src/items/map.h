
#ifndef TextAdventure_map_h
#define TextAdventure_map_h

#include "item.h"
#include <string>
using std::string;

class Map: public Item {
public:
    static Map const * INSTANCE;
    
    virtual void use(Player* player) const;
    
private:
    Map();
};

#endif
