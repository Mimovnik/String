#include <iostream>

#include "MyString.hpp"

int main() {
    MyString empty;
    MyString s1("kebab");
    MyString s2(std::move(s1));
    MyString s3;
    s3 = s1; // copy
    s3 = MyString("move assignment");
    return 0;
}