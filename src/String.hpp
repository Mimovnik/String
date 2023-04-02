#pragma once
#include <iostream>

class String {
   private:
    char* content = nullptr;

    unsigned int length = 0;

    static bool containsChar(const char* array, char contained);

    static unsigned int getLength(const char* cstring);

    static void copy(const char* source, char* destination,
                     unsigned int length);

    static bool equals(const char* first, const char* second);

   public:
    String();

    ~String();

    String(const String& other);

    String& operator=(const String& other);

    String(String&& other);

    String& operator=(String&& other);

    String(const char* s);

    String& operator=(const char* s);

    void trim();

    bool equals(const char* s);

    static String readString(const char* endChars, int maxReadLength = 64);

    friend std::ostream& operator<<(std::ostream& stream, const String& str);
};