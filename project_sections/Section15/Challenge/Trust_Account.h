#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
	friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
	
private:
	static constexpr const char *defaultName = "Unnamed Trust Account";
	static constexpr double defaultBalance = 0.0;
	static constexpr double defaultInterestRate = 0.0;
	static constexpr double bonusAmount = 50.0;
	static constexpr double bonusThreshold = 5000.0;
	static constexpr int maxWithdrawals = 3;
	static constexpr double maxWithdrawPercent = 0.2;
	
protected:
	int numWithdrawals;
	
public:
	Trust_Account(std::string name = defaultName, double balance = defaultBalance, double interestRate = defaultInterestRate);
	
	//Deposits of $5000.0 or more will receive $50 bonus
	bool deposit(double amount);
	
	//Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
	bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
