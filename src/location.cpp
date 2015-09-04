
#include "location.h"

const Location Location::HOME = Location(0, 0, "Home");

Location::Location(int x, int y, string name) : xPosition(x), yPosition(y), name(name) {
}

string Location::getName() {
    return name;
}
