#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
	
    //Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000});
    accounts.push_back(Account {"Curly", 5000});
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    //Savings
    vector<Savings_Account> savAccounts;
    savAccounts.push_back(Savings_Account {});
    savAccounts.push_back(Savings_Account {"Superman"});
    savAccounts.push_back(Savings_Account {"Batman", 2000});
    savAccounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0});
    
    display(savAccounts);
    deposit(savAccounts, 1000);
    withdraw(savAccounts, 2000);
	
	//Checking
	vector<Checking_Account> checkAccounts;
	checkAccounts.push_back(Checking_Account {});
	checkAccounts.push_back(Checking_Account {"Kirk"});
	checkAccounts.push_back(Checking_Account {"Spock", 2000});
	checkAccounts.push_back(Checking_Account {"Bones", 5000});
	
	display(checkAccounts);
	deposit(checkAccounts, 1000);
	withdraw(checkAccounts, 2000);
	
	//Trust
	vector<Trust_Account> trustAccounts;
	trustAccounts.push_back(Trust_Account {});
	trustAccounts.push_back(Trust_Account {"Athos", 10000, 5.0});
	trustAccounts.push_back(Trust_Account {"Porthos", 20000, 4.0});
	trustAccounts.push_back(Trust_Account {"Aramis", 30000});
	
	display(trustAccounts);
	deposit(trustAccounts, 1000);
	withdraw(trustAccounts, 3000);
	
	//Withdraw 5 times from each Trust Account
	//All withdrawals should fail if there are too many withdrawals or if the withdrawal is >20% of the balance
	for(int i {1}; i <= 5; i++) {
		withdraw(trustAccounts, 1000);
	}
    
	cout << endl;
    return 0;
}