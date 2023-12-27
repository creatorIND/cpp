#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

class Savings_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
    
private:
    static constexpr const char *defaultName = "Unnamed Savings Account";
    static constexpr double defaultBalance = 0.0;
    static constexpr double defaultInterestRate = 0.0;
    
protected:
    double interestRate;
    
public:
    Savings_Account(std::string name = defaultName, double balance = defaultBalance, double interestRate = defaultInterestRate);
    bool deposit(double amount);
    //Inherits the Account::withdraw method
};

#endif // _SAVINGS_ACCOUNT_H_
