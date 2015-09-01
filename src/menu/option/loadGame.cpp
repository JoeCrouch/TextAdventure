
#include <iostream>
#include "loadGame.h"
using std::cout;
using std::endl;

LoadGame& LoadGame::instance() {
    static LoadGame instance;
    return instance;
}

string LoadGame::name() {
    return LoadGame::NAME;
}

void LoadGame::apply() {
    cout << endl << "Sorry we don't currently support " + name() + " :( " << endl;
}

const string LoadGame::NAME = string("Load Game");
