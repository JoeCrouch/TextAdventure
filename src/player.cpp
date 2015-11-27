
#include "player.h"
#include <iostream>
using std::cout;
using std::endl;
using std::remove;
using std::find;

const vector<Action> COMMON_ACTIONS = vector<Action> {Action::MOVE, Action::PICK_UP, Action::DROP, Action::USE, Action::VIEW, Action::TALK_TO, Action::QUIT};

Player::Player(string name, Location* location) :
    name_(name),
    location_(location),
    items_(vector<Item const *> {}){
}

void Player::printPlayerCharacteristics() {
    cout << endl << "Name: " + name_ << endl;
}

string Player::getName() {
    return name_;
}

Location* Player::getLocation() {
    return location_;
}

void Player::moveTo(Location* location) {
    location_ = location;
}

string Player::getLocationName() {
    return location_->getName();
}

vector<Action> Player::getAvailableActions() {
    return COMMON_ACTIONS;
}

vector<Item const *> Player::getItems() {
    return items_;
}

void Player::pickUpItem(Item const * item) {
    // TODO: logic around how much can carry. Deal with multiple versions of an item.
    items_.push_back(item);
}

void Player::dropItem(Item const * item) {
    if(find(items_.begin(), items_.end(), item) != items_.end()) {
        items_.erase(remove(items_.begin(), items_.end(), item), items_.end());
    }
}
