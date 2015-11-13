
#include "invalidActionService.h"
#include <iostream>
using std::cout;
using std::endl;

InvalidActionService::InvalidActionService(string input) : invalidActionString_(input) {
}

bool InvalidActionService::execute() {
    cout << endl << "'" + invalidActionString_ + "' is not a valid action. For a list of valid actions choose 'view actions'" << endl;
    return false;
}