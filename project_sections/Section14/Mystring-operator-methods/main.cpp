#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;
    
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    
    Mystring stooge = larry;
    larry.display();
    moe.display();
    
    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;
    
    larry.display();
    Mystring larry2 = -larry;
    larry2.display();
    
    Mystring stooges = larry + "Moe"; // ok with member function
//    Mystring stooges = "Larry" + moe; // compiler error
    
    Mystring twoStooges = moe + " " + "Larry";
    twoStooges.display();
    
    Mystring threeStooges = moe + " " + larry + " " + "Curly";
    threeStooges.display();
    
    return 0;
}