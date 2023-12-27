#include <cstring>
#include <iostream>
#include "Mystring.h"

Mystring::Mystring() : str {nullptr} {
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s) : str {nullptr} {
    if(s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source) : str {nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::~Mystring() {
    delete [] str;
}

void Mystring::display() const {
    std::cout << str << ": " << getLength() << std::endl;
}

int Mystring::getLength() const {
    return std::strlen(str);
}

const char *Mystring::getStr() const {
    return str;
}