
#include "useService.h"
#include "item.h"
#include "player.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

UseService::UseService(string item, Player* player) : item_(item), player_(player) {
    
}

bool UseService::execute() {
    if (item_.length() == 0) {
        cout << endl << "What would you like to use?" << endl;
        getline(cin, item_);
    }
    
    if (Item::isValidItem(item_)) {
        Item const * item = Item::getItem(item_);
        
        vector<Item const *> availableItems = player_->getItems();
        
        
        if(find(availableItems.begin(), availableItems.end(), item) != availableItems.end()) {
            player_->pickUpItem(item);
            
            item->use(player_);
        }
        else {
            cout << endl << player_->getName() + " does not have a " + item_ << endl;
        }
    } else {
        cout << endl << item_ + " is not a valid item" << endl;
    }

    
    return false;
}