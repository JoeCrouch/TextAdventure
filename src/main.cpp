
#include <iostream>
#include "game.h"
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
    
    Game* game = option->buildGame();
    game->play();
    return 0;
}

