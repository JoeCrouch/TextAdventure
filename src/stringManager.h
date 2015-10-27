

#ifndef TextAdventure_stringManager_h
#define TextAdventure_stringManager_h

#include <string>
using std::string;

class StringManager {
    
public:
    static string toUpperCase(string theString);
    static string repeatedSymbol(int length, string symbol);
    static bool equalIgnoreCase(string string1, string string2);
    static string centerLine(int length, string centerText, string border);
    
private:
    StringManager() {};
    StringManager(StringManager const&) = delete;
    void operator=(StringManager const&) = delete;
};

#endif
