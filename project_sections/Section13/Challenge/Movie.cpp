#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watchCount) : name(name), rating(rating), watchCount(watchCount) {}

Movie::Movie(const Movie &source) : Movie{source.name, source.rating, source.watchCount} {}

Movie::~Movie() {}

void Movie::setName(std::string name) {
    this->name = name;
}

std::string Movie::getName() const {
    return name;
}

void Movie::setRating(std::string rating) {
    this->rating = rating;
}

std::string Movie::getRating() const {
    return rating;
}

void Movie::setWatchCount(int watchCount) {
    this->watchCount = watchCount;
}

int Movie::getWatchCount() const {
    return watchCount;
}

void Movie::incrementWatchCount() {
    ++watchCount;
}

void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watchCount << std::endl;
}