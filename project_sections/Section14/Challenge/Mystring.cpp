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
//    std::cout << "Copy constructor used" << std::endl;
}

//Move constructor
Mystring::Mystring(Mystring &&source) : str {source.str} {
    source.str = nullptr;
//    std::cout << "Move constructor used" << std::endl;
}

//Destructor
Mystring::~Mystring() {
    delete [] str;
}

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;
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
//    std::cout << "Using move assignment" << std::endl;
    if(this == &rhs) {
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//Unary minus
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i {}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//Equality operator
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

//Inequality operator
bool Mystring::operator!=(const Mystring &rhs) const {
    return !(std::strcmp(str, rhs.str) == 0);
}

//Less than
bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

//Greater than
bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

//Concatenation
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//Concatenate and store
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

//Repeat n times
Mystring Mystring::operator*(int num) const {
    Mystring temp;
    for(int i {1}; i <= num; i++) {
        temp  = temp + *this;
    }
    return temp;
//    char *buff = new char[(std::strlen(str) * num) + 1];
//    std::strcpy(buff, "");
//    for(int i {}; i < num; i++) {
//        std::strcat(buff, str);
//    }
//    Mystring temp {buff};
//    delete [] buff;
//    return temp;
}

//Repeat and store
Mystring &Mystring::operator*=(int num) {
    *this = *this * num;
    return *this;
}

//Pre-increment
Mystring &Mystring::operator++() {
    for(size_t i {}; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

//Post-increment
Mystring Mystring::operator++(int) {
    Mystring temp {*this};
    operator++();
    return temp;
}

//Display method
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
    rhs = Mystring{buff};
    delete [] buff;
    return is;
}