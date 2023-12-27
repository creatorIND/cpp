#include <iostream>
#include "Movies.h"

bool Movies::addMovie(std::string name, std::string rating, int watchCount) {
    for(const auto &movie: movies) {
        if(movie.getName() == name) {
            return false;
        }
    }
    Movie temp(name, rating, watchCount);
    movies.push_back(temp);
    return true;
}

bool Movies::incrementWatchCount(std::string name) {
    for(auto &movie: movies) {
        if(movie.getName() == name) {
            movie.incrementWatchCount();
            return true;
        }
    }
    return false;
}

void Movies::displayMovies() const {
    if(movies.size() == 0) {
        std::cout << "Sorry, no movies to display\n" << std::endl;
    }
    else {
        std::cout << "\n=========================================" << std::endl;
        for(const auto &movie: movies) {
            movie.display();
        }
        std::cout << "=========================================" << std::endl;
    }
}