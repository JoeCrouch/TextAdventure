

#ifndef TextAdventure_loadGame_h
#define TextAdventure_loadGame_h

#include <string>
#include "menuOption.h"
using std::string;

class LoadGame: public MenuOption {
public:
    
    static LoadGame& instance();
    string name();
    Game* buildGame();
    
private:
    
    LoadGame() {};
    LoadGame(LoadGame const&) = delete;
    void operator=(LoadGame const&) = delete;
    
    static const string NAME;
};

#endif
