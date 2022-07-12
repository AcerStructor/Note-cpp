#include <iostream>
#include <windows.h>
#include <sstream>
#include <vector>
#include <iomanip>

#define _LINE_WIDTH_ 55

void addLines(int width) { std::cout << std::setfill('=') << std::setw(width) << " " << std::endl << std::setfill(' '); }

void displayStorage(std::vector<int>& numbers) {
    if (!numbers.empty()) {
        std::cout << "Current Numbers Stored: [ ";
        for (int i = 0; i < (int)numbers.size(); i++)
            (i == (int)numbers.size() - 1) ? std::cout << numbers.at(i) << " " : std::cout << numbers.at(i) << ", ";
        std::cout << "]" << std::endl;
    } else
        std::cout << "Number Stack is currently empty..." << std::endl;
}

void addNumbers(std::vector<int>& numbers) {
    system("cls"); // Clear Console
    addLines(_LINE_WIDTH_);
    displayStorage(numbers);
    std::cout << std::endl;
    addLines(_LINE_WIDTH_);

    // Prompt the user:
    std::cout << "Enter your number to add in number stack\n"
            << "Type here: ";
    std::string input = "\0";
    std::cin >> input;
    std::stringstream ss{input};

    int numberToAdd = 0;
    // Check if user input is a number, if not then throw an exception:
    if (ss >> numberToAdd)
        numbers.push_back(numberToAdd);
    else {
        std::cerr << "Error: input is not a number, please try again." << std::endl;
        system("pause");
    }
}

void replaceNumbers(std::vector<int>& numbers) {
    system("cls"); // Clear Console

    // Display Storage:
    addLines(_LINE_WIDTH_);
    displayStorage(numbers);
    std::cout << std::endl;
    addLines(_LINE_WIDTH_);

    if (!numbers.empty()) {
        std::cout << "Enter the number you want to replace in from the number stack: ";
        std::string userInput = "\0";
        std::cin >> userInput;
        std::stringstream ss{userInput};

        int numberToFind = 0;
        if (ss >> numberToFind) {

            bool isFound = false;
            // Check all numbers inside the storage:
            for (int i = 0; i < (int)numbers.size(); i++) {
                // Check if the number exist:
                if (numberToFind == numbers.at(i)) {
                    isFound = true;

                    replaceNum:
                    std::cout << "Enter a replacing number: ";
                    std::string replaceInput = "\0";
                    std::cin >> replaceInput;
                    std::stringstream replaceSS{replaceInput};

                    int replacingNum = 0;
                    if (replaceSS >> replacingNum) {
                        numbers.at(i) = replacingNum;
                        std::cout << "Replacement Success!" << std::endl << std::endl;
                    }
                    else {
                        std::cout << "Error: input is not a number, please try again." << std::endl << std::endl;
                        goto replaceNum;
                    }

                    break;
                }
            }

            if (!isFound)
                std::cerr << "Error: the number that you want to replace doesn't existed" << std::endl;
            
            system("pause");
        } else {
            std::cout << "The input you have entered is invalid!" << std::endl;
            system("pause");
        }
    }
    else
        system("pause");
}

void clearNumbers(std::vector<int>& numbers) {
    if (!numbers.empty()) {
        clearLoop:
        system("cls"); // Clear Console
        std::cout << "Are you sure you want to clear the number stack?\n"
                << "Type \"Y\" to clear, if not then \"N\"\n"
                << "Type here: ";
        char userInput = '\0';
        std::cin >> userInput;

        switch(userInput) {
        case 'Y':
        case 'y':
            numbers.clear();
            break;

        case 'N':
        case 'n':
            break;

        default:
            std::cout << "Invalid user input, please try again." << std::endl;
            system("pause");
            goto clearLoop;
            break;
        }
    }
    else {
        system("cls"); // Clear Console
        std::cout << "Number stack is still empty..." << std::endl;
        system("pause");
    }
}

void exitProgramConfirmation(bool &isProgramOver) {
    exitLoop:
    system("cls"); // Clear Console
    std::cout << "Are you sure you want to clear the number storage?\n"
            << "Type \"Y\" to clear, if not then \"N\"\n"
            << "Type here: ";
    char userInput = '\0';
    std::cin >> userInput;

    switch(userInput) {
    case 'Y':
    case 'y':
        isProgramOver = true;
        break;

    case 'N':
    case 'n':
        // Just exits the loop
        break;

    default:
        std::cout << "Invalid user input, please try again." << std::endl;
        system("pause");
        goto exitLoop;
        break;
    }
}

void mainMenu(std::vector<int>& numbers, bool& isDisplayStorage, bool& isProgramOver) {
    system("cls"); // Clear Console
    // Main Menu Instruction:
    addLines(_LINE_WIDTH_);
    std::cout << "Main Menu:\n"
            << "\tA - Add numbers to your Storage\n"
            << "\tB - Find and replace numbers from your storage\n"
            << "\tC - Clear numbers from your storage\n"
            << "\tD - Delete upper number from your storage\n"
            << "\tE - Exit program\n"
            << "\tF - Turn Storage Display ON/OFF" << std::endl
            << std::endl;
    addLines(_LINE_WIDTH_);

    // Display Stack:
    if (isDisplayStorage) {
        displayStorage(numbers);
        addLines(_LINE_WIDTH_);
    }

    // Prompt the user:
    std::cout << "Enter here: ";
    char input = '\0';
    std::cin >> input;

    // Choices:
    switch(input) {
        // Add numbers:
    case 'A':
    case 'a':
        addNumbers(numbers);
        break;

        // Replace Number:
    case 'B':
    case 'b':
        replaceNumbers(numbers);
        break;

        // Clear Stack:
    case 'C':
    case 'c':
        clearNumbers(numbers);
        break;

        // Delete Numbers:
    case 'D':
    case 'd':
        // Work-in-progress
        break;

        // Exit Program:
    case 'E':
    case 'e':
        exitProgramConfirmation(isProgramOver);
        break;

        // Toggle Display Stack:
    case 'F':
    case 'f':
        (isDisplayStorage) ? isDisplayStorage = false : isDisplayStorage= true;
        break;

    default:
        break;
    }
}

int main() {
    bool isDisplayStorage = true;
    bool isProgramOver = false;
    std::vector<int> numbers;

    while(!isProgramOver) {
        mainMenu(numbers, isDisplayStorage, isProgramOver);
    }
    return 0;
}
