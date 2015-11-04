
#include "sea.h"
#include "stringManager.h"
#include "player.h"

const string Sea::NAME = "Sea";

Sea::Sea() : Location(0, 1, NAME) {
    
}

string Sea::getEntranceMessage(Player player) {
    if (StringManager::equalIgnoreCase(player.getName(), "Captain BananaBeard")) {
        return player.getName() + " gets on a boat and sails around a bit";
    } else {
        return string(player.getName() + " enters " + getName());
    }
}
