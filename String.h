//
// Created by leshik on 03.03.20.
//

#ifndef OOP_LAB5_STRING_H
#define OOP_LAB5_STRING_H

#include <iostream>
using namespace std;


class String {

private:
   char * string1;
   int size;
   int npos = 1024;
public:
    explicit String();
    String( size_t count, char ch );

};


#endif //OOP_LAB5_STRING_H
