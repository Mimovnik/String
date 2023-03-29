#pragma once
#include <iostream>

class MyString {
   private:
    char* content = nullptr;

    int length = 0;

   public:
    MyString();

    MyString(const char* s);

    ~MyString();

    MyString operator+(MyString const& other);

    MyString& operator=(const char* s);

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};