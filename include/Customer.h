#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Account.h"
#include "User.h"


class Customer : public User {
private:
    Account account;
public:
    Customer(const std::string& user, const std::string& pass, int accNum, double initialBalance)
        : User(user, pass), account(accNum, initialBalance) {}

    void deposit(double amount) {
        account.deposit(amount);
    }

    void withdraw(double amount) {
        account.withdraw(amount);
    }

    void displayBalance() {
        account.displayBalance();
    }

    void showPermissions() override {
        std::cout << "Customer permissions: Deposit, Withdraw, Check Balance\n";
    }
    
    int getAccountNumber() const {
        return account.getAccountNumber(); 
    }

    std::string getUsername() const { 
        return username; 
    }
     std::string getPassword() const { 
        return password; 
    }

    double getBalance() const { 
        return account.getBalance(); 
    }
};
#endif