#pragma once

#include <string>

class Movie {
public:
    Movie(std::string name, std::string rating, unsigned int watched)
    : mName(name), mRating(rating), mWatched(watched) {}
    ~Movie() = default;

    void increment_watched() {
        mWatched++;
    }

    // Getters:
    std::string get_name() const {
        return mName;
    }
    std::string get_rating() const {
        return mRating;
    }
    unsigned int get_watched() const {
        return mWatched;
    }

private: // Class Attributes
    std::string mName;
    std::string mRating;
    unsigned int mWatched;
};