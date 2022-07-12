#pragma once

#include <iostream> // for std::exception

class FileNotFoundException: public std::exception {
    friend std::ostream& operator<<(std::ostream& os, const FileNotFoundException& ex);
public:
    FileNotFoundException() noexcept = default;
    ~FileNotFoundException() = default;
    virtual const char *what() const noexcept {
        return "Error: Answer file is not found.";
    }
};
