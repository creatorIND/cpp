#include <iostream>
#include <string>

using namespace std;

class Player {
    string name;
    int health;
    int xp;
    
public:
    Player(string nameVal = "None", int healthVal = 0, int xpVal = 0);
};

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three-args constructor" << endl;
}

int main() {
    Player empty;
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
    cout << endl;
    return 0;
}