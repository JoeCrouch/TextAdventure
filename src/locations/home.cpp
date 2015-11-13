
#include "home.h"
#include "player.h"
#include "item.h"
#include "map.h"
#include <vector>
using std::to_string;
using std::vector;

int visitNumber = 1;
const string Home::NAME = "Home";

Home::Home() : Location(1, 1, NAME, vector<Item const *> {Map::INSTANCE}) {
    
}

string Home::getEntranceMessage(Player player) {
    return player.getName() + " has visited home " + to_string(visitNumber++) + " times";
}
