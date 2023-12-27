#include <iostream>
#include "Movies.h"

void incrementWatchCount(Movies &movies, std::string name);
void addMovie(Movies &movies, std::string name, std::string rating, int watchCount);

int main() {
    Movies myMovies;
    myMovies.displayMovies();
    
    addMovie(myMovies, "Harry Potter", "PG", 5);
    addMovie(myMovies, "Big Hero 6", "PG-13", 3);
    addMovie(myMovies, "3 Idiots", "PG-13", 10);
    
    myMovies.displayMovies();
    
    addMovie(myMovies, "3 Idiots", "PG-13", 10);
    addMovie(myMovies, "Ice Age", "PG", 2);
    
    myMovies.displayMovies();
    
    incrementWatchCount(myMovies, "Harry Potter");
    incrementWatchCount(myMovies, "Ice Age");
    
    myMovies.displayMovies();
    
    incrementWatchCount(myMovies, "Inception");
    
    std::cout << std::endl;
    return 0;
}

void incrementWatchCount(Movies &movies, std::string name) {
    if(movies.incrementWatchCount(name)) {
        std::cout << name << " watch incremented" << std::endl;
    }
    else {
        std::cout << name << " not found" << std::endl;
    }
}

void addMovie(Movies &movies, std::string name, std::string rating, int watchCount) {
    if(movies.addMovie(name, rating, watchCount)) {
        std::cout << name << " added" << std::endl;
    }
    else {
        std::cout << name << " already exists" << std::endl;
    }
}