
#include "dropService.h"
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

DropService::DropService(string item, Player* player) : item_(item), player_(player) {
    
}

bool DropService::execute() {
    if (item_.length() == 0) {
        cout << endl << "What would you like to drop?" << endl;
        getline(cin, item_);
    }
    if (Item::isValidItem(item_)) {
        Item const * item = Item::getItem(item_);
        
        Location* location = player_->getLocation();
        
        vector<Item const *> availableItems = player_->getItems();
        
        
        if(find(availableItems.begin(), availableItems.end(), item) != availableItems.end()) {
            player_->dropItem(item);
            location->addItem(item);
            
            cout << endl << player_->getName() + " dropped " + item->getName() << endl;
            
        }
        else {
            if (availableItems.size() > 0) {
                cout << endl << player_->getName() + " does not have a " + item_ + ". Try one of:" << endl;
                for (vector<Item const *>::iterator it = availableItems.begin(); it != availableItems.end(); it++) {
                    cout << (*it)->getName() << endl;
                }
            } else {
                cout << endl << player_->getName() + " has no items to drop." << endl;
            }
        }
    } else {
        cout << endl << item_ + " is not a valid item" << endl;
    }
    
    return false;
}
