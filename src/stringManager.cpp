
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

string StringManager::centerLine(int length, string centerText, string border) {
    int centerTextLength = (int) centerText.size();
    int borderLength = (int) border.size();
    
    int totalWhiteSpaceLength = length - centerTextLength - (2 * borderLength);
    int firstWhiteSpaceLength = totalWhiteSpaceLength / 2;
    int secondWhiteSpaceLength = firstWhiteSpaceLength + totalWhiteSpaceLength % 2;
    string centerLine =
    border +
    repeatedSymbol(firstWhiteSpaceLength, " ") +
    centerText +
    repeatedSymbol(secondWhiteSpaceLength, " ") +
    border;
    
    return centerLine;
}
