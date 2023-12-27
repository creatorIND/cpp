#include <iostream>
#include <cstring>
#include "Mystring.h"

//No-args constructor
Mystring::Mystring() : str {nullptr} {
    str = new char[1];
    *str = '\0';
}

//Overloaded constructor
Mystring::Mystring(const char *s) : str {nullptr} {
    if(s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

//Copy constructor
Mystring::Mystring(const Mystring &source) : str {nullptr} {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
}

//Move constructor
Mystring::Mystring(Mystring &&source) : str {source.str} {
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

//Destructor
Mystring::~Mystring() {
    delete [] str;
}

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;
    if(this == &rhs) {
        return *this;
    }
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

//Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if(this == &rhs) {
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

void Mystring::display() const {
    std::cout << str << " : " << getLength() << std::endl;
}

int Mystring::getLength() const {
    return strlen(str);
}

const char *Mystring::getStr() const {
    return str;
}

//Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

//Overloaded extraction operator
std::istream &operator>>(std::istream &is, Mystring &rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = Mystring(buff);
    delete [] buff;
    return is;
}