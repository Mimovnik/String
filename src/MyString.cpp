#include "MyString.hpp"

#include <cstring>

MyString::MyString() : MyString("") {}

MyString::MyString(const char* s) {
    length = strlen(s);
    content = new char[length];
    strcpy(content, s);
}

MyString::~MyString() { delete[] content; }

MyString MyString::operator+(MyString const& other) {
    return MyString(strcat(this->content, other.content));
}
MyString& MyString::operator=(const char* s) {
    int sLen = strlen(s);
    if (length != sLen) {
        delete[] content;
        length = sLen;
        content = new char[length];
    }
    std::copy(s, s + length, content);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.content;
    return os;
}