#include "Player.h"

int Player::numPlayers {0};

Player::Player(std::string nameVal, int healthVal, int xpVal) : name{nameVal}, health{healthVal}, xp{xpVal} {
    ++numPlayers;
}

Player::Player(const Player &source) : Player{source.name, source.health, source.xp} {}

Player::~Player() {
    --numPlayers;
}

int Player::getNumPlayers() {
    return numPlayers;
}