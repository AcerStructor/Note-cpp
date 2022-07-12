#include <iostream>
#include <iomanip>
#include <fstream>

int main(void) {
    // Declaration:
    std::ifstream read_file("romeoandjuliet.txt");
    std::ofstream out_file("romeoandjuliet_out.txt");

    // Read if "read_file" exist:
    if (!read_file) {
        std::cerr << "Error: file not found" << std::endl;
        return 1;
    }

    // Copy details from original file and paste to the output file:
    if (read_file.is_open()) {
        std::string line{};
        int count = 1;
        while (std::getline(read_file, line)) {
            if (!line.empty()) {
                out_file << std::left
                        << std::setw(7)
                        << count 
                        << std::right
                        << std::setw(2)
                        << ""
                        << line 
                        << std::endl;
                count++;
            }
            else
                out_file << std::endl;
        }
    }
    std::cout << "File contents are copied!" << std::endl;
    return 0;
}