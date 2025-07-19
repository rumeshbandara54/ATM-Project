#pragma once
#include <vector>
#include "User.h"
#include "Admin.h"
#include "Branch.h"


class ATM {
private:
    std::vector<User> users;
    User* currentUser = nullptr;

    Branch branchManager;

public:
   
  //  void registerUser();
    //void loginUser();
    //void mainMenu();
    //void loginUser();
    //void deposit();
    //void withdraw();

    //void adminMenu(); // if you keep it inside ATM
    //void forgotPasswordMenu();


    void start();
    void loginUser();
    


};
