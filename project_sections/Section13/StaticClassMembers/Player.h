#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
private:
    static int numPlayers;
    std::string name;
    int health;
    int xp;
    
public:
    std::string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getXP() {
        return xp;
    }
    
    Player(std::string nameVal = "None", int healthVal = 0, int xpVal = 0);
    
    //Copy Constructor
    Player(const Player &source);
    
    //Destructor
    ~Player();
    
    static int getNumPlayers();
};

#endif // _PLAYER_H_
