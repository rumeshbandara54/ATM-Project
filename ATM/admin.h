#pragma once
#include "User.h"
#include <vector>

class Admin {
public:
    Admin(std::vector<User>& users);
    void adminMenu();
    std::vector<User>& users;
  //  std::vector<User>& branchCode;
    void registerUser();
    void showUsers();
    void deleteUser();
};


