#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include <string>
#include "Movie.h"

class Movies {
    std::vector<Movie> movies;
    
public:
    bool addMovie(std::string name, std::string rating, int watchCount);
    bool incrementWatchCount(std::string name);
    void displayMovies() const;
};

#endif // _MOVIES_H_
