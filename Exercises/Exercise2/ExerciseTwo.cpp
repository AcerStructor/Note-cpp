#include <iostream>
#include <iomanip>

void printOutput(const int input_one, const int input_two) {
    std::cout << std::setw(10)
              << std::left
              << input_one
              << std::setw(10)
              << std::right
              << input_two
              << std::endl;
}

int main() {
    printOutput(1990, 135);
    printOutput(1991, 7290);
    printOutput(1992, 11300);
    printOutput(1993, 16200);
    return 0;
}