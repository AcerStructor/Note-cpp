#pragma once

#include <vector>
#include "Movie.hpp"

class Movies {
public:
    Movies();
    ~Movies();

    bool add_movie(std::string name, std::string rating, unsigned int watched);
    bool increment_watched(std::string name);
    void display() const;
private:
    std::vector<Movie> mMovies;
};