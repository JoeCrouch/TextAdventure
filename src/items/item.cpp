

#include "item.h"
#include "stringManager.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

Item::Item(string name) : name_(name) {
    
}

const Item Item::MAP = Item("Map");

const vector<Item> AVAILABLE_ITEMS = vector<Item> {Item::MAP};

string Item::getName() {
    return name_;
}

bool Item::isValidItem(string itemName) {
    for (int i = 0; i < AVAILABLE_ITEMS.size(); i++) {
        Item item = AVAILABLE_ITEMS[i];
        if (StringManager::equalIgnoreCase(itemName, item.getName())) {
            return true;
        }
    }
    return false;
}

Item Item::getItem(string itemName) {
    for (int i = 0; i < AVAILABLE_ITEMS.size(); i++) {
        Item item = AVAILABLE_ITEMS[i];
        if (StringManager::equalIgnoreCase(itemName, item.getName())) {
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