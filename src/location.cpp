
#include "location.h"

const Location Location::HOME = Location(0, 0, "Home");
const Location Location::WOODS = Location(1, 0, "Woods");
const Location Location::SEA = Location(-1, 0, "Sea");
const Location Location::MOUNTAIN = Location(0, 1, "Mountain");
const Location Location::DESERT = Location(0, -1, "Desert");

Location::Location(int x, int y, string name) : xPosition_(x), yPosition_(y), name_(name) {
}

string Location::getName() {
    return name_;
}

int Location::getXPosition() {
    return xPosition_;
}

int Location::getYPosition() {
    return yPosition_;
}

bool Location::operator==(const Location& location) {
    return xPosition_ == location.xPosition_ && yPosition_ == location.yPosition_;
}

bool Location::isAt(int x, int y) {
    return xPosition_ == x && yPosition_ == y;
}
