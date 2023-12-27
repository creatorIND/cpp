#include <iostream>

using namespace std;

class Base {
    //Note friends of Base have access to all
public:
    int a {};
    void display() {
        cout << a << ", " << b << ", " << c << endl; //member method has access to all
    }
    
protected:
    int b {0};
    
private:
    int c {0};
};

class Derived: public Base {
    //Note friends of Derived have access to only what Derived has access
    
    //a will be public
    //b will be protected
    //c will not be accessible
    
public:
    void accessBaseMember() {
        a = 100;
        b = 200;
//        c = 300; // not accessible
    }
};

int main() {
    cout << "****Base member access from base objects****" << endl;
    Base base;
    base.a = 100;
//    base.b = 200; // Compiler error
//    base.c = 300; // Compiler error
    
    cout << "****Base member access from derived objects****" << endl;
    Derived d;
    d.a = 100;
//    d.b = 200; // Compiler error
//    d.c = 300; // Compiler error
    
    return 0;
}