#include <iostream>
#include <iomanip>

// Money Values
#define DOLLAR_VALUE    100
#define QUARTER_VALUE   25
#define DIME_VALUE      10
#define NICKEL_VALUE    5
#define PENNY_VALUE     1

#define LINE_WIDTH      25
#define FIELD_WIDTH     10

void displayLine(int width) { std::cout << std::setfill('=') << std::setw(width) << " " << std::endl << std::setfill(' '); }

void display(std::string moneyType, unsigned int& balance) {
    std::cout << std::setw(FIELD_WIDTH)
              << std::left
              << moneyType
              << std::setw(FIELD_WIDTH)
              << std::right
              << balance
              << std::endl;
}

int main() {
    // Prompt the user
    unsigned int userInput = 0;
    std::cout << "Type a value: "; 
    std::cin >> userInput;
    std::cout << std::endl;

    // Money Value Convertion:
    unsigned int& balance = userInput;

    unsigned int dollar = balance/DOLLAR_VALUE;
    balance -= dollar * DOLLAR_VALUE;

    unsigned int quarter = balance/QUARTER_VALUE;
    balance -= quarter * QUARTER_VALUE;

    unsigned int dime = balance/DIME_VALUE;
    balance -= dime * DIME_VALUE;

    unsigned int nickel = balance/NICKEL_VALUE;
    balance -= nickel * NICKEL_VALUE;

    unsigned int penny = balance/PENNY_VALUE;
    balance -= penny * PENNY_VALUE;

    // Display Output:
    displayLine(LINE_WIDTH);
        display("Dollar: ", dollar);
        display("Quarter: ", quarter);
        display("Dime: ", dime);
        display("Nickel: ", nickel);
        display("Penny: ", penny);
    displayLine(LINE_WIDTH);

    return 0;
}