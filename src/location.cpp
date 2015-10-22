
#include "location.h"
#include <stdexcept>
using std::invalid_argument;

const Location Location::HOME = Location(1, 1, "Home");
const Location Location::WOODS = Location(2, 1, "Woods");
const Location Location::SEA = Location(0, 1, "Sea");
const Location Location::MOUNTAIN = Location(1, 2, "Mountain");
const Location Location::DESERT = Location(1, 0, "Desert");

Location::Location(int x, int y, string name) : xPosition_(x), yPosition_(y), name_(name) {
    if (x < 0 || y < 0) {
        throw invalid_argument("Can't have negative coordinate (Just coz)");
    }
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

bool Location::operator<(const Location& location) const {
    if (yPosition_ < location.yPosition_){
        return true;
    } else if (yPosition_ > location.yPosition_) {
        return false;
    } else {
        return xPosition_ < location.xPosition_;
    }
}

bool Location::isAt(int x, int y) {
    return xPosition_ == x && yPosition_ == y;
}
