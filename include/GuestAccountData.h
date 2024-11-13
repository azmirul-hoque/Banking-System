#ifndef GUESTACCOUNT_H
#define GUESTACCOUNT_H

#include <iostream>
using namespace std;

class GuestAccountData {
public:
    std::string username;
    std::string password;
    int accountNumber;
    double initialBalance;

    GuestAccountData(const std::string& user, const std::string& pass, int accNum, double balance)
        : username(user), password(pass), accountNumber(accNum), initialBalance(balance) {}
      // Getter for accountNumber
    int getAccountNumber() const {
        return accountNumber;
    }
      // Additional getters for other attributes if needed
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    double getBalance() const { return initialBalance; }
};

#endif