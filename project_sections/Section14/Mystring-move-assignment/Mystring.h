#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char *str;
    
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    
    void display() const;
    int getLength() const;
    const char *getStr() const;
};

#endif // _MYSTRING_H_
