#ifndef TextAdventure_actionService_h
#define TextAdventure_actionService_h

#include <string>
using std::string;

class ActionService {
public:
    virtual ~ActionService() {};
    
    virtual string getName() = 0;
    virtual void execute() = 0;
};

#endif

