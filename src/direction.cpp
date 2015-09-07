
#include "direction.h"

const Direction Direction::NORTH = Direction(1, 0);
const Direction Direction::SOUTH = Direction(-1, 0);
const Direction Direction::EAST = Direction(0, 1);
const Direction Direction::WEST = Direction(0, -1);

Direction::Direction(int x, int y) : xDirection_(x), yDirection_(y) {
}

const Direction* Direction::getDirection(string direction) {
    if (direction.compare("north") == 0) {
        return &(NORTH);
    } else if (direction.compare("south") == 0) {
        return &(SOUTH);
    } else if (direction.compare("east") == 0) {
        return &(EAST);
    } else if (direction.compare("west") == 0) {
        return &(WEST);
    }
    
    return NULL;
}

int Direction::getXDirection() {
    return xDirection_;
}

int Direction::getYDirection() {
    return yDirection_;
}