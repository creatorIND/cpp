#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account: public Account {
	friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
	
private:
	static constexpr const char *defaultName = "Unnamed Checking Account";
	static constexpr double defaultBalance = 0.0;
	static constexpr double perCheckFee = 1.5;
	
public:
	Checking_Account(std::string name = defaultName, double balance = defaultBalance);
	bool withdraw(double amount);
	//Inherits the Account::deposit method
};

#endif // _CHECKING_ACCOUNT_H_
