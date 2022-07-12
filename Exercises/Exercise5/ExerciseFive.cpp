#include <iostream>
#include <cctype>

int main() {
    // prompt the user:
    char input = '\0';
    std::cout << "Type a letter to identify if its zero or nonzero: ";
    std::cin >> input;

    // Check if the letter is zero or nonzero:
    if (islower(input))
        std::cout << "zero" << std::endl;
    else
        std::cout << "nonzero" << std::endl;
    
    return 0;
}