

#ifndef TextAdventure_saveGame_h
#define TextAdventure_saveGame_h

#include "menuOption.h"
using std::string;

class SaveGame: public MenuOption {
public:
    
    static SaveGame& instance() {
        static SaveGame instance;
        return instance;
    }
    
    virtual string name() {
        return NAME;
    }
    
private:
    SaveGame() {};
    SaveGame(SaveGame const&) = delete;
    void operator=(SaveGame const&) = delete;
    
    static const string NAME;
};

const string SaveGame::NAME = string("Save Game");

#endif
