
#ifndef TextAdventure_character_h
#define TextAdventure_character_h

#include <string>
using std::string;

class Character {
    
public:
    static const Character NEIGHBOURHOODS_FRIENDLY_SPIDER;
    static const Character STEVE_THE_SARCASTIC_SOMALI_PIRATE;
    static const Character SOMEONE_MINDING_THEIR_OWN_BUSINESS;
    
    static bool isValid(string characterName);
    static Character getCharacter(string characterName);
    
    string getName();
    
    bool operator < (const Character& character) const;
    bool operator == (const Character& character) const;
    
private:
    Character();
    Character(string name);
    
    string name_;
};


#endif
