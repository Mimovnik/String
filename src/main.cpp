#include <iostream>

#include "MyString.hpp"

int main() {
    MyString word = MyString::readString(",;");
    std::cout << "Your word is '" << word << "'" << std::endl;
    word.trim();
    std::cout << "Your trimmed word is '" << word << "'" << std::endl;
    return 0;
}