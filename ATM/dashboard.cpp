#include "dashboard.h"
#include <iostream>

// Constructor
dashboard::dashboard(std::vector<User>& users, User* currentUser) : users(users), currentUser(currentUser) {

}

void dashboard::mainMenu() {
    int choice;
    while (true) {
        std::cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Logout\nChoose: ";
        std::cin >> choice;

        switch (choice) {
        case 1: checkBalance(); break;
        case 2: deposit(); break;
        case 3: withdraw(); break;
        case 4: currentUser = nullptr; return;
        default: std::cout << "Invalid choice.\n";
        }
    }
}

void dashboard::checkBalance() {
    std::cout << "Your balance: " << currentUser->balance << "\n";
}

void dashboard::deposit() {
    double amount;
    std::cout << "Enter Amount to deposit: "; std::cin >> amount;
    if (amount > 0) {
        currentUser->balance += amount;
        std::cout << "Deposit successful.\n";
    }
    else {
        std::cout << "Enter the correct amount.\n";
    }
}

void dashboard::withdraw() {
    double amount;
    std::cout << "Enter Amount to withdraw: "; std::cin >> amount;
    if (amount > 0 && amount <= currentUser->balance) {
        currentUser->balance -= amount;
        std::cout << "Withdrawal successful.\n";
    }
    else {
        std::cout << "Invalid amount or insufficient funds.\n";
    }
}
