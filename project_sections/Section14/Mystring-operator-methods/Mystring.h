#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char *str;
    
public:
    Mystring();  //No-args constructor
    Mystring(const char *s);  //Overloaded constructor
    Mystring(const Mystring &source);  //Copy constructor
    Mystring(Mystring &&source); //Move constructor
    ~Mystring();  //Destructor
    
    Mystring &operator=(const Mystring &rhs);  //Copy assignment
    Mystring &operator=(Mystring &&rhs);  //Move assignment
    
    Mystring operator-() const;  //make lowercase
    Mystring operator+(const Mystring &rhs) const;  //concatenate
    bool operator==(const Mystring &rhs) const;
    
    void display() const;
    int getLength() const;
    const char *getStr() const;
};

#endif // _MYSTRING_H_
