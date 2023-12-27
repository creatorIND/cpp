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

Player::Player() : name{"None"}, health{0}, xp{0} {}

Player::Player(string nameVal) : name{nameVal}, health{0}, xp{0} {}

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {}

int main() {
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    cout << endl;
    return 0;
}