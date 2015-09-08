
#include "stringManager.h"

string StringManager::toUpperCase(string theString) {
    string stringCopy = theString;
    std::transform(theString.begin(), theString.end(), stringCopy.begin(), ::toupper);
    return stringCopy;
}

string StringManager::repeatedSymbol(int length, string symbol) {
    string repeatedSymbolString = string("");
    
    for (int i = 0; i < length; i ++) {
        repeatedSymbolString += symbol;
    }
    
    return repeatedSymbolString;
}

bool StringManager::equalIgnoreCase(string string1, string string2) {
    string string1Upper = toUpperCase(string1);
    string string2Upper = toUpperCase(string2);
    
    return string1Upper.compare(string2Upper) == 0;
}
