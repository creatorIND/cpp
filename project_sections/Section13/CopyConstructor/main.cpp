#include <iostream>
#include <string>

using namespace std;

class Player {
    string name;
    int health;
    int xp;
    
public:
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getXP() {
        return xp;
    }
    Player(string nameVal = "None", int healthVal = 0, int xpVal = 0);
    
    //Copy constructor
    Player(const Player &source);
    //Destructor
    ~Player() {
        cout << "Destructor called for: " << name << endl;
    }
};

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three-args constructor for " + name << endl;
}

Player::Player(const Player &source) : name{source.name}, health{source.health}, xp{source.xp} {
    cout << "Copy constructor - made copy of: " << source.name << endl;
}

void displayPlayer(Player p) {
    cout << "Name: " << p.getName() << endl;
    cout << "Health: " << p.getHealth() << endl;
    cout << "XP: " << p.getXP() << endl;
}

int main() {
    Player empty {"XXXXXX", 100, 50};
    Player myNewObject {empty};
    displayPlayer(empty);
    
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
    cout << endl;
    return 0;
}