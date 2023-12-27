#include <iostream>
#include <string>

using namespace std;

class Player {
    string name;
    int health;
    int xp;
    
public:
    void setName(string nameVal) {
        name = nameVal;
    }
    
    Player() {
        cout << "No args constructor called" << endl;
    }
    Player(string name) {
        cout << "String arg constructor called" << endl;
    }
    Player(string name, int health, int xp) {
        cout << "Three args constructor called" << endl;
    }
    ~Player() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    {
        Player slayer;
        slayer.setName("Slayer");
    }
    
    {
        Player frank;
        frank.setName("Frank");
        
        Player hero("Hero");
        hero.setName("Hero");
        
        Player villain("Villain", 100, 12);
        villain.setName("Villain");
    }
    
    Player *enemy = new Player;
    enemy->setName("Enemy");
    
    Player *levelBoss = new Player("Level Boss", 1000, 300);
    levelBoss->setName("Level Boss");
    
    delete enemy;
    delete levelBoss;
    
    cout << endl;
    return 0;
}