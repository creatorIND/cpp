#include <iostream>
#include "Player.h"

using namespace std;

void displayActivePlayers() {
    cout << "Active players: " << Player::getNumPlayers() << endl;
}

int main() {
    displayActivePlayers();
    Player hero {"Hero"};
    displayActivePlayers();
    
    {
        Player sujal{"Sujal"};
        displayActivePlayers();
    }
    
    displayActivePlayers();
    Player *enemy = new Player("Enemy", 100, 100);
    displayActivePlayers();
    delete enemy;
    displayActivePlayers();
    
    cout << endl;
    return 0;
}