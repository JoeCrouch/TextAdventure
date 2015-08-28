

#ifndef TextAdventure_mainMenu_h
#define TextAdventure_mainMenu_h

#include <vector>
#include <string>
#include <stdlib.h>
#include "newGame.h"
#include "loadGame.h"
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::vector;
using std::string;

string repeatedSymbol(int length, string symbol);
string centerLine(int length, string centerText, string border);

//TODO: Make a singleton
class MainMenu {
public:
    
    static void printTitle();
    static void printMenuOptions();
    static MenuOption* readOption();
    
private:
    MainMenu() {};
    MainMenu(MainMenu const&) = delete;
    void operator=(MainMenu const&) = delete;

    static const int MENU_WIDTH;
    static const vector<MenuOption*> MENU_OPTIONS;
    
    static string toUpperCase(string theString);
    static void printRepeatInputMessage(int entryFailures);
};

#endif
