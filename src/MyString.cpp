#include "MyString.hpp"

bool MyString::containsChar(const char* cstring, char contained) {
    for (int i = 0; i < getLength(cstring); i++) {
        if (cstring[i] == contained) {
            return true;
        }
    }
    return false;
}

unsigned int MyString::getLength(const char* cstring) {
    unsigned int length = 0;
    while (*cstring != '\0') {
        length++;
        cstring++;
    }
    return length;
}

void MyString::copy(const char* source, char* destination,
                    unsigned int length) {
    for (int i = 0; i < length; i++) {
        *destination = *source;
        destination++;
        source++;
    }
}

bool MyString::equals(const char* first, const char* second) {
    unsigned int firstLength = getLength(first);
    unsigned int secondLength = getLength(second);
    if (firstLength != secondLength) {
        return false;
    }
    for (int i = 0; i < firstLength; i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }

    return true;
}

MyString::MyString() {
    length = 0;
    content = new char[length + 1];
    content[0] = '\0';
}

MyString::~MyString() {
    length = 0;
    delete[] content;
}

MyString::MyString(const MyString& other) {
    unsigned int otherConentLength = getLength(other.content);
    if (length != otherConentLength) {
        delete[] content;
        length = otherConentLength;
        content = new char[length + 1];
    }
    copy(other.content, content, length + 1);
}

MyString& MyString::operator=(const MyString& other) {
    unsigned int otherConentLength = getLength(other.content);
    if (length != otherConentLength) {
        delete[] content;
        length = otherConentLength;
        content = new char[length + 1];
    }
    copy(other.content, content, length + 1);
    return *this;
}

MyString::MyString(MyString&& other) {
    char* tmp = content;
    content = other.content;
    other.content = tmp;
}

MyString& MyString::operator=(MyString&& other) {
    char* tmp = content;
    content = other.content;
    other.content = tmp;
    return *this;
}

MyString::MyString(const char* cstring) {
    length = getLength(cstring);
    content = new char[length + 1];
    copy(cstring, content, length + 1);
}

MyString& MyString::operator=(const char* cstring) {
    unsigned int cstringLength = getLength(cstring);
    if (length != cstringLength) {
        delete[] content;
        length = cstringLength;
        content = new char[length + 1];
    }
    copy(cstring, content, length + 1);
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
    for (int i = length - 1; i >= 0; i--) {
        if (isspace(content[i])) {
            backWhitespaces++;
        } else {
            break;
        }
    }

    int newLength = length - frontWhitespaces - backWhitespaces;
    if (length == newLength) {
        return;
    }
    char* newContent = new char[newLength + 1];
    copy(content + frontWhitespaces, newContent, newLength);
    newContent[newLength] = '\0';

    length = newLength;
    delete[] content;
    content = newContent;
}

bool MyString::equals(const char* cstring) { return equals(content, cstring); }

MyString MyString::readString(const char* endChars) {
    char input[MAX_READ_LENGTH];
    char c;
    for (int i = 0; std::cin.good() && i < MAX_READ_LENGTH; i++) {
        c = getchar();
        if (containsChar(endChars, c)) {
            input[i] = '\0';
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