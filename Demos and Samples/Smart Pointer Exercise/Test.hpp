#pragma once

#include <iostream>

class Test {
private:
    int data;
public:
    Test(): data(0) { std::cout << "\tTest constructor(" << data << ")" << std::endl; }
    Test(int data): data(data) { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};