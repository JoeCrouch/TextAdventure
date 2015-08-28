

#include "newGame.h"

NewGame& NewGame::instance() {
    static NewGame instance;
    return instance;
}

string NewGame::name() {
    return NewGame::NAME;
}

const string NewGame::NAME = string("New Game");
