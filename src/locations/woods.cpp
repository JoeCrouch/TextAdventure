
#include "woods.h"
#include "player.h"

bool firstVisit = true;

const string Woods::NAME = "Woods";

Woods::Woods() : Location(2, 1, NAME) {
    
}

string Woods::getEntranceMessage(Player player) {
    
    if (firstVisit) {
        firstVisit = false;
        return "This is your first visit to the woods";
    } else {
        return "This is not your first visit to the woods";
    }
}
