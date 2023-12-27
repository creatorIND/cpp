#include <iostream>
#include <string>

using namespace std;

class Player {
    string name;
    int health;
    int xp;
    
public:
    Player();
    Player(string nameVal);
    Player(string nameVal, int healthVal, int xpVal);
};

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {
    cout << "Three-args constructor" << endl;
}

Player::Player() : Player {"None", 0, 0} {
    cout << "No-args constructor" << endl;
}

Player::Player(string nameVal) : Player {nameVal, 0, 0} {
    cout << "One-arg constructor" << endl;
}

int main() {
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    cout << endl;
    return 0;
}