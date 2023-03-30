#include "MyString.hpp"

#include <cstring>

bool MyString::containsChar(const char* array, char contained) {
    for (int i = 0; i < strlen(array); i++) {
        if (array[i] == contained) {
            return true;
        }
    }
    return false;
}

char* MyString::trimmed(const char* array) { return nullptr; }

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

void MyString::trim() {
    int frontWhitespaces = 0;
    for (int i = 0; i < length; i++) {
        if (isspace(content[i])) {
            frontWhitespaces++;
        } else {
            break;
        }
    }

    int backWhitespaces = 0;
    for (int i = length - 1; i >= 0; i++) {
        if (isspace(content[i])) {
            backWhitespaces++;
        } else {
            break;
        }
    }

    int newLength = length - frontWhitespaces - backWhitespaces;
    char* newContent = new char[newLength];
    for (int i = 0; i < newLength; i++) {
        newContent[i] = content[frontWhitespaces + i];
    }
    length = newLength;
    delete[] content;
    content = newContent;
}

MyString MyString::readString(const char* endChars) {
    char input[MAX_READ_LENGTH];
    char c;
    for (int i = 0; std::cin.good() && i < MAX_READ_LENGTH; i++) {
        c = getchar();
        if (containsChar(endChars, c)) {
            break;
        }
        input[i] = c;
    }
    MyString s = MyString(input);
    return s;
}

std::ostream& operator<<(std::ostream& stream, const MyString& str) {
    stream << str.content;
    return stream;
}