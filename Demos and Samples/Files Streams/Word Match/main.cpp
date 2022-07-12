/********************************************
 * Written by: Jerico (OwllCraft)           *
 * Date: August 24, 2021                    *
 ********************************************/

#include <iostream> 
#include <fstream> // for ifstream

#include "DEFINITIONS.hpp"

// convert user input to lowercase:
std::string strLowerCase(std::string str) {
    for (size_t i=0; i<str.length(); i++)
        str.at(i) = std::tolower(str.at(i));
    return str;
}

int main() {
    std::ifstream read_file;
    read_file.open(_FILEPATH_); // Opens the filepath for the txt file.

    // Check if file is not found:
    if (!read_file) {
        std::cerr << "Error: file not found: " << _FILEPATH_ << std::endl;
        return 1;
    }

    // prompt the user:
    std::cout << "Enter the substring to search for: ";
    std::string input; std::cin >> input;
    input = strLowerCase(input); // convert to lowercase
    
    // Declare word counts:
    unsigned int matchCount = 0;
    unsigned int wordCount = 0;

    // Process read file:
    while (!read_file.eof()) {
        std::string textInFile;
        read_file >> textInFile;
        textInFile = strLowerCase(textInFile); // convert to lowercase

        if (textInFile.find(input) != std::string::npos)
            matchCount++;

        wordCount++;
    }
    read_file.close(); // Closes the current txt file

    // display output:
    std::cout << wordCount << " words were searched..." << std::endl;
    std::cout << "The substring " << input << " was found " << matchCount << " times." << std::endl;
    
    return 0;
}