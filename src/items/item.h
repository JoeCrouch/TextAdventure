
#ifndef TextAdventure_item_h
#define TextAdventure_item_h

class Player;

#include <string>
using std::string;

class Item {
public:
    string getName() const;
    
    static bool isValidItem(string item);
    static const Item* getItem(string itemName);
    
    bool operator < (const Item& item) const;
    bool operator == (const Item& item) const;
    
    virtual void use(Player* player) const = 0;
    
    Item(string name);
    
private:
    Item() {};
    
    string name_;
};


#endif
