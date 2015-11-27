
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

bool targetCanBeTalkedTo(string target, vector<Character> availableCharacters);
string genericMessage();

const map<string, string> theScript = {
    {StringManager::toUpperCase("Steve The Sarcastic Somali Pirate"), "Blarrrr Blarrr Blarrr I'm a pirate!"},
    {StringManager::toUpperCase("Neighbourhoods Friendly Spider"), "Blah Blah Blah I'm a spider"}
};

TalkToService::TalkToService(string target, Location* location) : target_(target), location_(location) {
    
}

bool TalkToService::execute() {
    if (target_.length() == 0) {
        cout << endl << "Who would you like to talk to?" << endl;
        getline(cin, target_);
    }
    
    vector<Character> availableCharacters = location_->getCharacters();
    
    if (targetCanBeTalkedTo(target_, availableCharacters)) {
        map<string, string>::const_iterator pos = theScript.find(StringManager::toUpperCase(target_));
        
        if (pos == theScript.end()) {
            cout << endl << target_ + ": " + genericMessage() << endl;
        } else {
            string speech = pos->second;
            cout << endl << target_ + ": " + speech << endl;
        }
    } else {
        cout << target_ + " cannot be spoken to. Try using 'view location' to see characters available to speak to." << endl;
    }
    
    return false;
}

bool targetCanBeTalkedTo(string target, vector<Character> availableCharacters) {
    
    for (vector<Character>::iterator it = availableCharacters.begin(); it != availableCharacters.end(); it++) {
        if (StringManager::equalIgnoreCase(target, (*it).getName())) {
            return true;
        }
    }
    
    return false;
}

string genericMessage() {
    return " Fuck Off I'm Busy! Where Do You Get Off Walking Up To Strangers And Demanding A Conversation?";
}