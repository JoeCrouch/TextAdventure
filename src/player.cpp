
#include "player.h"
#include <iostream>
using std::cout;
using std::endl;
using std::remove;
using std::find;

Player::Player(string name, Location* location) :
    name_(name),
    location_(location),
availableActions_(vector<Action> {Action::MOVE, Action::PICK_UP, Action::DROP, Action::PRINT, Action::QUIT}),
    items_(vector<Item> {}){
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
    return availableActions_;
}

vector<Item> Player::getItems() {
    return items_;
}

void Player::pickUpItem(Item item) {
    // TODO: logic around how much can carry. Deal with multiple versions of an item.
    items_.push_back(item);
}

void Player::dropItem(Item item) {
    if(find(items_.begin(), items_.end(), item) != items_.end()) {
        items_.erase(remove(items_.begin(), items_.end(), item), items_.end());
    }
}
