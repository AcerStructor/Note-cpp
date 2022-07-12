#include "FileNotFoundException.hpp"

std::ostream& operator<<(std::ostream& os, const FileNotFoundException& ex) {
    os << ex.what();
    return os;
}