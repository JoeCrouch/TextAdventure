
#ifndef TextAdventure_game_h
#define TextAdventure_game_h

class Location;
class Direction;

#include "player.h"
#include <vector>
using std::vector;

class Game {
    Player player;
    
public:
    Game(Player player);
    void play();
    static const vector<Location> LOCATIONS;
    
private:
    Game();
};

#endif
