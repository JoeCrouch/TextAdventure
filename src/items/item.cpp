

#include "item.h"
#include "map.h"
#include "stringManager.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

Item::Item(string name) : name_(name) {
    
}

vector<Item const *> availableItems();

string Item::getName() const {
    return name_;
}

bool Item::isValidItem(string itemName) {
    for (int i = 0; i < availableItems().size(); i++) {
        Item const * item = availableItems()[i];
        if (StringManager::equalIgnoreCase(itemName, item->getName())) {
            return true;
        }
    }
    return false;
}

const Item* Item::getItem(string itemName) {
    for (int i = 0; i < availableItems().size(); i++) {
        Item const * item = availableItems()[i];
        if (StringManager::equalIgnoreCase(itemName, item->getName())) {
            return item;
        }
    }
    
    cout << endl << "ERROR: not valid item with name " + itemName;
    throw -1;
}

bool Item::operator < (const Item& item) const {
    return name_ < item.name_;
}

bool Item::operator == (const Item& item) const {
    return name_ == item.name_;
}

vector<Item const *> availableItems() {
    return vector<Item const *> {Map::INSTANCE};
}