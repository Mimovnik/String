#include <iostream>

#include "String.hpp"

int main() {
    String s1 = String::readString("\n", 2);
    std::cout << s1 << std::endl;
    std::cout << "Int = " << s1.toInt() << std::endl;
    return 0;
}