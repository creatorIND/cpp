#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;
    
public:
    void setName(string nameVal) {
        name = nameVal;
    }
    
    string getName() {
        return name;
    }
    
    Player() {
        name = "None";
        health = 100;
        xp = 3;
    }
    
    Player(string nameVal, int healthVal, int xpVal) {
        name = nameVal;
        health = healthVal;
        xp = xpVal;
    }
};

int main() {
    Player hero;
    Player sujal {"Sujal", 100, 13};
    sujal.setName("Sujal");
    cout << sujal.getName() << endl;
    
    cout << endl;
    return 0;
}