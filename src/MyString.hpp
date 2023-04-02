#pragma once
#include <iostream>

class MyString {
   private:
    static const int MAX_READ_LENGTH = 128;

    char* content = nullptr;

    unsigned int length = 0;

    static bool containsChar(const char* array, char contained);

    static unsigned int getLength(const char* cstring);

    static void copy(const char* source, char* destination,
                     unsigned int length);

    static bool equals(const char* first, const char* second);

   public:
    MyString();

    ~MyString();

    MyString(const MyString& other);

    MyString& operator=(const MyString& other);

    MyString(MyString&& other);

    MyString& operator=(MyString&& other);

    MyString(const char* s);

    MyString& operator=(const char* s);

    void trim();

    bool equals(const char* s);

    static MyString readString(const char* endChars);

    friend std::ostream& operator<<(std::ostream& stream, const MyString& str);
};