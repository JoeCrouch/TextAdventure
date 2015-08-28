
#include <iostream>
#include "mainMenu.h"
using std::cout;

void MainMenu::printTitle() {
    cout
    << repeatedSymbol(MENU_WIDTH, "_") << endl
    << centerLine(MENU_WIDTH, "Text Adventure", "|") << endl
    << repeatedSymbol(MENU_WIDTH, "_") << endl << endl;
}

void MainMenu::printMenuOptions() {
    
    cout
    << repeatedSymbol(MENU_WIDTH, "=") << endl
    << centerLine(MENU_WIDTH, "", "||") << endl;
    
    for (int i = 0; i < MENU_OPTIONS.size(); i++) {
        MenuOption* option = MENU_OPTIONS[i];
        string optionName = option->name();
        
        cout << centerLine(MENU_WIDTH, "-- " + optionName, "||") << endl;
    }
    
    cout
    << centerLine(MENU_WIDTH, "", "||") << endl
    << repeatedSymbol(MENU_WIDTH, "=") << endl;
}

MenuOption* MainMenu::readOption() {
    MenuOption* chosenOption = NULL;
    int entryFailures = 0;
    
    cout << "\n\nType Your Choosen Option From Menu: " << endl;
    
    while (chosenOption == NULL) {
        string input = string("");
        getline(cin, input);
        input = toUpperCase(input);
        
        for (int i = 0; i < MENU_OPTIONS.size(); i++) {
            MenuOption* option = MENU_OPTIONS[i];
            string optionName = option->name();
            
            if (toUpperCase(optionName).compare(input) == 0) {
                chosenOption = option;
            }
        }
        
        if (chosenOption == NULL) {
            printRepeatInputMessage(entryFailures);
            entryFailures++;
        }
        
    }
    
    return chosenOption;
}

string MainMenu::toUpperCase(string theString) {
    string stringCopy = theString;
    std::transform(theString.begin(), theString.end(), stringCopy.begin(), ::toupper);
    return stringCopy;
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
            << repeatedSymbol(MENU_WIDTH, "=") << endl
            << centerLine(MENU_WIDTH, "", "||") << endl
            << centerLine(MENU_WIDTH, " GAME OVER", "||") << endl
            << centerLine(MENU_WIDTH, "", "||") << endl
            << repeatedSymbol(MENU_WIDTH, "=") << endl << endl;
            
            exit(EXIT_FAILURE);
        default:
            break;
    }
}

const int MainMenu::MENU_WIDTH = 50;
const vector<MenuOption*> MainMenu::MENU_OPTIONS {&(NewGame::instance()), &(LoadGame::instance())};

string repeatedSymbol(int length, string symbol) {
    string repeatedSymbolString = string("");
    
    for (int i = 0; i < length; i ++) {
        repeatedSymbolString += symbol;
    }
    
    return repeatedSymbolString;
}

string centerLine(int length, string centerText, string border) {
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