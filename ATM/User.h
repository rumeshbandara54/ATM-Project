#pragma once
#include <string>

class User {
public:
    std::string username;
    std::string password;
    std::string email;
    std::string TP;
    std::string branchCode;
    std::string address;
    double balance;

    User(std::string u, std::string p, std::string e, std::string tp, std::string branch, std::string addr, double b = 0.0);
};
