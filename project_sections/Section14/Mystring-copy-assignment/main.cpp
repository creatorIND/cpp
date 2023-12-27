#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring a("Hello");   //overloaded constructor
    Mystring b;     //no-args constructor
    b = a;      //copy assignment
                //b.operator=(a)
    b = "This is a test";   //b.operator=("This is a test")
    
    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge(larry);
    Mystring stooges;
    
    empty = stooge;
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe and Curly";
    stooges.display();
    
    vector<Mystring> stoogesVec;
    stoogesVec.push_back("Larry");
    stoogesVec.push_back("Moe");
    stoogesVec.push_back("Curly");
    
    cout << "======Loop 1======" << endl;
    for(const Mystring &s: stoogesVec) {
        s.display();
    }
    
    cout << "======Loop 2======" << endl;
    for(Mystring &s: stoogesVec) {
        s = "Changed";
    }
    
    cout << "======Loop 3======" << endl;
    for(const Mystring &s: stoogesVec) {
        s.display();
    }
    
    cout << endl;
    return 0;
}