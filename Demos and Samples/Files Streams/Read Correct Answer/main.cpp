#include <iostream>
#include <iomanip>
#include <fstream>

#include "DEFINITIONS.hpp"
#include "FileNotFoundException.hpp"

void setLineBreak(const int totalLength) {
    std::cout << std::setw(totalLength) 
              << std::setfill('-')
              << ""
              << std::endl
              << std::setfill(' ');
}

void displayRight(std::string input, const int sectionLength) {
    std::cout << std::right
            << std::setw(_SECTION_LENGTH_)
            << input 
            << std::endl;
}

void displayLeft(std::string input, const int sectionLength) {
    std::cout << std::left
              << std::setw(_SECTION_LENGTH_) 
              << input;
}

void process_score_per_student(std::ifstream& read_file);

int main() {
    try {
        std::ifstream read_file;
        // If the file is not found
        read_file.open(_FILEPATH_);
        if (!read_file)
            throw FileNotFoundException();
            
        process_score_per_student(read_file);
        read_file.close();
    }
    catch(const FileNotFoundException& ex) {
        std::cerr << ex << std::endl;
        std::cerr << _FILEPATH_ << std::endl;
        return 1;
    }
    catch(...) {
        std::cerr << "Unknown Error occured" << std::endl;
        return 2;
    }

    return 0;
}

void process_score_per_student(std::ifstream& read_file) {
    // Declare correct answer and name variable
    std::string correct_answer, name;

    // Display header
    displayLeft("Student", _SECTION_LENGTH_);
    displayRight("Score", _SECTION_LENGTH_);
    setLineBreak(_TOTAL_LENGTH_);

    // Process checking the score
    while (!read_file.eof()) {
        // Read the Correct Answer first
        if (correct_answer.empty()) {
            std::getline(read_file, correct_answer);
            continue;
        }

        // Display Name:
        if (name.empty()) {
            std::getline(read_file, name);
            displayLeft(name, _SECTION_LENGTH_);
        }
        
        // Check the score
        if (!name.empty()) {
            // Declare score variable
            int score = 0;
            std::string answer;

            // Read the answer of the current student
            std::getline(read_file, answer);
            for (size_t i=0; i<correct_answer.length(); i++) {
                if (correct_answer[i] == answer[i])
                    score++; // Add points if the answer is correct
            }

            // Display Score:
            displayRight(std::to_string(score), _SECTION_LENGTH_);

            // Reset score and name:
            score = 0; name = "\0";
        }
    }
    setLineBreak(_TOTAL_LENGTH_);
}