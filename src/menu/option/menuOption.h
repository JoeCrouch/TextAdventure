
#ifndef TextAdventure_menuOption_h
#define TextAdventure_menuOption_h

#include <string>
using std::string;

class MenuOption {
public:
    virtual string name() = 0;
    virtual void apply() = 0;
};

#endif
