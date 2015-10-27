

#ifndef TextAdventure_mainMenu_h
#define TextAdventure_mainMenu_h

#include <vector>
#include <string>
#include "newGame.h"
#include "loadGame.h"
using std::vector;
using std::string;

class MainMenu {
public:
    
    static MainMenu& instance();
    void printTitle();
    void printMenuOptions();
    MenuOption* readOption();
    
private:
    MainMenu() {};
    MainMenu(MainMenu const&) = delete;
    void operator=(MainMenu const&) = delete;

    static const int MENU_WIDTH;
    static const vector<MenuOption*> MENU_OPTIONS;

    void printRepeatInputMessage(int entryFailures);
};

#endif
