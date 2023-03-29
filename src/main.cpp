#include <iostream>
#include "MyString.hpp"

int main() {
    MyString s = "Kebab";
    MyString s2 = MyString("isto");
    std::cout << s + s2;
    return 0;
}