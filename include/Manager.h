// Derived Manager Class
#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include "GuestAccountData.h"
#include "Customer.h"
#include <algorithm>

#include "User.h"
class Manager : public User {
private:
    std::vector<Customer> approvedUsers;
    std::vector<GuestAccountData> guestAccounts;

public:
    Manager(const std::string& user, const std::string& pass) : User(user, pass) {}
    
    // Guest pending Account View
    void showPendingGuestAccounts() const {
    if (guestAccounts.empty()) {
        std::cout << "No pending guest accounts.\n";
        return;
    }

    std::cout << "Pending Guest Accounts:\n";
    for (const auto& guest : guestAccounts) {
        std::cout << "Username: " << guest.username
                  << ", Account Number: " << guest.accountNumber
                  << ", Initial Balance: $" << guest.initialBalance << "\n";
    }
}
    // Add guest Account by Applicant
    // Store guest account data
    void addGuestAccount(const std::string& username, const std::string& password, int accNum, double balance) {
        guestAccounts.push_back(GuestAccountData(username, password, accNum, balance));
        std::cout << "I got it will be approved soon!";
    }

   bool approveGuestAccount(int accountNumber) {
    // Find guest account by account number
    auto it = std::find_if(guestAccounts.begin(), guestAccounts.end(),
                           [accountNumber](const GuestAccountData& guest) {
                               return guest.getAccountNumber() == accountNumber;
                           });

    // If account is found, create a Customer object, move it to approvedUsers, and remove from guestAccounts
    if (it != guestAccounts.end()) {
        // Create an approved Customer object using the guest data
        Customer approvedCustomer(it->getUsername(), it->getPassword(), it->getAccountNumber(), it->getBalance());

        // Add the approved Customer object to the approvedUsers vector
        approvedUsers.push_back(approvedCustomer);

        // Remove the guest account from guestAccounts
        guestAccounts.erase(it);

        return true;  // Approval successful
    }

    return false;  // Account not found
}

   void showApprovedAccount() const {
    if (approvedUsers.empty()) {
        std::cout << "No approved users.\n";
        return;
    }

    std::cout << "Approved Users:\n";
    for (const auto& user : approvedUsers) {
        std::cout << "Username: " << user.getUsername() 
                  << ", Account Number: " << user.getAccountNumber() 
                  << ", Balance: $" << user.getBalance() << "\n";
    }
}

    Customer* findCustomer(const std::string& username, const std::string& password) {
    auto it = std::find_if(approvedUsers.begin(), approvedUsers.end(),
                           [&](const Customer& customer) {
                               return customer.getUsername() == username && 
                                      customer.getPassword() == password;
                           });
    
    if (it != approvedUsers.end()) {
        return &(*it); // Return a pointer to the found customer
    }
    return nullptr; // Return null if no matching customer is found
}

    void transferTo(const Customer& customer, int amount) const{
        if(amount > customer.getBalance()){
            std:: cout << "Insufficient Balance";
        }else{

        }
    }

     Customer* findCustomerByAccountNumber(int accountNumber) {
        for (auto& customer : approvedUsers) {
            if (customer.getAccountNumber() == accountNumber) {
                return &customer;  // Return pointer to the found customer
            }
        }
        std::cout << "Customer with account number " << accountNumber << " not found.\n";
        return nullptr;  // Return nullptr if customer not found
    }

    void TransferTo(Customer& customer, double amount, int recipientAcc) {
        // Check if the sender (customer) has sufficient balance
        if (amount > customer.getBalance()) {
            std::cout << "Insufficient Balance\n";
            return;
        }

        // Find the recipient customer
        Customer* recipient = findCustomerByAccountNumber(recipientAcc);
        if (recipient == nullptr) {
            std::cout << "Recipient not found.\n";
            return;
        }

        // Proceed with the transfer
        customer.withdraw(amount);  // Withdraw from sender
        recipient->deposit(amount);  // Deposit into recipient

        std::cout << "Transfer successful! " << amount << " transferred from "
                  << customer.getUsername() << " to " << recipient->getUsername() << ".\n";
    }

    void showPermissions() override {
        std::cout << "Manager Permissions: Approve Accounts, Delete Accounts.\n";
    }
  
    void deleteAccount() {
        std::cout << "Account Deleted.\n";
    }
};

#endif