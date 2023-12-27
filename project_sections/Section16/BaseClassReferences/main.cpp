#include <iostream>

using namespace std;

//This class uses dynamic polymorphism for the withdraw method
//We'll learn about virtual functions in the next video
class Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Account::withdraw" << std::endl;
	}
	virtual ~Account() {}
};

class Checking: public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Checking::withdraw" << std::endl;
	}
	virtual ~Checking() {}
};

class Savings: public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Savings::withdraw" << std::endl;
	}
	virtual ~Savings() {}
};

class Trust: public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Trust::withdraw" << std::endl;
	}
	virtual ~Trust() {}
};

void doWithdraw(Account &account, double amount) {
	account.withdraw(amount);
}

int main() {
	Account a;
	Account &ref = a;
	ref.withdraw(1000);
	
	Trust t;
	Account &ref1 = t;
	ref1.withdraw(1000);
	
	Account a1;
	Savings a2;
	Checking a3;
	Trust a4;
	
	doWithdraw(a1, 1000);
	doWithdraw(a2, 2000);
	doWithdraw(a3, 3000);
	doWithdraw(a4, 4000);
	
	return 0;
}