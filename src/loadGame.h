

#ifndef TextAdventure_loadGame_h
#define TextAdventure_loadGame_h

#include "menuOption.h"
using std::string;

class LoadGame: public MenuOption {
public:
    
    static LoadGame& instance() {
        static LoadGame instance;
        return instance;
    }
    
    virtual string name() {
        return NAME;
    }
    
private:
    LoadGame() {};
    LoadGame(LoadGame const&) = delete;
    void operator=(LoadGame const&) = delete;
    
    static const string NAME;
};

const string LoadGame::NAME = string("Load Game");

#endif
