//
// Created by leshik on 03.03.20.
//

#ifndef OOP_LAB5_STRING_H
#define OOP_LAB5_STRING_H

#include <iostream>
//#include <cstdlib>
using namespace std;
static const int npos = 1024;

class String {

private:
    size_t length;
    char* mystring;
public:

    ~String();
    explicit String();
    String(size_t count, char ch);
    String(const String& other, size_t pos, size_t count = npos);
    String(const char* s);
    String(const String &);
    size_t size() const;
    String& operator=(const String& str);
    String& operator=(const char* s);
    String& operator=(char ch );
    String& operator+=(const String& str);
    String& operator+=(char* s);
    void resize(size_t count);
    void resize(size_t count, char ch);
    void swap(String& other);
    bool operator==(String &lhs);
    size_t find(const String& str, size_t pos = 0) const; // return -1 if can`t find
    size_t find_first_of(const char* s, size_t pos, size_t count) const; // return -1 if can`t find
    size_t find_first_not_of(const char* s, size_t pos, size_t count) const; // return -1 if can`t find
    size_t find_last_not_of(const char* s, size_t pos, size_t count ) const; // return -1 if can`t find
    size_t rfind(const String & str, size_t pos = npos) const; // return -1 if can`t find
    String& append(const String &str,  size_t pos, size_t count);
    void print() const;

};

#endif //OOP_LAB5_STRING_H