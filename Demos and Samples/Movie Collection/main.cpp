#include <iostream>
#include "Movies.hpp"

void add_Movie(Movies& movie, std::string name, std::string rating, unsigned int watched) {
    if (movie.add_movie(name, rating, watched))
        std::cout << "Movie has been added successfully." << std::endl;
    else 
        std::cout << "Movie has failed to be added to the list." << std::endl;

}

void watch_Movie(Movies& movie, std::string name) {
    if (movie.increment_watched(name))
        std::cout << "You've watched " << name << " movie." << std::endl;
    else
        std::cout << "Movie not found" << std::endl;
}

int main() {
    Movies myMovies;
    myMovies.display();
    add_Movie(myMovies, "Cinderella", "G", 3);
    add_Movie(myMovies, "Spirited Away", "PG-13", 10);

    myMovies.display();
    add_Movie(myMovies, "Cinderella", "G", 3);
    watch_Movie(myMovies, "Cinderella");

    myMovies.display();
    return 0;
}