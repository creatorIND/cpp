#include <iostream>
#include <cstring>
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

Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment" << std::endl;
    if(this == &rhs) {
        return *this;
    }
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

void Mystring::display() const {
    std::cout << str << ": " << getLength() << std::endl;
}

int Mystring::getLength() const {
    return strlen(str);
}

const char *Mystring::getStr() const {
    return str;
}