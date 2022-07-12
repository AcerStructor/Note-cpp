#include <iostream>
#include <iomanip>
#define _MAX_LENGTH_ 20

float dollarToBritishPound(float& dollar) {
    return dollar / 1.487f;
}
float dollarToFrenchFranc(float dollar) {
    return dollar / 0.172f;
}
float dollarToGermanDeutschemark(float dollar) {
    return  dollar / 0.584f;
}
float dollarToJapaneseYen(float dollar) {
    return dollar / 0.00955f;
}

int main() {
    // Prompt the user:
    float dollarInput = 0.f;
    std::cout << "Type a value of your dollar: ";
    std::cin >> dollarInput;

//  // Print Output:
// Dollar:
    std::cout << std::setw(_MAX_LENGTH_) 
              << std::left << "Dollar" 
              << std::setw(_MAX_LENGTH_) 
              << std::right 
              << ": " 
              << "$"
              << dollarInput 
              << std::endl;

// British Pound: 
    std::cout << std::setw(_MAX_LENGTH_) 
              << std::left << "British Pound" 
              << std::setw(_MAX_LENGTH_) 
              << std::right << ": " 
              << ""
              << "£"
              << dollarToBritishPound(dollarInput) 
              << std::endl;

// French Franc:
    std::cout << std::setw(_MAX_LENGTH_) 
              << std::left 
              << "French Franc" 
              << std::setw(_MAX_LENGTH_) 
              << std::right 
              << ": " 
              << "₣"
              << dollarToFrenchFranc(dollarInput) 
              << std::endl;

// German Deutshemark:
    std::cout << std::setw(_MAX_LENGTH_) 
              << std::left 
              << "German Deutschemark" 
              << std::setw(_MAX_LENGTH_) 
              << std::right 
              << ": " 
              << "€"
              << dollarToGermanDeutschemark(dollarInput) 
              << std::endl;

// Japanese Yen:
    std::cout << std::setw(_MAX_LENGTH_) 
              << std::left 
              << "Japanese Yen" 
              << std::setw(_MAX_LENGTH_) 
              << std::right 
              << ": " 
              << "¥"
              << dollarToJapaneseYen(dollarInput) 
              << std::endl;

    return 0;
}