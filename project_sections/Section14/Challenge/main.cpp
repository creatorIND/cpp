#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;
    Mystring a {"sujal"};
    Mystring b {"sujal"};
    
    cout << (a == b) << endl; //true
    cout << (a != b) << endl; //false
    
    b = "creator";
    cout << (a == b) << endl; //false
    cout << (a != b) << endl; //true
    cout << (a < b) << endl; //false
    cout << (a > b) << endl; //true
    
    Mystring s1 {"SUJAL"};
    s1 = -s1;
    cout << s1 << endl; //sujal
    
    s1 = s1 + "*****";
    cout << s1 << endl; //sujal*****
    
    s1 += "-----";
    cout << s1 << endl; //sujal*****-----
    
    Mystring s2 {"12345"};
    s1 = s2 * 3;
    cout << s1 << endl; //123451234512345
    
    Mystring s3 {"abcdef"};
    s3 *= 5;
    cout << s3 << endl; //abcdefabcdefabcdefabcdefabcdef
    
    Mystring repeatString;
    int repeatTimes {};
    cout << "Enter a string to repeat: ";
    cin >> repeatString;
    cout << "How many times do you want it repeated? ";
    cin >> repeatTimes;
    repeatString *= repeatTimes;
    cout << "The resulting string is:\n" << repeatString << endl;
    
    cout << (repeatString * 12) << endl;
    
    repeatString = "RepeatMe";
    cout << (repeatString + repeatString + repeatString) << endl;
    
    repeatString += (repeatString * 3);
    cout << repeatString << endl;
    
    Mystring s = "Sujal";
    ++s;
    cout << s << endl; //SUJAL
    
    s = -s;
    cout << s << endl; //sujal
    
    Mystring result;
    result = ++s;
    cout << s << endl; //SUJAL
    cout << result << endl; //SUJAL
    
    s = "Sujal";
    s++;
    cout << s << endl; //SUJAL
    
    s = -s;
    cout << s << endl; //sujal
    result = s++;
    cout << s << endl; //FRANK
    cout << result << endl; //frank
    
    return 0;
}