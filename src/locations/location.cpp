
#include "location.h"
#include "player.h"
#include <stdexcept>
using std::invalid_argument;

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
    if (yPosition_ > location.yPosition_){
        return true;
    } else if (yPosition_ < location.yPosition_) {
        return false;
    } else {
        return xPosition_ < location.xPosition_;
    }
}

bool Location::isAt(int x, int y) {
    return xPosition_ == x && yPosition_ == y;
}
