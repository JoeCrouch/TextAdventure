
#include "invalidActionService.h"
#include <iostream>
using std::cout;
using std::endl;

InvalidActionService::InvalidActionService(string input) : invalidActionString_(input) {
}

bool InvalidActionService::execute(Player* player) {
    //TODO: implement printing actions
    cout << "'" + invalidActionString_ + "' is not a valid action. For a list of valid actions choose 'print actions'" << endl;
    return false;
}