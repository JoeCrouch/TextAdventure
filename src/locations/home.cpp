
#include "home.h"
#include "player.h"
using std::to_string;

int visitNumber = 1;
const string Home::NAME = "Home";

Home::Home() : Location(1, 1, NAME) {
    
}

string Home::getEntranceMessage(Player player) {
    return player.getName() + " has visited home " + to_string(visitNumber++) + " times";
}
