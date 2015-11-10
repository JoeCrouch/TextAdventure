
#include "home.h"
#include "player.h"
#include "item.h"
#include <vector>
using std::to_string;
using std::vector;

int visitNumber = 1;
const string Home::NAME = "Home";

Home::Home() : Location(1, 1, NAME, vector<Item> {Item::MAP}) {
    
}

string Home::getEntranceMessage(Player player) {
    return player.getName() + " has visited home " + to_string(visitNumber++) + " times";
}
