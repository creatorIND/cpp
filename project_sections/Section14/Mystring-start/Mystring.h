#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char *str; //pointer to a char[] that holds a C-style string
    
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    ~Mystring();
    
    void display() const;
    int getLength() const;
    const char *getStr() const;
};

#endif // _MYSTRING_H_
