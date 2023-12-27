#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
    std::string name;
    std::string rating;
    int watchCount;
    
public:
    Movie(std::string name, std::string rating, int watchCount);
    Movie(const Movie &source);
    ~Movie();
    
    void setName(std::string name);
    std::string getName() const;
    
    void setRating(std::string rating);
    std::string getRating() const;
    
    void setWatchCount(int watchCount);
    int getWatchCount() const;
    
    void incrementWatchCount();
    
    void display() const;
};

#endif // _MOVIE_H_
