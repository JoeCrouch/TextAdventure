
#ifndef TextAdventureXCode_direction_h
#define TextAdventureXCode_direction_h

class Direction {
    
public:
    static const Direction NORTH;
    static const Direction SOUTH;
    static const Direction EAST;
    static const Direction WEST;
    
    int getXDirection();
    int getYDirection();
    
private:
    Direction() {};
    void operator=(Direction const&) = delete;
    
    Direction(int x, int y);
    
    int xDirection_;
    int yDirection_;
};

#endif
