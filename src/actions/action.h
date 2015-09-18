#ifndef TextAdventureXCode_action_h
#define TextAdventureXCode_action_h

#include <string>
using std::string;

class Action {
public:
    virtual ~Action() {};
    
    virtual string getName() = 0;
    virtual void execute() = 0;
};

#endif
