#include "Movies.hpp"

#include <iostream>
#include <iomanip>

Movies::Movies() {}

Movies::~Movies() {}

bool Movies::add_movie(std::string name, std::string rating, unsigned int watched) {
    // Check if that movie already exists:
    for (const auto& movie: mMovies) {
        if (name == movie.get_name()) {
            std::cout << name << " movie is already existed to the movie list" << std::endl;
            return false;
        }
    }
    // Add movie to the movie list:
    Movie temp(name, rating, watched);
    mMovies.push_back(temp);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (auto& movie: mMovies) {
        if (name == movie.get_name()) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (!mMovies.empty()) {
        std::cout << std::setw(50)
                << std::setfill('=')
                << ""
                << std::endl 
                << std::setfill(' ');
        
        for (const auto& movie: mMovies)
            std::cout << movie.get_name() << ", " << movie.get_rating() << ", " << movie.get_watched() << std::endl;
        
        std::cout << std::setw(50)
                << std::setfill('=')
                << ""
                << std::endl
                << std::setfill(' ');
    }
    else {
        std::cout << "Movie list is empty!" << std::endl;
    }
}