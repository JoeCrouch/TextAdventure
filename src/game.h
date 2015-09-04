
#ifndef TextAdventureXCode_game_h
#define TextAdventureXCode_game_h

#include "player.h"

class Game {
    Player player;
    
public:
    Game(Player player);
    void play();
    
private:
    Game();
};

#endif
