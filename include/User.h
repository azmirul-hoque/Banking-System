// Base User Class
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
protected:
    std::string username;
    std::string password;
public:
    User(const std::string& user, const std::string& pass) : username(user), password(pass) {}
    virtual void showPermissions() = 0;  // Pure virtual function for specific roles
    bool login(const std::string& user, const std::string& pass) {
        return (username == user && password == pass);
    }
};

#endif