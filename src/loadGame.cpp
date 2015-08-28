
#include "loadGame.h"

LoadGame& LoadGame::instance() {
    static LoadGame instance;
    return instance;
}

string LoadGame::name() {
    return LoadGame::NAME;
}

const string LoadGame::NAME = string("Load Game");
