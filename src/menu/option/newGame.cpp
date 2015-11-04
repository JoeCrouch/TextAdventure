
#include <iostream>
#include "game.h"
#include "home.h"
#include "newGame.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;

NewGame& NewGame::instance() {
    static NewGame instance;
    return instance;
}

string NewGame::name() {
    return NewGame::NAME;
}

Game* NewGame::buildGame() {
    // TODO: give option to say entry is not valid.
    cout << endl << "Whats your characters name? " << endl;
    string characterName;
    getline(cin, characterName);
    
    Player player = Player(characterName, new Home());
    
    return new Game(player);
}

const string NewGame::NAME = string("New Game");
