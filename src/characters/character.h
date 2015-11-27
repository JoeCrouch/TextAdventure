
#ifndef TextAdventure_character_h
#define TextAdventure_character_h

#include <string>
using std::string;

class Character {
    
public:
    Character(string name);
    
    string getName();
    
private:
    Character();
    
    string name_;
};


#endif
