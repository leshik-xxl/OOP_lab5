//
// Created by leshik on 03.03.20.
//

#include <cstring>
#include "String.h"

String::String()
{
    mystring = nullptr;
    length = 0;
}

String::String(size_t count, char ch)
{
    length = count;
    mystring = new char[length];
    for(int i = 0; i < length; i++)
    mystring[i] = ch;

}

String::String(const String& other, size_t pos, size_t count){
    if(pos >= other.size())
        throw out_of_range("pos >= other.size()");

    size_t buf = other.size();
    if((pos + count) < other.size()) buf = pos + count;
    length = buf - pos;

    mystring = new char[length];

    for(size_t i = pos; i < buf; i++)
        mystring[i-pos] = other.mystring[i];
}

String::String(const char* s){
    length = strlen(s);
    mystring = new char[length];
    for(int i = 0; i < length; i++)
        mystring[i] = s[i];
}

String::String(const String & other){
    length = other.length;
    mystring = new char[length];
    for(int i = 0; i < length; i++)
        mystring[i] = other.mystring[i];
}

size_t String::size() const
{
    return length;
}

String& String::operator=(const String& str){
    delete[] mystring;
    length = str.length;
    mystring = new char[length];
    for(int i = 0; i < length; i++)
        mystring[i] = str.mystring[i];
    return *this;
}

String& String::operator=(const char* s){
    size_t buf_len = strlen(s);
    delete[] mystring;
    length = buf_len;
    mystring = new char[length];
    for(int i = 0; i < length; i++)
        mystring[i] = s[i];
    return *this;
}

String& String::operator=(char ch){
    delete[] mystring;
    length = 1;
    mystring = new char[length];
    mystring[0] = ch;
    return  *this;
}

String& String::operator+=(const String& str){
    char* buff_str = new char[length + str.length];
    for(int i = 0; i < length; i++)
        buff_str[i] = mystring[i];

    for(int i = length; i< length + str.length; i++)
        buff_str[i] = str.mystring[i - length];

    length += str.length;
    delete[] mystring;
    mystring = buff_str;

    return *this;
}

String& String::operator+=(char* s){
    size_t s_len = strlen(s);
    char* buff_s = new char [length + s_len];
    for(int i = 0; i < length; i++)
        buff_s[i] = mystring[i];

    for(int i = length; i < length + s_len; i++)
        buff_s[i] = s[i - length];

    length += s_len;
    delete[] mystring;
    mystring = buff_s;

    return *this;
}

void String::resize(size_t count){
    char* buff = new char[count];
    if(count < length){
        for(int i = 0; i < count; i++)
            buff[i] = mystring[i];
    }else{
        for(int i = 0; i < length; i++)
            buff[i] = mystring[i];
    }

    length = count;
    delete [] mystring;
    mystring = buff;
}

void String::resize(size_t count, char ch){
    if(count <= length){
        resize(count);
    }else{
        size_t buff_len = length;
        resize(count);
        for(int i = buff_len; i < length; i++)
            mystring[i] = ch;
    }
}

void String::swap(String& other){
    char* buff_string1 = new char[length];
    char* buff_other = new char[other.length];

    for(int i = 0; i < length; i++)
        buff_string1[i] = mystring[i];
    for(int i = 0; i < other.length; i++)
        buff_other[i] = other.mystring[i];

    size_t buf_length = length;
    length = other.length;
    other.length =buf_length;

    delete[] mystring;
    delete[] other.mystring;
    mystring = buff_other;
    other.mystring = buff_string1;
}

void String::print() const {
    for (int i = 0; i < length; i++) {
        cout << mystring[i];
    }
    cout << '\n';
}

bool String::operator==(String &lhs){
    if(length == lhs.length){
        for(int i = 0; i < length; i++)
            if(mystring[i] != lhs.mystring[i]) return false;
        return true;
    }
    return false;
}

size_t String::find(const String& str, size_t pos) const{
    for(int i = pos; i < length; i++){
        bool isFind = true;
         for(int j = 0; j < str.length || length < i + j; j++){
             if(mystring[i + j] != str.mystring[j]){
                 isFind = false;
                 break;
             }
         }
         if(isFind) return i;
    }
    return -1;
}

size_t String::find_first_of(const char* s, size_t pos, size_t count) const{
    if(count > strlen(s)) count = strlen(s);
    for(int i = pos; i < length; i++){
        bool isFind = false;
        for(int j = 0; j < count; j++){
            if(mystring[i] == s[j]){
                isFind = true;
                break;
            }
        }
        if(isFind) return i;
    }
    return -1;
}

size_t String::find_first_not_of(const char* s, size_t pos, size_t count) const{

    for(int i = pos; i < length; i++){
        bool notFind = true;
        for(int j = 0; j < count; j++){
            if(mystring[i] == s[j]){
                notFind = false;
                break;
            }
        }
        if(notFind) return i;
    }
    return -1;
}

size_t String::find_last_not_of(const char* s, size_t pos, size_t count ) const{
    for(int i = pos - 1; i >= 0; i--){
        bool notFind = true;
        for(int j = count - 1; j >= 0; j--){
            if(mystring[i] == s[j]){
                notFind = false;
                break;
            }
        }
        if(notFind) return i;
    }
    return -1;
}

size_t String::rfind(const String & str, size_t pos) const{
    if (pos == npos) pos = 0;
    size_t i = -1;
    while (length >= pos + str.length && this->find(str, pos) != -1){
     i = this->find(str, pos);
     pos++;
    }
    return i;
}

String& String::append(const String &str,  size_t pos, size_t count){
    if(pos >= length)
        throw out_of_range("pos >= length");
    size_t countPlusPos = count + pos;
    if(countPlusPos > str.length) countPlusPos = str.length;

    char* buf = new char[length + countPlusPos - pos];
    for(int i = 0; i < length; i++){
        buf[i] = mystring[i];
    }

    for (int i = length; i < length + countPlusPos - pos; i++) {
        buf[i] = str.mystring[pos + i - length];
    }
    delete [] mystring;
    mystring = buf;
    length = length + countPlusPos - pos;

    return *this;
}

String::~String()
{
    delete[] mystring;
}