
#ifndef TextAdventure_direction_h
#define TextAdventure_direction_h

#include <string>
#include <vector>
using std::vector;
using std::string;

class Direction {
    
public:
    static const Direction NORTH;
    static const Direction SOUTH;
    static const Direction EAST;
    static const Direction WEST;
    static const Direction NOWHERE;
    static const vector<Direction> VALID_DIRECTIONS;
    
    static const Direction getDirection(string direction);
    
    int getXDirection() const;
    int getYDirection() const;
    string getName() const;
    
    bool operator == (const Direction& direction) const;
    
private:
    Direction() {};
    void operator=(Direction const&) = delete;
    
    Direction(int x, int y, string name);
    
    int xDirection_;
    int yDirection_;
    string name_;
};

#endif
