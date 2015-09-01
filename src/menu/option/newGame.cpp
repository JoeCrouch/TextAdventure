
#include <iostream>
#include "newGame.h"
using std::cout;
using std::endl;

NewGame& NewGame::instance() {
    static NewGame instance;
    return instance;
}

string NewGame::name() {
    return NewGame::NAME;
}

void NewGame::apply() {
    cout << endl << "some " + name() + " stuff should probably create a player etc." << endl;
}

const string NewGame::NAME = string("New Game");
