

#ifndef TextAdventure_newGame_h
#define TextAdventure_newGame_h

#include <string>
#include "menuOption.h"
using std::string;

class NewGame: public MenuOption {
    
public:
    
    static NewGame& instance();
    virtual string name();
    
private:
    
    NewGame() {};
    NewGame(NewGame const&) = delete;
    void operator=(NewGame const&) = delete;
    
    static const string NAME;
};

#endif
