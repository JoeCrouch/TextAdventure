
#ifndef TextAdventureXCode_game_h
#define TextAdventureXCode_game_h

#include "player.h"
#include "location.h"
#include "direction.h"
#include <vector>
using std::vector;

class Game {
    Player player;
    
public:
    Game(Player player);
    void play();
    
private:
    Game();
    
    static const vector<Location> LOCATIONS;
    
    void movePlayer(Direction dir);
};

#endif
