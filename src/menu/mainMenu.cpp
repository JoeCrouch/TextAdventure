
#include <iostream>
#include <stdlib.h>
#include "mainMenu.h"
#include "stringManager.h"
using std::cout;
using std::endl;
using std::cin;
using std::getline;

MainMenu& MainMenu::instance() {
    static MainMenu instance;
    return instance;
}

void MainMenu::printTitle() {
    cout
    << StringManager::repeatedSymbol(MENU_WIDTH, "_") << endl
    << StringManager::centerLine(MENU_WIDTH, "Text Adventure", "|") << endl
    << StringManager::repeatedSymbol(MENU_WIDTH, "_") << endl << endl;
}

void MainMenu::printMenuOptions() {
    
    cout
    << StringManager::repeatedSymbol(MENU_WIDTH, "=") << endl
    << StringManager::centerLine(MENU_WIDTH, "", "||") << endl;
    
    for (int i = 0; i < MENU_OPTIONS.size(); i++) {
        MenuOption* option = MENU_OPTIONS[i];
        string optionName = option->name();
        
        cout << StringManager::centerLine(MENU_WIDTH, "-- " + optionName, "||") << endl;
    }
    
    cout
    << StringManager::centerLine(MENU_WIDTH, "", "||") << endl
    << StringManager::repeatedSymbol(MENU_WIDTH, "=") << endl;
}

MenuOption* MainMenu::readOption() {
    MenuOption* chosenOption = NULL;
    int entryFailures = 0;
    
    cout << "\n\nType Your Choosen Option From Menu: " << endl;
    
    while (chosenOption == NULL) {
        string input = string("");
        getline(cin, input);
        
        for (int i = 0; i < MENU_OPTIONS.size(); i++) {
            MenuOption* option = MENU_OPTIONS[i];
            
            if (StringManager::equalIgnoreCase(option->name(), input)) {
                chosenOption = option;
                break;
            }
        }
        
        if (chosenOption == NULL) {
            printRepeatInputMessage(entryFailures);
            entryFailures++;
        }
        
    }
    
    return chosenOption;
}

void MainMenu::printRepeatInputMessage(int entryFailures) {
    switch (entryFailures) {
        case 0:
            cout << "Invalid option try again:" << endl;
            break;
        case 1:
            cout << "Still Invalid try copy and paste? " << endl;
            break;
        case 2:
            cout << "This really isn't rocket science! Enter an option from the list above:" << endl;
            break;
        case 3:
            cout << "Last chance stop being stoopid:" << endl;
            break;
        case 4:
            cout
            << "Congratulations you lose the game before even beginning" << endl
            << StringManager::repeatedSymbol(MENU_WIDTH, "=") << endl
            << StringManager::centerLine(MENU_WIDTH, "", "||") << endl
            << StringManager::centerLine(MENU_WIDTH, " GAME OVER", "||") << endl
            << StringManager::centerLine(MENU_WIDTH, "", "||") << endl
            << StringManager::repeatedSymbol(MENU_WIDTH, "=") << endl << endl;
            
            exit(EXIT_FAILURE);
        default:
            break;
    }
}

const int MainMenu::MENU_WIDTH = 50;
const vector<MenuOption*> MainMenu::MENU_OPTIONS {&(NewGame::instance()), &(LoadGame::instance())};

