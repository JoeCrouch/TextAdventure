
#ifndef TextAdventure_menuOption_h
#define TextAdventure_menuOption_h

class Game;

#include <string>
using std::string;

class MenuOption {
public:
    virtual string name() = 0;
    virtual Game* buildGame() = 0;
};

#endif
