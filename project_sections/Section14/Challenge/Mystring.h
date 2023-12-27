#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);
    
    char *str;
public:
    Mystring(); //No-args constructor
    Mystring(const char *s); //Overloaded constructor
    Mystring(const Mystring &source); //Copy constructor
    Mystring(Mystring &&source); //Move constructor
    ~Mystring(); //Destructor
    
    Mystring &operator=(const Mystring &rhs); //Copy assignment
    Mystring &operator=(Mystring &&rhs); //Move assignment
    
    Mystring operator-() const;
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    Mystring operator+(const Mystring &rhs) const;
    Mystring operator*(int num) const;    
    Mystring &operator+=(const Mystring &rhs);
    Mystring &operator*=(int n);
    Mystring &operator++();
    Mystring operator++(int);
    
    void display() const;
    
    int getLength() const;
    const char *getStr() const;
};

#endif // _MYSTRING_H_