

#ifndef TextAdventure_newGame_h
#define TextAdventure_newGame_h

#include "menuOption.h"
using std::string;

class NewGame: public MenuOption {
public:
    
    static NewGame& instance() {
        static NewGame instance;
        return instance;
    }
    
    virtual string name() {
        return NAME;
    }
    
private:
    NewGame() {};
    NewGame(NewGame const&) = delete;
    void operator=(NewGame const&) = delete;
    
    static const string NAME;
};

const string NewGame::NAME = string("New Game");

#endif
