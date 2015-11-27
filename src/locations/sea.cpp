
#include "sea.h"
#include "stringManager.h"
#include "player.h"
#include "character.h"

const string Sea::NAME = "Sea";

Sea::Sea() : Location(0, 1, NAME, vector<Character> {Character::STEVE_THE_SARCASTIC_SOMALI_PIRATE, Character::SOMEONE_MINDING_THEIR_OWN_BUSINESS}) {
    
}

string Sea::getEntranceMessage(Player player) {
    if (StringManager::equalIgnoreCase(player.getName(), "Captain BananaBeard")) {
        return player.getName() + " gets on a boat and sails around a bit";
    } else {
        return string(player.getName() + " enters " + getName());
    }
}
