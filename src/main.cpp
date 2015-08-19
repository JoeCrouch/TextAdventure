
#include <iostream>
#include "mainMenu.h"
#include "menuOption.h"

int main()
{
    MainMenu::printTitle();
    MainMenu::printMenuOptions();
    
    MenuOption* option = MainMenu::readOption();
    
    cout << "Option chosen is: " << option->name() << endl;
    return 0;
}

