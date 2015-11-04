
#include "desert.h"
#include "player.h"

const string Desert::NAME = "Desert";

Desert::Desert() : Location(1, 0, NAME) {
    
}

string Desert::getEntranceMessage(Player player) {
    return string(player.getName() + " enters " + getName());
}
