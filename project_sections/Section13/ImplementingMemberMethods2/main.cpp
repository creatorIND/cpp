#include <iostream>
#include "Account.h"

using namespace std;

int main() {
    Account sujalAccount;
    sujalAccount.setName("Sujal's Account");
    sujalAccount.setBalance(1000.0);
    
    if(sujalAccount.deposit(200.0))
        cout << "Amount deposited in your account :)" << endl;
    else
        cout << "Your transaction is declined" << endl;
    
    if(sujalAccount.withdraw(500.0))
        cout << "Please wait to collect your 500 INR cash..." << endl;
    else
        cout << "Insufficient funds" << endl;
    
    if(sujalAccount.withdraw(1500.0))
        cout << "Please wait to collect your 1500 INR cash..." << endl;
    else
        cout << "Insufficient funds" << endl;
    cout << endl;
    return 0;
}