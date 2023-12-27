#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double interestRate) : Account{name, balance}, interestRate(interestRate) {}

bool Savings_Account::deposit(double amount) {
    amount += amount * (interestRate / 100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "[Savings Account: " << account.name << ": " << account.balance << ", " << account.interestRate << "%]";
    return os;
}