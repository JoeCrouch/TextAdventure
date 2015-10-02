#ifndef TextAdventure_action_h
#define TextAdventure_action_h

#include <string>
using std::string;

class Action {
    
public:
    static const Action MOVE;
    static const Action PRINT;
    static const Action QUIT;
    
    string getName();
    bool operator < (const Action& action) const;
    
private:
    Action() {};
    
    Action(string name);
    
    string name_;
};



#endif
