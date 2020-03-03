//
// Created by leshik on 03.03.20.
//

#include "String.h"

String::String() {
    size = 0;
}

String::String(size_t count, char ch) {
    size = count;
    string1 = new char[size];
    for (int i = 0; i < size; i++) {
        string1[i] = ch;
    }
}


