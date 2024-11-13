#include <iostream>
#include "Admin.h"
#include "Account.h"
#include "Customer.h"
#include "Manager.h"
#include "User.h"
using namespace std;


void showCustomerOptions(Customer& customer, Manager& manager) {
    int option;
    double amount;
    while (true) {
        std::cout << "\nCustomer Menu:\n";
        std::cout << "1. Withdraw Money\n";
        std::cout << "2. Add Money\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Transfer Money\n";
        std::cout << "5. Logout\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 5) break;  // Logout and return to main menu

        switch (option) {
            case 1:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                customer.withdraw(amount);
                break;
            case 2:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                customer.deposit(amount);
                break;
            case 3:
                customer.displayBalance();
                break;
            case 4:
                double Toamount;
                int recipientAccount;
                std::cout << " Enter Account Number: ";
                std::cin >> recipientAccount;
                std:: cout << "Enter Amount to be send";
                std::cin >> Toamount;
                manager.TransferTo(customer, Toamount, recipientAccount);
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }
}

void showManagerOptions(Manager& manager) {
    int option;
    while (true) {
        std::cout << "\nManager Menu:\n";
        std::cout << "1. Show pending Approval Account\n";
        std::cout << "2. Approve Now\n";
        std::cout << "3. Delete Customer Account\n";
        std::cout << "4. Show Approved Account\n";
        std::cout << "5. Logout\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 5) break;  // Logout and return to main menu

        switch (option) {
            case 1:
                std::cout << "----Approve account----\n";
                manager.showPendingGuestAccounts();
                break;
            case 2:
                    //Approve Now
                    int accNo; 
                    std::cout << "Enter your Account No. ";
                    std::cin >> accNo;
                    manager.approveGuestAccount(accNo);
                    break;
            case 3:
                std::cout << "Deleting customer account...\n";
                // Implement delete account logic here
                break;
            case 4:
                manager.showApprovedAccount();
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }
}

int showAdminOptions(Admin& admin) {
    int option;
    double admin_value;
    while (true) {
        std::cout << "\nAdmin Menu:\n";
        std::cout << "1. Create Manager\n";
        std::cout << "2. Delete Manager\n";
        std::cout << "3. Logout\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 3) break;  // Logout and return to main menu

        switch (option) {
            case 1:
                std::cout << "Creating manager...\n";
                // Implement create manager logic here
                break;
            case 2:
                std::cout << "Deleting manager...\n";
                // Implement delete manager logic here
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }
}

// Guest Options 
int showGuestOptions(Manager& manager) {
    int option;
    while (true) {
        std::cout << "\nGuest Menu:\n";
        std::cout << "1. Apply for new Saving Account\n";
        std::cout << "2. Login Existing Account\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;
        
        if (option == 3) break;

        switch (option) {
            case 1: {
                std::string username, password;
                int accountNumber;
                double initialBalance;
                
                std::cout << "----Apply for New Saving Account----\n";
                std::cout << "Enter Username: ";
                std::cin >> username;
                std::cout << "Enter Password: ";
                std::cin >> password;
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Initial Balance: ";
                std::cin >> initialBalance;

                manager.addGuestAccount(username, password, accountNumber, initialBalance);
                std::cout << "Account request submitted. Waiting for approval.\n";
                break;
            }
            case 2:
                std::cout << "Login Coming soon!\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}


void loginSystem(User* user) {
    std::string username, password;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    if (user->login(username, password)) {
        std::cout << "Login Successful.\n";
        user->showPermissions();
    } else {
        std::cout << "Login Failed. Try again.\n";
    }
}

void customerLogin(Manager& manager) {
    std::string username, password;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    Customer* customer = manager.findCustomer(username, password);

    if (customer != nullptr) {
        std::cout << "Login Successful.\n";
        // Show customer options after login
        showCustomerOptions(*customer, manager);
    } else {
        std::cout << "Login Failed. Invalid username or password.\n";
    }
}

int main() {
     Admin admin("adminUser", "adminPass");
     Manager manager("manUser", "manPass");

    int roleChoice;
    while (true) {
        std::cout << "\nSelect Role to Login (1: Customer, 2: Manager, 3: Admin, 4: Guest, 5: Exit): ";
        std::cin >> roleChoice;

        if (roleChoice == 5) {
            std::cout << "Exiting system.\n";
            break;
        }

        switch (roleChoice) {
            case 1:
                 customerLogin(manager);
                break;
            case 2:
                if (manager.login("manUser", "manPass")) {
                    showManagerOptions(manager);
                }
                break;
            case 3:
               if (admin.login("adminUser", "adminPass")) {
                    showAdminOptions(admin);
                }
                break;
            case 4:
                showGuestOptions(manager);
                break;
            default:
                std::cout << "Invalid choice. Please select a valid role.\n";
        }
    }
    return 0;
}
