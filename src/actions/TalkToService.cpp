
#include "TalkToService.h"
#include "location.h"
#include "character.h"
#include "stringManager.h"
#include <map>
#include <iostream>
using std::map;
using std::cout;
using std::cin;
using std::endl;

bool targetCanBeTalkedTo(Character character, vector<Character> availableCharacters);
string genericMessage();

const map<Character, string> theScript = {
    {Character::STEVE_THE_SARCASTIC_SOMALI_PIRATE, "Blarrrr Blarrr Blarrr I'm a pirate!"},
    {Character::NEIGHBOURHOODS_FRIENDLY_SPIDER, "Blah Blah Blah I'm a spider"}
};

TalkToService::TalkToService(string target, Location* location) : target_(target), location_(location) {
    
}

bool TalkToService::execute() {
    if (target_.length() == 0) {
        cout << endl << "Who would you like to talk to?" << endl;
        getline(cin, target_);
    }
    
    if (Character::isValid(target_)) {
        
        Character character = Character::getCharacter(target_);
        vector<Character> availableCharacters = location_->getCharacters();
        
        if (targetCanBeTalkedTo(character, availableCharacters)) {
            map<Character, string>::const_iterator pos = theScript.find(character);
            
            if (pos == theScript.end()) {
                cout << endl << target_ + ": " + genericMessage() << endl;
            } else {
                string speech = pos->second;
                cout << endl << target_ + ": " + speech << endl;
            }
        } else {
            cout << target_ + " cannot be spoken to. Try using 'view location' to see characters available to speak to." << endl;
        }
    } else {
        cout << endl << target_ + " is not a valid character" << endl;
    }
    
    return false;
}

bool targetCanBeTalkedTo(Character character, vector<Character> availableCharacters) {
    return find(availableCharacters.begin(), availableCharacters.end(), character) != availableCharacters.end();
}

string genericMessage() {
    return " Fuck Off I'm Busy! Where Do You Get Off Walking Up To Strangers And Demanding A Conversation?";
}