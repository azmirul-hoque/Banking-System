// Derived Admin Class
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Manager.h"
#include "Customer.h"
#include "Account.h"
#include <iostream>

class Admin : public User{
public:
    Admin(const std::string& user, const std::string& pass) : User(user, pass) {}
    void showPermissions() override {
        std::cout << "Admin Permissions: Full Access, Create/Delete Manager.\n";
    }
    void createManager() {
        std::cout << "Manager Created.\n";
    }
    void deleteManager() {
        std::cout << "Manager Deleted.\n";
    }
};

#endif