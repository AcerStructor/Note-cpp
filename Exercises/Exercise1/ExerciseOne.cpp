#include <iostream>

// Pseudo Code:
// Prompt the user
// calculate the gallons to cubic feet
// display the output

float gallonsToCubicFeet(float input) {
    return input / 7.481f;
}

int main() {
    // Prompt the user to enter a number of gallons
    float input = 0;
    std::cout << "Enter a number of gallons: ";
    std::cin >> input;

    std::cout << "Gallons to cubic feet: " << gallonsToCubicFeet(input) << "ft^3" << std::endl;
    return 0;
}