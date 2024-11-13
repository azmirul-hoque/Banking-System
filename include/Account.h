#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;
public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    
    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: " << amount << "\n";
    }
    void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew: " << amount << "\n";
        } else {
            std::cout << "Insufficient funds.\n";
        }
    }
    void displayBalance() {
        std::cout << "Current Balance: " << balance << "\n";
    }
    int getAccountNumber() const{
        return accountNumber;
    }
    double getBalance() const{
        return balance;
    }
};

#endif