#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string name;
    double balance;
    
public:
    void setBalance(double bal) {
        balance = bal;
    }
    
    double getBalance() {
        return balance;
    }
    
    //methods will be declared outside the class declaration
    void setName(string n);
    string getName();
    
    bool deposit(double amount);
    bool withdraw(double amount);
};

void Account::setName(string n) {
    name = n;
}

string Account::getName() {
    return name;
}

bool Account::deposit(double amount) {
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if(balance - amount >= 0) {
        balance -= amount;
        return true;
    }
    else {
        return false;
    }
}

int main() {
    Account sujalAccount;
    sujalAccount.setName("Sujal's Account");
    sujalAccount.setBalance(1000.0);
    
    if(sujalAccount.deposit(200.0))
        cout << "Amount deposited in your account :)" << endl;
    else
        cout << "Your transaction is declined" << endl;
    
    if(sujalAccount.withdraw(500.0))
        cout << "Please wait to collect your 500 INR cash..." << endl;
    else
        cout << "Insufficient funds" << endl;
    
    if(sujalAccount.withdraw(1500.0))
        cout << "Please wait to collect your 1500 INR cash..." << endl;
    else
        cout << "Insufficient funds" << endl;
    cout << endl;
    return 0;
}