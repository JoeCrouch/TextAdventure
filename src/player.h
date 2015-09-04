
#ifndef TextAdventureXCode_player_h
#define TextAdventureXCode_player_h

#include <string>
using std::string;

class Player {
public:
    void printPlayerCharacteristics();
    Player(std::string name);
private:
    Player();
    std::string name;
};

#endif
