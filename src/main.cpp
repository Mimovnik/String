#include <iostream>

#include "MyString.hpp"

int main() {
    MyString s1("  kebab  ");
    s1.trim();
    s1.trim();
    return 0;
}