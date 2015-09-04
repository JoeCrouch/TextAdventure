
#include "direction.h"

const Direction Direction::NORTH = Direction(1, 0);
const Direction Direction::SOUTH = Direction(-1, 0);
const Direction Direction::EAST = Direction(0, 1);
const Direction Direction::WEST = Direction(0, -1);

Direction::Direction(int x, int y) : xDirection_(x), yDirection_(y) {
}

int Direction::getXDirection() {
    return xDirection_;
}

int Direction::getYDirection() {
    return yDirection_;
}