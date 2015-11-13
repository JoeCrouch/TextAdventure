
#include "action.h"

const Action Action::MOVE = Action("Move");
const Action Action::PICK_UP = Action("Pick Up");
const Action Action::DROP = Action("Drop");
const Action Action::USE = Action("Use");
const Action Action::VIEW = Action("View");
const Action Action::QUIT = Action("Quit");

Action::Action(string name) : name_(name) {
}

string Action::getName() {
    return name_;
}

bool Action::operator < (const Action& action) const {
    return name_ < action.name_;
}
