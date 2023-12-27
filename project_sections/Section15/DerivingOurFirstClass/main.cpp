#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main() {
    //Using the Account class
    cout << "\n**************Account**************" << endl;
    Account acc {};
    acc.deposit(2000.0);
    acc.withdraw(500.0);
    
    cout << endl;
    
    Account *pAcc {nullptr};
    pAcc = new Account();
    pAcc->deposit(1000.0);
    pAcc->withdraw(500.0);
    delete pAcc;
    
    //Using the Savings_Account class
    cout << "\n**************Savings Account**************" << endl;
    Savings_Account savAcc {};
    savAcc.deposit(2000.0);
    savAcc.withdraw(500.0);
    
    cout << endl;
    
    Savings_Account *pSavAcc {nullptr};
    pSavAcc = new Savings_Account();
    pSavAcc->deposit(1000.0);
    pSavAcc->withdraw(500.0);
    delete pSavAcc;
    
    cout << "\n********************************************************" << endl;
    
    return 0;
}