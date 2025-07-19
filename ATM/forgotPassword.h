#pragma once
#include <vector>
#include "User.h"

class forgotPassword {
private:
    std::vector<User>& users;  // Reference to users list

public:
    forgotPassword(std::vector<User>& users);  // Constructor declaration

    void forgotPasswordMenu();  // forgot password menu
};
