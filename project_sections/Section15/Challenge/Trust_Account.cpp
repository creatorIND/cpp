#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double interestRate) :Savings_Account{name, balance, interestRate}, numWithdrawals{0} {}

//Deposit additional $50 bonus when amount >= $5000
bool Trust_Account::deposit(double amount) {
	if(amount >= bonusThreshold)
		amount += bonusAmount;
	return Savings_Account::deposit(amount);
}

//Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool Trust_Account::withdraw(double amount) {
	if(numWithdrawals >= maxWithdrawals || (amount > balance * maxWithdrawPercent))
		return false;
	else {
		++numWithdrawals;
		return Savings_Account::withdraw(amount);
	}
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
	os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.interestRate << "%, Withdrawals: " << account.numWithdrawals << "]";
	return os;
}