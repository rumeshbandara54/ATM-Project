#include "admin.h"
#include <iostream>
#include "Logger.h"

Admin::Admin(std::vector<User>& users) : users(users) {}

void Admin::adminMenu() {
    int choice;

    while (true) {
        std::cout << "\n====== Admin Panel ======\n";
        std::cout << "1. Register User\n";
        std::cout << "2. Show All Users\n";
        std::cout << "3. Cancel User Account \n";
        std::cout << "4. Exit to Main Menu\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            showUsers();
            break;
        case 3:
            deleteUser();
            break;
        case 4:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void Admin::registerUser() {
    std::string username, password, email, TP, branchCode, address;
    double balance;

    std::cout << "Enter User Name: ";
    std::cin >> username;

    std::cout << "Enter Password: ";
    std::cin >> password;

    std::cout << "Enter Email: ";
    std::cin.ignore(); //you can skip
    std::cin >> email;

    std::cout << "Enter Telephone Number: ";
    std::cin >> TP;

    std::cout << "Enter Branch Code: ";
    std::cin >> branchCode;

    std::cout << "Enter Address: ";
    std::cin.ignore();  // you can skip address values
    std::getline(std::cin, address);

    std::cout << "Enter balance: ";
    std::cin >> balance;

    // Create user with all details
    User newUser(username, password, email, TP, branchCode, address, balance);
    users.push_back(newUser);

    std::cout << "User registered successfully.\n";
    Logger::log("Admin registered new user: " + username); //Log file
}


void Admin::showUsers() {
    std::cout << "\n===== User List =====\n";
    for (const auto& user : users) {
        std::cout << "Name: " << user.username << " | Branch Code: " << user.branchCode << " | Email: " << user.email << " | Phone number Code: " << user.TP <<" \n";
    }
}


void Admin::deleteUser() {
    std::string username;
    std::cout << "Enter User Name: ";
    std::cin >> username;

    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->username == username) {
            users.erase(it);
            std::cout << "User " << username << " Successfully cancelled your account..\n";
            Logger::log("Successfully cancelled your account.: " + username);
            return;
        }
    }

    std::cout << "User not found.\n";
}
