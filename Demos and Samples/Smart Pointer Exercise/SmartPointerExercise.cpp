#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>

#include "Test.hpp"

// Function Prototypes:
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);

int main() {
    // Declare and initialize Vector Pointer with Test Object:
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();

    // Prompt the user:
    std::cout << "How many data points do you want to enter: ";
    int num = 0;
    std::cin >> num;

    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num) {
    int input = 0;
    for (int i=0; i<num; i++) {
        std::cout << "Enter data point[" << i+1 << "] : ";
        std::cin >> input;
        vec.push_back(std::make_shared<Test>(input));
        input = 0;
    }
}

void display(const std::vector<std::shared_ptr<Test>>& vec) {
    std::cout << "Displaying Vector data" << std::endl;
    // Border
    std::cout << std::setw(23) << std::setfill('=') << " " << std::endl << std::setfill(' ');
    // Print output
    for (const auto& v: vec)
        std::cout << v->get_data() << std::endl;
    // Border
    std::cout << std::setw(23) << std::setfill('=') << " " << std::endl << std::setfill(' ');
}