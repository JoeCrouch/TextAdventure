
#include "player.h"
#include <iostream>
using std::cout;
using std::endl;

Player::Player(string name) : name(name) {
}

void Player::printPlayerCharacteristics() {
    cout << endl << "Name: " + name << endl;
}
