#include "ATM.h"
#include <iostream>
#include "Logger.h"

#include "admin.h"
#include "forgotPassword.h"
#include "dashboard.h"



void ATM::start() {
    int choice;
    Admin admin(users); // create admin manager

    branchManager.preloadDefaultBranches(); //  Load Main Menustart


    while (true) {
        std::cout << "\n====== ATM System ======\n";
        std::cout << "1. ATM Login Panel\n";
        std::cout << "2. ATM Register Panel\n";
        std::cout << "3. Branch Management\n";  
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            loginUser();
            break;
        case 2:
            admin.adminMenu();
            break;
        case 3:
            branchManager.manageBranch();  
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}




//void ATM::registerUser() {
//    std::string username, password;
//    std::cout << "Enter username: "; std::cin >> username;
//    std::cout << "Enter password: "; std::cin >> password;
//
//    users.push_back(User(username, password, 0.0));
//    std::cout << "Registration successful.\n";
//    Logger::log("User registered: " + username);
//
//}

void ATM::loginUser() {
    int attempts = 0;
    const int maxAttempts = 3; //user enter wrng pass word or user name you have 3 time try log 
    bool loginSuccess = false;

    while (attempts < maxAttempts && !loginSuccess) {
        std::string username, password;
        std::cout << "Enter User Name: ";
        std::cin >> username;
        std::cout << "Enter Password: ";
        std::cin >> password;

        Logger::log("User login attempt: " + username);

        for (auto& user : users) {
            if (user.username == username && user.password == password) {
                currentUser = &user;
                std::cout << "Login successful.\n";
                Logger::log("User login successful: " + username);
                loginSuccess = true;
                break;
            }
        }

        if (!loginSuccess) {
            attempts++;
            std::cout << "Login failed. Attempt " << attempts << " of " << maxAttempts << ".\n";
            Logger::log("User login failed: " + username);
        }
    }

    if (loginSuccess) {
        //  Correct call to dashboard
        dashboard userDashboard(users, currentUser);
        userDashboard.mainMenu();
    }
    else {
        // After 3 failed attempts
        std::string choice;
        std::cout << "You've lost your chance.Try another approach.\n";
        std::cout << "Do you want to go to the ForgotPassword page? (yes/no): ";
        std::cin >> choice;

        if (choice == "yes" || choice == "Yes" || choice == "Y" || choice == "y") {
            forgotPassword forgotPassword(users);
            forgotPassword.forgotPasswordMenu();
        }
        else {
            std::cout << "Returning to the System...\n";
        }
    }
}




//void ATM::mainMenu() {
//    int choice;
//    while (true) {
//        std::cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Logout\nChoose: ";
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1: checkBalance(); break;
//        case 2: deposit(); break;
//        case 3: withdraw(); break;
//        case 4: currentUser = nullptr; return;
//        default: std::cout << "Invalid choice.\n";
//        }
//    }
//}
//
//void ATM::checkBalance() {
//    std::cout << "Your balance: " << currentUser->balance << "\n";
//}
//
//void ATM::deposit() {
//    double amount;
//    std::cout << "Enter amount to deposit: "; std::cin >> amount;
//    if (amount > 0) {
//        currentUser->balance += amount;
//        std::cout << "Deposit successful.\n";
//    }
//    else {
//        std::cout << "Invalid amount.\n";
//    }
//}
//
//void ATM::withdraw() {
//    double amount;
//    std::cout << "Enter amount to withdraw: "; std::cin >> amount;
//    if (amount > 0 && amount <= currentUser->balance) {
//        currentUser->balance -= amount;
//        std::cout << "Withdrawal successful.\n";
//    }
//    else {
//        std::cout << "Invalid amount or insufficient funds.\n";
//    }
//}
