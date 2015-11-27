
#include "sea.h"
#include "stringManager.h"
#include "player.h"
#include "character.h"

const string Sea::NAME = "Sea";

Sea::Sea() : Location(0, 1, NAME, vector<Character> {Character("Steve The Sarcastic Somali Pirate"), Character("Someone Minding Thier Own Business")}) {
    
}

string Sea::getEntranceMessage(Player player) {
    if (StringManager::equalIgnoreCase(player.getName(), "Captain BananaBeard")) {
        return player.getName() + " gets on a boat and sails around a bit";
    } else {
        return string(player.getName() + " enters " + getName());
    }
}
