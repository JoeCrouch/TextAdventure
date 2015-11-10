
#ifndef TextAdventure_item_h
#define TextAdventure_item_h

#include <string>
using std::string;

class Item {
public:
    static const Item MAP;
    
    string getName();
    
    static bool isValidItem(string item);
    static Item getItem(string itemName);
    
    bool operator < (const Item& item) const;
    bool operator == (const Item& item) const;
    
private:
    Item() {};
    Item(string name);
    
    string name_;
};


#endif
