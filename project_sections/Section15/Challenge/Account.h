#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
    
private:
    static constexpr const char *defaultName = "Unnamed Account";
    static constexpr double defaultBalance = 0.0;
    
protected:
    std::string name;
    double balance;
    
public:
    Account(std::string name = defaultName, double balance = defaultBalance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};

#endif // _ACCOUNT_H_