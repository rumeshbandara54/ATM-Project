#pragma once
#include <vector>
#include "User.h"  

class dashboard {
private:
    std::vector<User>& users; //users list
    User* currentUser;     

public:
    // Constructor
    dashboard(std::vector<User>& users, User* currentUser);

    // Main menu
    void mainMenu();

    // Actions ATM Sytem
    void checkBalance();
    void deposit();
    void withdraw();
};
