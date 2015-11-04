
#include "mountain.h"
#include "player.h"

const string Mountain::NAME = "Mountain";

Mountain::Mountain() : Location(1, 2, NAME) {
    
}

string Mountain::getEntranceMessage(Player player) {
    return string(player.getName() + " enters " + getName());
}
