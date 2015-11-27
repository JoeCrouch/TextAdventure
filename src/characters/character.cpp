
#include "character.h"
#include "stringManager.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

vector<Character> availableCharacters();

Character::Character(string name) : name_(name) {
    
}

const Character Character::NEIGHBOURHOODS_FRIENDLY_SPIDER = Character("Neighbourhoods Friendly Spider");
const Character Character::STEVE_THE_SARCASTIC_SOMALI_PIRATE = Character("Steve The Sarcastic Somali Pirate");
const Character Character::SOMEONE_MINDING_THEIR_OWN_BUSINESS = Character("Someone Minding Their Own Business");

string Character::getName() {
    return name_;
}

bool Character::isValid(string characterName) {
    for (int i = 0; i < availableCharacters().size(); i++) {
        Character character = availableCharacters()[i];
        if (StringManager::equalIgnoreCase(characterName, character.getName())) {
            return true;
        }
    }
    return false;
}

Character Character::getCharacter(string characterName) {
    for (int i = 0; i < availableCharacters().size(); i++) {
        Character character = availableCharacters()[i];
        if (StringManager::equalIgnoreCase(characterName, character.getName())) {
            return character;
        }
    }
    
    cout << endl << "ERROR: not valid character with name " + characterName << endl;
    throw -1;
}

bool Character::operator < (const Character& character) const {
    return name_ < character.name_;
}

bool Character::operator == (const Character& character) const {
    return name_ == character.name_;
}

vector<Character> availableCharacters() {
    return vector<Character> {
        Character::NEIGHBOURHOODS_FRIENDLY_SPIDER,
        Character::STEVE_THE_SARCASTIC_SOMALI_PIRATE,
        Character::SOMEONE_MINDING_THEIR_OWN_BUSINESS
    };
}
