
#include "pickUpService.h"
#include "location.h"
#include "player.h"
#include "item.h"
#include "stringManager.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

PickUpService::PickUpService(string item, Player* player) : item_(item), player_(player) {
    
}

bool PickUpService::execute() {
    if (item_.length() == 0) {
        cout << endl << "What would you like to pick up?" << endl;
        getline(cin, item_);
    }
    if (Item::isValidItem(item_)) {
        Item const * item = Item::getItem(item_);
        
        Location* location = player_->getLocation();
        
        vector<Item const *> availableItems = location->getItems();
        
        
        if(find(availableItems.begin(), availableItems.end(), item) != availableItems.end()) {
            player_->pickUpItem(item);
            location->removeItem(item);
            
            cout << endl << player_->getName() + " picked up " + item->getName() << endl;
            
        }
        else {
            if (availableItems.size() > 0) {
                cout << endl << item_ + " is not available to pick up. The items at " + location->getName() + " are:" << endl;
                for (vector<Item const *>::iterator it = availableItems.begin(); it != availableItems.end(); it++) {
                    cout << (*it)->getName() << endl;
                }
            } else {
                cout << endl << location->getName() + " has no items to pick up." << endl;
            }
        }
    } else {
        cout << endl << item_ + " is not a valid item" << endl;
    }
    
    return false;
}