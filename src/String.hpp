#pragma once
#include <iostream>

class String {
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

    static String readString(const char* endChars);

    friend std::ostream& operator<<(std::ostream& stream, const String& str);
};