

#ifndef TextAdventure_mainMenu_h
#define TextAdventure_mainMenu_h

#include <vector>
#include <string>
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

class MainMenu {
public:
    
    static void printTitle() {
        cout
        << repeatedSymbol(MENU_WIDTH, "_") << endl
        << centerLine(MENU_WIDTH, "Text Adventure", "|") << endl
        << repeatedSymbol(MENU_WIDTH, "_") << endl << endl;
    }
    
    static void printMenuOptions() {
        
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
    
    static MenuOption* readOption() {
        MenuOption* chosenOption = NULL;
        
        cout << "\n\nType Your Choosen Option From Menu: " << endl;
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
        
        return chosenOption;
    }
    
private:
    MainMenu() {};
    MainMenu(MainMenu const&) = delete;
    void operator=(MainMenu const&) = delete;

    static const int MENU_WIDTH;
    static const vector<MenuOption*> MENU_OPTIONS;
    
    static string toUpperCase(string theString) {
        string stringCopy = theString;
        std::transform(theString.begin(), theString.end(), stringCopy.begin(), ::toupper);
        return stringCopy;
    }
};

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

#endif
