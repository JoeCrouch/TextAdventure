
#include "direction.h"
#include "stringManager.h"

const Direction Direction::NORTH = Direction(1, 0, "north");
const Direction Direction::SOUTH = Direction(-1, 0, "south");
const Direction Direction::EAST = Direction(0, 1, "east");
const Direction Direction::WEST = Direction(0, -1, "west");

Direction::Direction(int x, int y, string name) : xDirection_(x), yDirection_(y), name_(name) {
}

const Direction* Direction::getDirection(string direction) {
    
    if (StringManager::equalIgnoreCase(direction, NORTH.name_)) {
        return &(NORTH);
    } else if (StringManager::equalIgnoreCase(direction, SOUTH.name_)) {
        return &(SOUTH);
    } else if (StringManager::equalIgnoreCase(direction, EAST.name_)) {
        return &(EAST);
    } else if (StringManager::equalIgnoreCase(direction, WEST.name_)) {
        return &(WEST);
    }
    
    return NULL;
}

int Direction::getXDirection() const {
    return xDirection_;
}

int Direction::getYDirection() const {
    return yDirection_;
}

string Direction::getName() const {
    return name_;
}