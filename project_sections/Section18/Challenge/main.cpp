#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

int main() {
    std::unique_ptr<Account> moesAccount;
	std::unique_ptr<Account> larrysAccount;
	try {
		larrysAccount = std::make_unique<Savings_Account>("Larry", -2000.0);
		std::cout << *larrysAccount << std::endl;
	}
	catch(const IllegalBalanceException &ex) {
		std::cerr << ex.what() << std::endl;
	}
	
	try {
		moesAccount = std::make_unique<Savings_Account>("Moe", 1000.0);
		std::cout << *moesAccount << std::endl;
		moesAccount->withdraw(500.0);
		std::cout << *moesAccount << std::endl;
		moesAccount->withdraw(1000.0);
		std::cout << *moesAccount << std::endl;
	}
	catch(const IllegalBalanceException &ex) {
		std::cerr << ex.what() << std::endl;
	}
	catch(const InsufficientFundsException &ex) {
		std::cerr << ex.what() << std::endl;
	}
	
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

