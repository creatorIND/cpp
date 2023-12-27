#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring larry {"Larry"};
    larry.display();
    
    larry = -larry;
    larry.display();
    
    cout << boolalpha << endl;
    Mystring moe {"Moe"};
    Mystring stooge = larry;
    
    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;
    
//    Mystring stooges = larry = "Moe";
    Mystring stooges = "Larry" + moe; // Now ok with global non-member functions
    stooges.display();
    
    Mystring twoStooges = moe + " " + "Larry";
    twoStooges.display();
    Mystring threeStooges = moe + " " + larry + " " + "Curly";
    threeStooges.display();
    return 0;
}