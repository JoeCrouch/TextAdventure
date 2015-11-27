
#ifndef TextAdventure_talkToService_h
#define TextAdventure_talkToService_h

class Location;

#include "actionService.h"
#include <string>
using std::string;

class TalkToService: public ActionService {
public:
    TalkToService(string character, Location* location);
    bool execute();
    
private:
    TalkToService();
    
    string target_;
    Location* location_;
};

#endif
