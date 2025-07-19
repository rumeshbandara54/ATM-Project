#include "forgotPassword.h"
#include <iostream>

forgotPassword::forgotPassword(std::vector<User>& users) : users(users) {
   
}

void forgotPassword::forgotPasswordMenu() {
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

    bool userFound = false;

    for (auto& user : users) {
        if (user.username == username) {
            std::string newPassword;
            std::cout << "User found. Enter new password: ";
            std::cin >> newPassword;
            user.password = newPassword;
            std::cout << "Password reset successful.\n";
            userFound = true;
            break;
        }
    }

    if (!userFound) {
        std::cout << "User not found.\n";
    }
}
