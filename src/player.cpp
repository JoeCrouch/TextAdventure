
#include "player.h"
#include <iostream>
using std::cout;
using std::endl;

Player::Player(string name, Location location) :
    name_(name),
    location_(location),
    availableActions_(vector<Action> {Action::MOVE, Action::PRINT_ACTIONS, Action::QUIT}) {
}

void Player::printPlayerCharacteristics() {
    cout << endl << "Name: " + name_ << endl;
}

string Player::getName() {
    return name_;
}

Location Player::getLocation() {
    return location_;
}

void Player::moveTo(Location location) {
    location_ = location;
}

string Player::getLocationName() {
    return location_.getName();
}

vector<Action> Player::getAvailableActions() {
    return availableActions_;
}
