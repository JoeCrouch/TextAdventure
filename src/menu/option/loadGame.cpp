
#include <iostream>
#include <stdlib.h>
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

Game* LoadGame::buildGame() {
    cout << endl << "Sorry we don't currently support " + name() + " :( " << endl;
    exit(EXIT_SUCCESS);
    return NULL;
}

const string LoadGame::NAME = string("Load Game");
