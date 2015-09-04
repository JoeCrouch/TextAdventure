
#include "player.h"
#include <iostream>
using std::cout;
using std::endl;

Player::Player(string name, Location location) : name(name), location(location) {
}

void Player::printPlayerCharacteristics() {
    cout << endl << "Name: " + name << endl;
}

string Player::getName() {
    return name;
}

string Player::getLocationName() {
    return location.getName();
}
