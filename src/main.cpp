
#include <iostream>
#include "mainMenu.h"
#include "menuOption.h"
using std::cout;
using std::endl;

int main()
{
    MainMenu* menu = &(MainMenu::instance());
    menu->printTitle();
    menu->printMenuOptions();
    
    MenuOption* option = menu->readOption();
    
    cout << "Option chosen is: " << option->name() << endl;
    return 0;
}

