#include <iostream>
#include <string>

using namespace std;

class Player {
    string name;
    int health;
    int xp;
public:
    string getName() const {
        return name;
    }
    
    void setName(string nameVal) {
        name = nameVal;
    }
    
    //Overloaded Constructors
    Player();
    Player(string nameVal);
    Player(string nameVal, int healthVal, int xpVal);
};

Player::Player() : Player{"None", 0, 0} {}

Player::Player(string nameVal) : Player{nameVal, 0, 0} {}

Player::Player(string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {}

void displayPlayerName(const Player &p) {
    cout << p.getName() << endl;
}

int main() {
    const Player villain {"Villain", 100, 55};
    Player hero {"Hero", 100, 15};
    
//    villain.setName("Super villain");
    cout << villain.getName() << endl;
    cout << hero.getName() << endl;
    
    displayPlayerName(villain);
    displayPlayerName(hero);
    cout << endl;
    return 0;
}